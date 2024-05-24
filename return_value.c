#include <stdio.h>

enum return_value {
  SUCCESS = 0,
  FAILURE,
}; 

enum return_value my_function() {
    printf("Hello, World!\n");
    return 0;  // Indicates that the function ran successfully
}

int main() {
    if (my_function() == SUCCESS) {
        printf("The function ran successfully.\n");
    } else {
        printf("The function encountered an error.\n");
    }
    return 0;
}


// ------------------------------------------
//or is it better like this what is convention

#include <stdio.h>


int my_function() {
    printf("Hello, World!\n");
    return 0;  // Indicates that the function ran successfully
}

int main() {
    if (my_function() == 0) {
        printf("The function ran successfully.\n");
    } else {
        printf("The function encountered an error.\n");
    }
    return 0;
}