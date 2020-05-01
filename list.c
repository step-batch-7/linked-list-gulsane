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