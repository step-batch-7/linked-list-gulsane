#include <stdio.h>
#include <stdlib.h>
#include "./list.h"

Node_ptr create_node(int value)
{
  Node_ptr new_node = (Node_ptr)malloc(sizeof(Node));
  new_node->value = value;
  new_node->next = NULL;
  return new_node;
}

List_ptr create_list(void)
{
  List_ptr list = (List_ptr)malloc(sizeof(List));
  list->head = NULL;
  list->last = NULL;
  list->count = 0;
  return list;
}

Status add_to_end(List_ptr list, int value)
{
  Node_ptr new_node = create_node(value);
  if (list->head == NULL)
  {
    list->head = new_node;
  }
  else
  {
    list->last->next = new_node;
  }
  list->last = new_node;
  list->count++;
  Status status = Success;
  return status;
}

void display(List_ptr list)
{
  Node_ptr walk_on = list->head;
  while (walk_on != NULL)
  {
    printf("%d\n", walk_on->value);
    walk_on = walk_on->next;
  }
}

Status add_to_start(List_ptr list, int value)
{
  Node_ptr new_node = create_node(value);
  Node_ptr second_node = list->head;
  list->head = new_node;
  if (list->last == NULL)
  {
    list->last = new_node;
  }
  list->head->next = second_node;
  list->count++;
  Status status = Success;
  return status;
}

Status insert_at(List_ptr list, int value, int position)
{
  Status status;
  if (position < 0 || position > list->count)
  {
    status = Failure;
    return status;
  }
  Node_ptr new_node = create_node(value);
  Prev_Current_Pair prev_current_pair;
  prev_current_pair.current = list->head;
  prev_current_pair.prev = NULL;

  while (position != 0)
  {
    prev_current_pair.prev = prev_current_pair.current;
    prev_current_pair.current = prev_current_pair.current->next;
    position--;
  }

  if (prev_current_pair.prev == NULL)
  {
    return add_to_start(list, value);
  }

  prev_current_pair.prev->next = new_node;
  new_node->next = prev_current_pair.current;
  list->count++;
  status = Success;
  return status;
}