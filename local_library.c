#include <stdlib.h>

#include "books.h"
#include "local_library.h"

const Books all_books[] = {
  {"postman", 101, 101, 3},
  {"Color of magic", 102, 30, 2},
  {"Small gods", 103, 30, 2},
  {"Witches abroad", 104, 30, 2},
  {"Witches abroad2", 105, 30, 2},
  {"Witches abroad3", 106, 30, 2},
  {"Witches abroad4", 107, 30, 2},
  {"Witches abroad5", 108, 30, 2},
  {"Witches abroad6", 109, 30, 2},
  {"Fantastic light", 110, 30, 2}
};

int test_local(){
   if (sizeof_books() != 5)
    printf("Error\n");
  printf("%s\n", get_title_by_internal_number(123));
  printf("%s\n", get_title_by_internal_number(423));

  return 0;
}


const Books *ptr_to_first_book(){
  return &all_books[0];
}


int sizeof_books(){
  int res = 0;
  res = sizeof(all_books)/ sizeof(Books);
  return res;
}

const char* get_title_by_internal_number(int internal_number){
  int i;
  int size;
  size = sizeof_books();
  for(i=0; i< size; ++i)
  {
    if (all_books[i].internal_number == (unsigned short) internal_number)
      return all_books[i].title;
  }
  return NULL;
}
