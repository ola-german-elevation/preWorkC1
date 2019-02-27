#include <stdio.h>
#include <stdlib.h>
#include "books.h"

int main(){
  int size_of_items;
  int i;
  int temp_internal = 101;
  Items **ptr_items;
  size_of_items = 5;

  /*printf("How many items do you want to add?\n");
  scanf("%d", &size_of_items);*/

  ptr_items = (Items**) malloc(size_of_items * sizeof(Items*)); /* *ptr_items */

  for (i = 0; i < size_of_items; ++i, ++temp_internal)
  {
    ptr_items[i] = create_item(temp_internal);
  }

  for(i=0; i<size_of_items; ++i)
  {
    print_item(ptr_items[i]);
  }


  return 0;
}



int array_of_items(){
  int size_of_items;
  int i;
  int temp_internal = 101;
  Items *ptr_items;
  size_of_items = 0;

  printf("How many items do you want to add?\n");
  scanf("%d", &size_of_items);

  ptr_items = (Items*) malloc(size_of_items * sizeof(Items)); /* *ptr_items */


  for(i=0; i<size_of_items; ++i)
  {
    init_item(&ptr_items[i] ,temp_internal);
    ++temp_internal;
  }


  for(i=0; i<size_of_items; ++i)
  {
    print_item(&ptr_items[i]);
  }


  return 0;
}
