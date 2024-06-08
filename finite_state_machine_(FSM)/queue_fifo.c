#include <stdio.h>
#include <stdint.h>



#include "queue_fifo.h"


//examples: https://www.mikrocontroller.net/articles/FIFO#FIFO_mit_C-Pr%C3%A4prozessor


/**
 * \brief           includes all needed variables
 */
typedef struct {
	uint8_t buffer_size;					/*!< how many element in the buffer*/
	uint8_t buffer_front;					/*!< first element in the buffer*/
	uint8_t buffer_end;					    /*!< last element in the buffer*/
	
} queue_variables;

queue_variables var;




// ----------- Functions -------------------
// -----------------------------------------

/**
 * \brief           initializes all variables and code needed
 */
void init_function(){
	var.buffer_size = 10;
	var.buffer_front = 0; 
    var.buffer_end = 0;
}

/**
 * \brief           calculates how many elements are currently contained in the buffer
 * \return          uint8_t elements contained in buffer
 */
uint8_t elements_in_buffer() {
    if (var.buffer_front > var.buffer_end) {
        return var.buffer_size - var.buffer_front + var.buffer_end;
    }
    else {
        return var.buffer_end - var.buffer_front;
    }
}

/**
 * \brief           takes element and saves it last in queue
 */
void enqueue(uint32_t number) {
    //put element in que

}

/**
 * \brief           returns first element from queue
 * \return          returns first element from queue
 */
uint32_t dequeue(){
    uint32_t last_element;

    //code

    return last_element;
}







// --------------------- MAIN ---------------------------

int main() 
{ 
	// do stuff with a queue

	return 0;	//program ended successfully 
} 