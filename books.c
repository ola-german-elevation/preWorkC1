#include <stdlib.h>
#include "books.h"


static const char* zones_str[] = {"kids", "highschool", "adult", "documentary", "comic", "fantasy"};
void print_condition(Items *item);

int test_main()
{
  test_books();
  return 0;
}


Items* create_item(int internal_number){
  Items *item;
  item = (Items*) malloc(sizeof(Items));

  if (item)
    init_item(item, internal_number);
  else
    printf("could not allocate ITEM !!!");

  return item;
}


Books* create_book(char* title, int internal_number, signed char promotion, Zones zone){
  Books *book;
  book = (Books*) malloc(sizeof(Books));

  if (book)
    init_book(book, title, internal_number, promotion, zone);
  return 0;
}


void free_item(Items *item)
{
  free(item);
}


void free_book(Books *book)
{
  free(book);
}


const char* get_zone_name(Zones z)
{
  return zones_str[z];
}


void init_book(Books *book, char* title, int internal_number, signed char promotion, Zones zone){
  strcpy(book->title, title);
  book->internal_number = (unsigned short) internal_number;
  book->promotion = promotion;
  book->zone = zone;
}

void print_book(Books *book)
{
  printf("\n\nBOOK SUMMERY\n-------------\n");
  printf("%s\n", book->title);
  printf("zone: %s\n", get_zone_name(book->zone));
  printf("internal num: %d\n", (int) book->internal_number);
}


void print_item(Items *item){
  if (!item)
  {
    printf("could not print an empty item\n");
    return;
  }
  printf("\n-------------\n");
  printf("internal num: %d\n", (int) item->internal_number);
  /* printf("Title: %s\n", get_title_by_internal_number(item->internal_number)); */
  printf("serial number: %d\n", (int) item->serial_num);
  if (item->is_borrowed)
    printf("Borrowed !!!\n");
  else
    printf("free to take\n");

  printf("problems with a book:\n");
  print_condition(item);

}


/* printing all the problems with an item */
void print_condition(Items *item)
{

  if(item->condition & CON_IS_P_COVER)
    printf("problem in its cover\n");

  if(item->condition & CON_IS_P_INDEX)
    printf("problem in its index\n");

  if(item->condition & CON_IS_MISSING_PAGES)
    printf("there are missing pages\n");

  if(item->condition & CON_IS_BAR_CODE)
    printf("problem in its bar code\n");

  if(item->condition & CON_IS_BAR_SPINE_BROKEN)
    printf("bar spine broken\n");

  if(item->condition & CON_IS_STAINED_PAGES)
    printf("there is staines pages\n");
}

/* borrow/ unborrow item
   return 0 if error accures */
int borrow_item(Items *item, int is_borrowing)
{

  int ans = item->is_borrowed ^ is_borrowing;
  if (ans)
  {
    item->is_borrowed = !item->is_borrowed;
    ++(item->borrowing_times);
  }
  return ans;
}


void init_item(Items *item, int internal_number)
{
  static long serial_num = START_S_NUM;
  item->internal_number = (unsigned short) internal_number;
  item->serial_num = (unsigned long) serial_num;
  item->is_borrowed = 0;
  item->borrowing_times = 0;
  item->condition = 0;
  ++serial_num;
}

void test_books()
{

    Books book1, book2;
    Items item1, item2;
    init_item(&item1, 123);
    init_item(&item2, 223);

    init_book(&book2, "hello", 123, 40, 3);
    init_book(&book1, "Veronica decides to die", 223, 30, 2);
    print_book(&book1); /* what do i pass here? a pointer? this way is an address*/
    print_book(&book2);
    print_item(&item1);
    if (borrow_item(&item1, 1)) /* borrow */
      print_item(&item1);
    else
      printf("********* error occured\n");
    borrow_item(&item1, 0); /* unborrow */
    print_item(&item1);

    /* expect error */
    if (borrow_item(&item1, 0)) /* borrow */
      print_item(&item1);
    else
      printf("Expect error: ********* error accure\n");

    print_item(&item1);
    print_item(&item2);

}


/* condition of the book methods */
int is_librarian_required(Items *item)
{
  if ((item->condition & CON_IS_P_COVER) ||
      (item->condition & CON_IS_P_INDEX) ||
      (item->condition & CON_IS_BAR_CODE))
      return 1;
  return 0;
}


int is_bookbinder_required(Items *item)
{
  if ((item->condition & CON_IS_BAR_SPINE_BROKEN) ||
      (item->condition & CON_IS_MISSING_PAGES) ||
      (item->condition & CON_IS_STAINED_PAGES))
      return 1;
  return 0;
}

/* todo: TEST this function */
int is_repairable(Items *item)
{
  if ((item->condition & CON_IS_STAINED_PAGES) ||
      (item->condition & CON_IS_MISSING_PAGES))
      return 0;
  return 1;
}


int is_ok(Items *item)
{
  if (item->condition == 0)
    return 1;
  return 0;
}


int is_useless(Items *item)
{
  unsigned int num;
  int bit;
  int issues;

  issues = 0;
  num = item->condition;

  for (bit=0; bit<(sizeof(unsigned int) * 8); ++bit)
  {
    issues += num & 0x01;
    /* printf("%i ", num & 0x01); */
    num = num >> 1;
  }
  if (issues >= 4)
    return 1;
  return 0;
}

/* todo: TEST this function */

int are_in_same_condition(Items *item1, Items *item2){
  if ((item1->condition == item2->condition))
    return 1;
  return 0;
}
