#ifndef LOCAL_LIBRARY_H
#define LOCAL_LIBRARY_H

#include "books.h"

const Books *ptr_to_first_book();
int sizeof_books();
const char* get_title_by_internal_number(int internal_number);


#endif
