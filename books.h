#ifndef BOOKS_H
#define BOOKS_H

#include <stdio.h>
#include <string.h>
#define MAX_TITLE_LEN 50
#define START_S_NUM 10000


/* masks for bitwise opertaion on book condition */

#define CON_IS_P_COVER 0x1
#define CON_IS_P_INDEX 0x2
#define CON_IS_MISSING_PAGES 0x4
#define CON_IS_BAR_CODE 0x8
#define CON_IS_BAR_SPINE_BROKEN 0x10
#define CON_IS_STAINED_PAGES 0x20




typedef enum {
  KIDS, HIGHSCHOOL, ADULT, DOCUMENTARY, COMICS, FANTASY
} Zones;


/* todo: write down the padding */
typedef struct {
  unsigned long serial_num; /* 0 - 1,000,000 */
  unsigned short internal_number;  /* a number: 0 - 50,000 */
  int is_borrowed; /* 0-false 1-true */
  unsigned int borrowing_times;
  unsigned int condition;
}Items;

/* BOOK */
typedef struct {
  char title[MAX_TITLE_LEN];
  unsigned short internal_number;  /* a number: 0 - 50,000 */
  signed char promotion;   /* a number: (-100) - 100 */
  Zones zone; /* typdef enum */

}Books;

/* Decleretion */
const char* get_zone_name(Zones z);
void print_book(Books *book);
void init_book(Books *book, char* title, int internal_number, signed char promotion, Zones zone);
void print_item(Items *item);
int borrow_item(Items *item, int is_borrowing);
void test_books();
void init_item(Items *item, int internal_number);


int is_librarian_required(Items *item);
int is_bookbinder_required(Items *item);
int is_repairable(Items *item);
int is_ok(Items *item);
int is_useless(Items *item);
int are_in_same_condition(Items *item1, Items *item2);
#endif
