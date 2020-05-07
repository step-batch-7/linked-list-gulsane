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

Status add_unique(List_ptr list, int value)
{
  Node_ptr p_walker = list->head;
  while (p_walker != NULL)
  {
    if (p_walker->value == value)
    {
      return Failure;
    }
    p_walker = p_walker->next;
  }
  return add_to_end(list, value);
}

Status remove_at(List_ptr list, int position)
{
  if (position >= list->count || position < 0)
  {
    return Failure;
  }
  Prev_Current_Pair pre_current_pair;
  pre_current_pair.prev = NULL;
  pre_current_pair.current = list->head;
  while (position > 0)
  {
    pre_current_pair.prev = pre_current_pair.current;
    pre_current_pair.current = pre_current_pair.current->next;
    position--;
  }
  Node_ptr node_to_remove = pre_current_pair.current;
  Node_ptr *ptr_to_set = &list->head;
  if (pre_current_pair.prev != NULL)
  {
    ptr_to_set = &pre_current_pair.prev->next;
  }
  *ptr_to_set = pre_current_pair.current->next;
  if (pre_current_pair.current->next == NULL)
  {
    list->last = pre_current_pair.prev;
  }
  list->count--;
  free(node_to_remove);
  return Success;
}

Status remove_from_start(List_ptr list)
{
  return remove_at(list, 0);
}

Status remove_from_end(List_ptr list)
{
  return remove_at(list, list->count - 1);
}

Status remove_first_occurrence(List_ptr list, int value)
{
  Node_ptr p_walker = list->head;
  for (size_t i = 0; i < list->count; i++)
  {
    if (p_walker->value == value)
    {
      return remove_at(list, i);
    }
    p_walker = p_walker->next;
  }
  return Failure;
}

Status is_number_in_list(List_ptr list, int value)
{
  Node_ptr p_walker = list->head;
  while (p_walker != NULL)
  {
    if (p_walker->value == value)
    {
      return Success;
    }
    p_walker = p_walker->next;
  }
  return Failure;
}

Status remove_all_occurrences(List_ptr list, int value)
{
  Status status;

  while (is_number_in_list(list, value))
  {
    status = remove_first_occurrence(list, value);
  }

  return status;
}