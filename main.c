#include "backend/backend.h"
#include "common.h"
#include "frontend/frontend.h"

int main() {
  inputBuffer *new_input_buffer = init_inputBuffer();
  
  while (true) {
    printf("db >");
    read_input(new_input_buffer); //Read Input from User

    if (isMetaCommand(new_input_buffer)) {
      if (isExit(new_input_buffer)) {
        exit(EXIT_SUCCESS);
      } else {
        printf("unrecognized meta command '%s'.\n", new_input_buffer->input);
      }
    } else {
      printf("unrecognized command '%s'.\n", new_input_buffer->input);
    }
  }

  return 0;
}
