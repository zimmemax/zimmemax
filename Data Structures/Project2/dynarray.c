/*
 * This file contains a simple implementation of a dynamic array.  See the
 * documentation below for more information on the individual functions in
 * this implementation.
 */

#include <stdlib.h>
#include <assert.h>

#include "dynarray.h"

/*
 * This structure is used to represent a single dynamic array.
 */
struct dynarray {
  void** data;
  int size;
  int capacity;
  int start;
  int front;
  int rear;
  int logical;
  int physical;
};

int get_size(struct dynarray* da)
{
  return da->size;
}
int get_capacity(struct dynarray* da)
{
  return da->capacity;
}
int get_front(struct dynarray* da)
{
  return da->front;
}
int get_rear(struct dynarray* da)
{
  return da->rear;
}
void set_size(struct dynarray* da, int size)
{
  da->size = size;
}
void set_capacity(struct dynarray* da, int capacity)
{
  da->capacity = capacity;
}
void set_front(struct dynarray* da, int front)
{
  da->front = front;
}
void set_rear(struct dynarray* da, int rear)
{
  da->rear = rear;
}

#define DYNARRAY_INIT_CAPACITY 4

/*
 * This function allocates and initializes a new, empty dynamic array and
 * returns a pointer to it.
 */
struct dynarray* dynarray_create() {
  struct dynarray* da = malloc(sizeof(struct dynarray));
  assert(da);

  da->data = malloc(4 * sizeof(void*));
  assert(da->data);
  da->size = 0;
  da->capacity = 4;
  da->rear = 0;
  da->front = 0;
  da->size = 0;
  da->logical = 0;
  da->physical = 0;

  return da;
}

/*
 * This function frees the memory associated with a dynamic array.  Freeing
 * any memory associated with values stored in the array is the responsibility
 * of the caller.
 *
 * Params:
 *   da - the dynamic array to be destroyed.  May not be NULL.
 */
void dynarray_free(struct dynarray* da) {
  assert(da);
  free(da->data);
  free(da);
}

/*
 * This function returns the size of a given dynamic array (i.e. the number of
 * elements stored in it, not the capacity).
 */
int dynarray_size(struct dynarray* da) {
  assert(da);
  return da->size;
}


/*
 * Auxilliary function to perform a resize on a dynamic array's underlying
 * storage array.
 */
void _dynarray_resize(struct dynarray* da, int new_capacity) {
  assert(new_capacity > da->size);

  /*
   * Allocate space for the new array.
   */
  void** new_data = malloc(new_capacity * sizeof(void*));
  assert(new_data);

  /*
   * Copy data from the old array to the new one.
   */

 int counter = 0;
 for(int i = 0; i < da->capacity; i++)
 {
   //printf("in resize:%d\n", *b);
   new_data[i] = da->data[i];
 }
  //printf("in resize\n");
  da->front = 0;


  /*
   * Put the new array into the dynarray struct.
   */
  free(da->data);
  da->data = new_data;
  da->capacity = new_capacity;
}

/*
 * This function inserts a new value to a given dynamic array.  The new element
 * is always inserted at the *end* of the array.
 *
 * Params:
 *   da - the dynamic array into which to insert an element.  May not be NULL.
 *   val - the value to be inserted.  Note that this parameter has type void*,
 *     which means that a pointer of any type can be passed.
 */
void dynarray_insert(struct dynarray* da, void* val) {
  assert(da);

  /*
   * Make sure we have enough space for the new element.  Resize if needed.
   */

  if (da->size == da->capacity) {
    _dynarray_resize(da, 2 * da->capacity);
  }

  /*
   * Put the new element at the end of the array.
   */
  da->data[da->size] = val;
  da->size++;
}

/*
 * This function removes an element at a specified index from a dynamic array.
 * All existing elements following the specified index are moved forward to
 * fill in the gap left by the removed element.
 *
 * Params:
 *   da - the dynamic array from which to remove an element.  May not be NULL.
 *   idx - the index of the element to be removed.  The value of `idx` must be
 *     between 0 (inclusive) and n (exclusive), where n is the number of
 *     elements stored in the array.
 */
void dynarray_remove(struct dynarray* da, int idx) {
  assert(da);
  assert(idx < da->capacity && idx >= 0);

  /*
   * Move all elements behind the one being removed forward one index,
   * overwriting the element to be removed in the process.
   */
  for (int i = idx; i < da->size; i++) {
    da->data[i] = da->data[i+1];
  }

  da->size--;
}

/*
 * This function returns the value of an existing element in a dynamic array.
 *
 * Params:
 *   da - the dynamic array from which to get a value.  May not be NULL.
 *   idx - the index of the element whose value should be returned.  The value
 *     of `idx` must be between 0 (inclusive) and n (exclusive), where n is the
 *     number of elements stored in the array.
 */
void* dynarray_get(struct dynarray* da, int idx) {
  assert(da);
  assert(idx < da->capacity && idx >= 0);

  return da->data[idx];
}

/*
 * This function updates (i.e. overwrites) the value of an existing element in
 * a dynamic array.
 *
 * Params:
 *   da - the dynamic array in which to set a value.  May not be NULL.
 *   idx - the index of the element whose value should be updated.  The value
 *     of `idx` must be between 0 (inclusive) and n (exclusive), where n is the
 *     number of elements stored in the array.
 *   val - the new value to be set.  Note that this parameter has type void*,
 *     which means that a pointer of any type can be passed.
 */
void dynarray_set(struct dynarray* da, int idx, void* val) {
  assert(da);
  assert(idx < da->capacity && idx >= 0);

  da->data[idx] = val;
}


void da_enqueue(struct dynarray* da, void* val)
{
  
  
  if(da->size >= da->capacity - 1)
  {
    _dynarray_resize(da, da->capacity*2);
  }
  
  da->data[da->rear] = val;
  da->rear = (da->rear + 1) % da->capacity;
  da->data[da->rear] = val;
  da->size = da->size + 1;

  return;



}

void* da_dequeue(struct dynarray* da)
{
  
  void* removed = da->data[da->front];
  da->front = (da->front + 1) % da->capacity;
  da->size = da->size - 1;
  return removed;


}

