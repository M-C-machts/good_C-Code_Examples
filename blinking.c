#include <stdio.h> 
#include <stdint.h>
#include <unistd.h>

#include "blinking.h"

typedef void (*fsm_state)(void);
typedef struct {
	fsm_state state;
} fsm_t;

fsm_t fsm;

/*
typedef void (*fsm_state)(void);
fsm_state fsm;
*/

//uint32_t counter = 0;
int counter = 0;


void state_led_on(void) {
	printf("\n run: %i", counter);

	if (counter++ < 5) {
		fsm.state = state_led_off;
	}
	else {
		fsm.state = state_end_program;
	}

}

void state_led_off(void) {
	printf("\n off");

	fsm.state = state_led_on;
}

void state_end_program(void) {
	printf("\n Ending the program.");
	exit(0);
}


int main() 
{ 

	fsm.state = state_led_off;

	while(1) {
		usleep(500 * 1000);  // usleep takes sleep time in microseconds
		fsm.state();
	}


	return 0;
} 

