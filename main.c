#include "local_library.h"
#include "books.h"
#define ITEM_SIZE 3

Items items[ITEM_SIZE];

void add_items();
void scan_internal_number_from_user();

void do_actions_on_items();
Items* get_item_by_serial_number(int s_num);

int change_item_state_borrowing(int is_borrowing);
int scan_serial_num();
void print_all_items();
void print_borrow_menu();



int main()
{
  add_items();
  do_actions_on_items();
  print_all_items();

  return 0;
}


void print_all_items()
{
  int i;
  for (i = 0; i < ITEM_SIZE; ++i)
    print_item(&items[i]);
}



void add_items()
{
  int i;
  printf("Add %d items, u need to enter internal_number numbers (0-50,000)\n",  ITEM_SIZE );

  for (i=0; i< ITEM_SIZE; ++i)
    scan_internal_number_from_user(i);
}

/*and init item */
void scan_internal_number_from_user(int item_index)
{
  int internal_number = 0;
  while(1)
  {
    printf("Enter Internal Number: \n");
    fflush(stdout);

    scanf("%d\n", &internal_number);

    if (get_title_by_internal_number(internal_number))
    {
      init_item(&items[item_index], internal_number);
      return;
    }
    printf("there is no internal number.\npls try again!\n");
  }
}


void do_actions_on_items()
{
  int choice =0;
  int ans;
  while(choice != 9)
  {
  print_borrow_menu();
  fflush(stdout);
  scanf("%d\n", &choice);

    switch(choice)
    {
       case 1 : /* borrow */
          ans = change_item_state_borrowing(1);
          if (!ans)
            printf("Attention! The Item is allready BORROWED !!!\n");
          else
            printf("option completed\n");
          break;
       case 2 : /* unborrow */
          ans = change_item_state_borrowing(0);
          if (!ans)
            printf("Attention! The Item is NOT BORROWED !!!\n");
          else
            printf("option completed\n");
          break;
        case 3:
          print_all_items();
          break;
       case 9 : /*exit */
          printf("Goodbye\n");
          break;
       default :
          printf("Invalid choice, pls try again.\n");

    }
  }
}


int change_item_state_borrowing(int is_borrowing){
  Items *item;

  int serial_num = 0;
  int ans = 0;

  serial_num = scan_serial_num();

  if (serial_num<0)
  {
    printf("serial number is gone wrong\n");
    return ans;
  }
  item = get_item_by_serial_number(serial_num); /* could it be done in one line? */
  ans = borrow_item(item, is_borrowing);
  return ans;
}


Items* get_item_by_serial_number(int s_num)
{
  return &items[s_num - START_S_NUM];
}


int scan_serial_num()
{
  int s_num = 0;
  while(1)
  {
    printf("choose a serial number\n");
    fflush(stdout);
    
    scanf("%d\n", &s_num);

    /*test if choice valid */

    if ((s_num < (START_S_NUM + ITEM_SIZE)) && (s_num >= START_S_NUM))
      return s_num;
    else
      printf("the serial number is wrong\n");
  }
return -1;
}


void print_borrow_menu()
{
  printf("\n-------------\nchoose an option:\n");
  printf("1- borrow\n");
  printf("2- unborrow\n");
  printf("3- print all items\n");

  printf("9- exit\n");
}
