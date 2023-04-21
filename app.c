#include "contiki.h"
#include <stdio.h>
#include "dev/button-sensor.h"
#include "dev/leds.h"
#include "node-id.h"
#include "net/rime.h"

PROCESS(app_process,"App");
AUTOSTART_PROCESSES(&app_process);

static uint8_t counterOne, counterTwo;

static void broadcast_recv(struct broadcast_conn *c, const rimeaddr_t *from)
{
	counterTwo += 1;
	printf("Button pressed on node %d.%d: '%s' - %d messages received in total.\n", from->u8[0], from->u8[1], (char *)packetbuf_dataptr(), counterTwo);
	leds_toggle(LEDS_GREEN);
	leds_toggle(LEDS_BLUE);
}
static const struct broadcast_callbacks broadcast_call = {broadcast_recv};
static struct broadcast_conn broadcast;

PROCESS_THREAD(app_process,ev,data) 
{
	static struct etimer et;
	SENSORS_ACTIVATE(button_sensor);
	PROCESS_EXITHANDLER(broadcast_close(&broadcast);)

	PROCESS_BEGIN();
	counterOne = 0;
	counterTwo = 0;
	broadcast_open(&broadcast, 129, &broadcast_call);
		
	while(1) {

		PROCESS_WAIT_EVENT_UNTIL(ev==sensors_event && data==&button_sensor);
			counterOne += 1;
			printf("Node %d: my button was pressed - it has been pressed %d times in total.\n", node_id, counterOne);
			packetbuf_copyfrom("Button pressed.", 16);
			broadcast_send(&broadcast);
			leds_on(LEDS_RED);
			etimer_set(&et, CLOCK_SECOND*5);

		PROCESS_WAIT_EVENT_UNTIL(etimer_expired(&et));	
			leds_off(LEDS_RED);
			etimer_reset(&et);

	}
	PROCESS_END();

}