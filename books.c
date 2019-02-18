#include "books.h"

const char* zones_str[] = {"kids", "highschool", "adult", "documentary", "comic"};

int test_main()
{
  test_books();
  return 0;
}


const char* get_zone_name(Zones z){
  return zones_str[z];
}

void init_book(Books *book, char* title, unsigned short internal_number, signed char promotion, Zones zone){
  strcpy(book->title, title);
  book->internal_number = internal_number;
  book->promotion = promotion;
  book->zone = zone;
}

void print_book(Books *book){
  printf("\n\nBOOK SUMMERY\n-------------\n");
  printf("%s\n", book->title);
  printf("zone: %s\n", get_zone_name(book->zone));
  printf("internal num: %d\n", book->internal_number);
}


void print_item(Items *item){
  printf("\n\nITEM SUMMERY\n-------------\n");
  printf("internal num: %d\n",item->internal_number);
  printf("serial number: %d\n", item->serial_num);
  if (item->is_borrowed)
    printf("Borrowed !!!\n");
  else
    printf("free to take\n");
}
/* borrow/ unborrow item
   return 0 if error accures */
int borrow_item(Items *item, int is_borrowing){
  int ans = 1;
  if (is_borrowing) /* borrow item */
  {
    if (item->is_borrowed)
      ans = 0; /* the book is allready borrowed, u cant borrow it now */
    else
      item->is_borrowed = 1;
  }
  else /* unborrow item */
  {
    if (item->is_borrowed)
      item->is_borrowed = 0;
    else
      ans = 0;
  }

  return ans;
}

void init_item(Items *item, int internal_number){
  static long serial_num = 10000;
  item->internal_number = internal_number;
  item->serial_num = serial_num;
  item->is_borrowed = 0;
  ++serial_num;
}

void test_books(){

    Books book1, book2;
    Items item1, item2;
    init_item(&item1, 123);
    init_item(&item2, 223);

    init_book(&book2, "hello", 123, 40, 3);
    init_book(&book1, "Veronica decide to die", 223, 30, 2);
    print_book(&book1); /* what do i pass here? a pointer? this way is an address*/
    print_book(&book2);
    print_item(&item1);
    if (borrow_item(&item1, 1)) /* borrow */
      print_item(&item1);
    else
      printf("********* error accure\n");
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
