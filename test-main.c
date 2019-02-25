#include <stdio.h>
#include <stdlib.h>
#include "books.h"

int main(){
  int size_of_items;
  int i;
  int temp_internal = 101;
  Items *ptr_items;  /* **ptr_items ?ask? do i need to protect my first pointer?*/
  /* cuz i dont want him to change, const? */
  Items *temp_ptr_item;

  size_of_items = 0;
  printf("How many items do you want to add?\n");
  scanf("%d", &size_of_items);

  ptr_items = (Items*) malloc(size_of_items * sizeof(Items)); /* *ptr_items */

  temp_ptr_item = ptr_items;

  for(i=0; i<size_of_items; ++i)
  {
    init_item(temp_ptr_item ,temp_internal);
    ++temp_internal;
    ++temp_ptr_item;
  }

  temp_ptr_item = ptr_items;

  for(i=0; i<size_of_items; ++i)
  {
    print_item(temp_ptr_item);
    ++temp_ptr_item;
  }


  return 0;
}
