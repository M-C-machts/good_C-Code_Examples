#include <stdio.h>
#include <stdint.h>



#include "queue_fifo.h"


//examples: https://www.mikrocontroller.net/articles/FIFO#FIFO_mit_C-Pr%C3%A4prozessor


/**
 * \brief           includes all needed variables
 */
typedef struct {
	uint8_t size;					/*!< how many element in the buffer*/
	uint8_t write_index;					/*!< first element in the buffer*/
	uint8_t read_index;					    /*!< last element in the buffer*/
	
} buffer_variables;

buffer_variables buffer;




// ----------- Functions -------------------
// -----------------------------------------

/**
 * \brief           initializes all variables and code needed
 */
void init_function(){
	buffer.size = 10;       // 0 to 9
	buffer.write_index = 0; 
    buffer.read_index = 0;
}

/**
 * \brief           calculates how many elements are currently contained in the buffer
 * \return          uint8_t elements contained in buffer
 */
uint8_t elements_in_buffer() {
    if (buffer.write_index > buffer.read_index) {
        return buffer.write_index - buffer.read_index;
    }
    else {
        return buffer.size - buffer.write_index + buffer.read_index;
    }
}

/**
 * \brief           takes element and saves it to the queue
 */
void write_to_buffer(uint32_t number) {
    //put element in que

}

/**
 * \brief           returns first element from queue
 * \return          returns first element from queue
 */
uint32_t get_buffer_element(){
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
