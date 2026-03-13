#ifndef FRONTEND_H
#define FRONTEND_H

#include "../common.h"

typedef enum {
  PREPARE_SUCCESS,
  PREPARE_UNRECOGNIZED_STATEMENT
} PrepareResult;

// Types of statements our VM understands
typedef enum {
  STATEMENT_INSERT,
  STATEMENT_SELECT
} StatementType;

#define true 1
#define false 0

void read_input(inputBuffer *new_input_field); /* Function to Read Input*/

#endif // !FRONTEND_H
