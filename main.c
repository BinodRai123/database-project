#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct {
  char* input_text;
  int input_length;
} input_field;

input_field* init_input_field(){
  input_field* inputField = malloc(sizeof(input_field));
  inputField->input_text = NULL;
  inputField->input_length = 0;

  return inputField;
}

void read_input(input_field* new_input_field){
  if(new_input_field->input_text == NULL){ //if the input text is empty
    new_input_field->input_length = 200;  //then length be 200
    new_input_field->input_text = malloc(sizeof(new_input_field->input_length)); //allocate memory size in ram
  }

  //store exactly 1024 char 
  scanf("%200[^\n]", new_input_field->input_text);
  
  //removing the \n from the scanf
  getchar();
}

int main(){
  input_field* new_input_field = init_input_field();
  while(true){
    printf("db> ");
    read_input(new_input_field);

    if(strcmp(".exit", new_input_field->input_text) == 0){
      free(new_input_field->input_text); //freeing the make input_text
      free(new_input_field); //freeing the input field
      exit(EXIT_SUCCESS);
    }else{
      printf("unrecognized command '%s'.\n", new_input_field->input_text);
    }
  }

  return 0;

}