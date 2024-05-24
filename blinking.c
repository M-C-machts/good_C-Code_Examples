#include <stdio.h> 
#include <stdint.h>
#include <unistd.h>

#include <time.h>

#include "blinking.h"

typedef void (*fsm_state)(void);
typedef struct {
	fsm_state state;
} fsm_t;

fsm_t fsm;										/*!< current state of state machine */


/**
 * \brief           includes all needed variables
 */
typedef struct {
	uint32_t counter;							/*!< how often the led has blinked before*/
	uint32_t count_to;							/*!< how often the led has should blink over all*/

    //fsm_t fsm;								/*!< current state of state machine */

} led_variables;

led_variables var;



/*
typedef void (*fsm_state)(void);
fsm_state fsm;
*/



// ----------- Functions -------------------
// -----------------------------------------

/**
 * \brief           initializes all variables and code needed
 */
void init_function(){
	var.counter = 0;
	var.count_to = 5; //find naming convention maybe counter_end but cout_to seems better
}

/**
 * \brief           all code needed to turn on a LED
 * \return          returns 0 if successful, 1 on failure
 */
void turn_on_led(){
	printf("\n LED ON");

	// + code needed to turn on a led
}

/**
 * \brief           all code needed to turn off a LED
 * \return          returns 0 if successful, 1 on failure
 */
void turn_off_led(){
	printf("\n LED OFF");

	// + code needed to turn off a led
}




// ----------- fsm STATES ------------------
// -----------------------------------------

/**
 * \brief           start_time point of state machine
 */
void state_start_time(void) {
	init_function();

	fsm.state = state_led_on;
}

/**
 * \brief           turns on the led and checks if runs succeed number of needed runs
 */
void state_led_on(void) {
	printf("\n\n run: %i", var.counter);	
	turn_on_led();


	if (var.counter < (var.count_to - 1)) {
		var.counter++;
		fsm.state = state_led_off;
	}
	else {
		fsm.state = state_end_program;
	}
}

/**
 * \brief           turns off the led
 */
void state_led_off(void) {
	turn_off_led();

	fsm.state = state_led_on;
}

/**
 * \brief           turns off the led, and ends program
 */
void state_end_program(void) {
	turn_off_led();
	printf("\n Ending the program.");
	exit(0);
}




// --------------------- MAIN ---------------------------

int main() 
{ 
	fsm.state = state_start_time;


	/*
	// while function with delay
	while(1) {
		usleep(500 * 1000);  					// usleep takes sleep time in microseconds
		fsm.state();							//runs current state of state machine
	}
	*/


	time_t start_time;
	start_time = time(NULL);

	// while function that doesn't block code with sleep function
	while(1) {									
		if (difftime(time(NULL), start_time) > 0.5) {	
			fsm.state();					//runs current state of state machine
			start_time = time(NULL);
		}
		usleep(1 * 1000);  					// 1 microsecond delay so is will not block one CPU core (delay not needed in embedded)


		//----
		//other code that is not blocked by sleep function
		//----

	}

	return 0;	//program ended successfully 
} 

