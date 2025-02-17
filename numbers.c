#include <stdio.h>
#include <stdlib.h>
#include "list.h"

Status completeOperation(List_ptr list, char option)
{
  int value, position;
  Status status;
  switch (option)
  {
  case 'a':
    printf("Enter a number to add to the end of list: \n");
    scanf("%d", &value);
    fflush(stdin);
    return add_to_end(list, value);
    break;

  case 'b':
    printf("Enter a number to add to start of the list: \n");
    scanf("%d", &value);
    fflush(stdin);
    return add_to_start(list, value);
    break;

  case 'c':
    printf("Enter number and position to insert in the list: \n");
    scanf("%d %d", &value, &position);
    fflush(stdin);
    return insert_at(list, value, position);
    break;

  case 'd':
    printf("Enter a unique number to add to end of the list: \n");
    scanf("%d", &value);
    fflush(stdin);
    return add_unique(list, value);
    break;

  case 'e':
    status = remove_from_start(list);
    printf("%s\n", status ? "Number successfully removed from start of the list" : "list is empty");
    return status;
    break;

  case 'f':
    status = remove_from_end(list);
    printf("%s\n", status ? "Number successfully removed from end of the list" : "list is empty");
    return status;
    break;

  case 'g':
    printf("Enter position of number to remove from the list: \n");
    scanf("%d", &position);
    fflush(stdin);
    return remove_at(list, position);
    break;

  case 'h':
    printf("Enter a number to remove its first occurrence from list: \n");
    scanf("%d", &value);
    fflush(stdin);
    status = remove_first_occurrence(list, value);
    printf("%s\n", status ? "Number successfully removed from the list" : "Number not found");
    return status;
    break;

  case 'i':
    printf("Enter a number to remove its all occurrences from list: \n");
    scanf("%d", &value);
    fflush(stdin);
    status = remove_all_occurrences(list, value);
    printf("%s\n", status ? "Number successfully removed from the list" : "Number not found");
    return status;
    break;

  case 'j':
    status = clear_list(list);
    printf("%s\n", status ? "List cleared successfully" : "List was empty");
    return status;
    break;

  case 'l':
    printf("your List is as follows\n");
    display(list);
    break;

  default:
    printf("you have entered wrong option\n");
    Status status = Failure;
    return status;
    break;
  }
}

char take_option(void)
{
  char option;
  printf("Please enter the alphabet of the operation you would like to perform\n");
  scanf("%c", &option);
  fflush(stdin);
  return option;
}

int main(void)
{
  char option;
  List_ptr list = create_list();
  printf("Main Menu\n---------\n(a) add a number to the end of the list\n(b) add a number to the start of the list\n(c) insert a number at a given position in the list\n(d) add a unique item on the list at the end(if it already exists, do not insert)\n(e) remove a number from the beginning of the list\n(f) remove a number from the end of the list\n(g) remove a number from a given position in the list\n(h) remove first occurrence of a number\n(i) remove all occurrences of a number\n(j) clear the whole list\n(k) check if a number exists in the list\n(l) display the list of numbers\n(m) exit\n");
  for (option = take_option(); option != 'm'; option = take_option())
  {
    Status status = completeOperation(list, option);
  }
  return 0;
}