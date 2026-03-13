#include "frontend.h"

// Function to read Input from User

void read_input(inputBuffer *new_input_buffer) {
  if (new_input_buffer->input == NULL) { // if the input text is empty
    AllocateInputBuffer(new_input_buffer, 100); //create new space for input field to store
  }

  //Read entire line from keyboard and return the count
  size_t bytes_count = getline(&new_input_buffer->input,
                               &(new_input_buffer->buffer_length), stdin);
  if (bytes_count <= 0) {
    setError("Error while reading Input \n");
  } else {
    //It Remove \n from the end of input like insert\n 
    new_input_buffer->input_length = bytes_count - 1;
    new_input_buffer->input[bytes_count - 1] = 0; 
  }
}
