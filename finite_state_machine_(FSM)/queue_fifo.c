#include <stdio.h>
#include <stdint.h>



//#include "queue_fifo.h"


//examples: https://www.mikrocontroller.net/articles/FIFO#FIFO_mit_C-Pr%C3%A4prozessor


/**
 * \brief           includes all needed variables
 */
typedef struct {
	uint8_t buffer[10];						/*!< this is the buffer*/
	uint8_t size;					        /*!< how many element in the buffer*/
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
	//buffer.buffer[10] = {0};			//set all 10 elements to 0 
	for (int i=0; i<5; i++) {
		buffer.buffer[i] = 0;
	}


	buffer.size = 10;       	// 0 to 9
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
 * \brief           takes element and saves it to the queue except if buffer is full
 */
void write_to_buffer(uint32_t number) {
	if (elements_in_buffer() < buffer.size ) {
		buffer.buffer[buffer.write_index] = number;

		//check if buffer write_index in on last position. than set to next position
		if (buffer.write_index == (buffer.size - 1)) {
			buffer.write_index = 0;
		}
		else {
			buffer.write_index++;
		}
	}

}


/**
 * \brief           returns first element from buffer
 * \return          returns first element from buffer
 */
uint32_t read_from_buffer() {

	if (elements_in_buffer() > 0) {
		uint32_t temp_var = 0;
		temp_var =  buffer.buffer[buffer.read_index];

		//check if buffer read_index in on last position. than set to next position
		if (buffer.read_index == (buffer.size - 1)) {
			buffer.read_index = 0;
		}
		else {
			buffer.read_index++;
		}

		return temp_var;

	}

	return 0; 	//TODO think of a way to return something if  buffer is empty for now check if buffer is not empty befor executing function.

}







// --------------------- MAIN ---------------------------

int main() 
{ 
	for (int i=0; i<10; i++) {
		write_to_buffer(i);

        printf("\nread_index: %u, write_index: %u\n", buffer.read_index, buffer.write_index);
		printf("%u, %u, %u, %u, %u, %u, %u, %u, %u, %u \n", buffer.buffer[0], buffer.buffer[1], buffer.buffer[2], buffer.buffer[3], buffer.buffer[4], buffer.buffer[5], buffer.buffer[6], buffer.buffer[7], buffer.buffer[8], buffer.buffer[9]);
        
		//for (int j=0; j<10; j++) {
		//	printf("%u, ", buffer.buffer[j]);	//print buffer
		//	printf("\n");
		//}
		

	}

	return 0;	//program ended successfully 
} 
