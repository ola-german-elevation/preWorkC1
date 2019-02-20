#ifndef BOOKS_H
#define BOOKS_H

#include <stdio.h>
#include <string.h>
#define MAX_TITLE_LEN 50
#define START_S_NUM 10000

typedef enum {
  KIDS, HIGHSCHOOL, ADULT, DOCUMENTARY, COMICS, FANTASY
} Zones;


/* todo: write down the padding */
typedef struct {
  long serial_num; /* 0 - 1,000,000 */
  int internal_number;  /* a number: 0 - 50,000 */
  int is_borrowed; /* 0-false 1-true */
}Items;

/* BOOK */
typedef struct {
  char title[MAX_TITLE_LEN];
  int internal_number;  /* a number: 0 - 50,000 */
  signed char promotion;   /* a number: (-100) - 100 */
  Zones zone; /* typdef enum */
}Books;

/* Decleretion */
const char* get_zone_name(Zones z);
void print_book(Books *book);
void init_book(Books *book, char* title, unsigned short internal_number, signed char promotion, Zones zone);
void print_item(Items *item);
int borrow_item(Items *item, int is_borrowing);
void test_books();
void init_item(Items *item, int internal_number);

#endif
