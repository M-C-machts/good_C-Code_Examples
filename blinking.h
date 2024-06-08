#ifndef BLINKING_H
#define BLINKING_H



#include <stdio.h> 
#include <stdint.h>
#include <unistd.h>


#ifdef __cplusplus
extern "C" {
#endif /* __cplusplus */




void state_start(void);
void state_led_on(void);
void state_led_off(void);
void state_end_program(void);



#ifdef __cplusplus
}
#endif /* __cplusplus */

#endif /* BLINKING_H */
