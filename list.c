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
