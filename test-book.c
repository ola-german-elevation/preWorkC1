#include "books.h"

void test_books_bitwise();


int main() {
  test_books_bitwise();
  return 0;
}


void test_books_bitwise()
{

    Books book1, book2;
    Items item1, item2;
    init_item(&item1, 123);
    init_item(&item2, 223);

    init_book(&book2, "hello", 123, 40, 3);
    init_book(&book1, "Veronica decide to die", 223, 30, 2);
    print_book(&book1); /* what do i pass here? a pointer? this way is an address*/
    print_book(&book2);
    print_item(&item1);
    item1.condition = 11;
    printf("condition: %d\n", item1.condition);
    if (is_librarian_required(&item1))
    {
      printf("librarian is required - OK\n");
    }
    /* is_librarian_required */
    item1.condition = 1;
    printf("condition: %d\n", item1.condition);
    if (is_librarian_required(&item1))
    {
      printf("librarian is required - OK\n");
    }

    item1.condition = 10;
    printf("condition: %d\n", item1.condition);
    if (is_librarian_required(&item1))
    {
      printf("librarian is required - OK\n");
    }

    item1.condition = 4;
    printf("condition: %d\n", item1.condition);
    if (~is_librarian_required(&item1))
    {
      printf("librarian is NOT required - OK\n");
    }


    item1.condition = 36;  /* 100100 :b */
    printf("condition: %d\n", item1.condition);
    if (is_bookbinder_required(&item1))
    {
      printf("bookbinder is  required - OK\n");
    }

    item1.condition = 32;  /* 100100 :b */
    printf("condition: %d\n", item1.condition);
    if (is_bookbinder_required(&item1))
    {
      printf("bookbinder is required - OK\n");
    }


    item1.condition = 11;  /* 100100 :b */
    printf("condition: %d\n", item1.condition);
    if (~is_bookbinder_required(&item1))
    {
      printf("bookbinder is NOT required - OK\n");
    }


    item1.condition = 0;
    printf("condition: %d\n", item1.condition);
    if (is_ok(&item1))
    {
      printf(" is OK - OK\n");
    }

    item1.condition = 43; /* 4 issues */
    printf("condition: %d\n", item1.condition);
    if (is_useless(&item1))
    {
      printf("Useless - OK\n");
    }

    item1.condition = 31; /* 5 issues */
    printf("condition: %d\n", item1.condition);
    if (is_useless(&item1))
    {
      printf("Useless - OK\n");
    }

    item1.condition = 5; /* 2 issues */
    printf("condition: %d\n", item1.condition);
    if (~is_useless(&item1))
    {
      printf("NOT Useless - OK\n");
    }

  }
