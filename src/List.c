#include "List.h"
#include "stdio.h"
#include "malloc.h"
#include "ErrorCode.h"

/*
 * To create list of specific buffer length
 *
 * Input
 *		length		is the length of the stack
 */
List *listNew(int length)
{
	List *list = malloc(sizeof(List));
	list->buffer = malloc(sizeof(int) * length);
	list->size = 0;
	list->length = length;
}

/*
 * To free the memory allocated by list
 *
 * Input
 *		list	is a pointer to List object
 */
void listDel(List *list)
{
	if(list != NULL)
	{
		free(list->buffer);
		free(list);
	}
}

/*
 * To add data into the list and throw an error if list is full
 *
 * Input
 *		list	is a pointer to List object
 *		data		data that add into the list
 */
void listAdd(List *list, int data)
{
	if(listIsFull(list))
		Throw(ERR_LIST_IS_FULL);
		
	list->buffer[list->size] = data;
	list->size++;
}

/*
 * To remove data out of the list and throw an error if list is empty
 *
 * Input
 *		list	is a pointer to List object
 *
 * Return
 *		dataRemove		data that remove out from the list
 */
int listRemove(List *list)
{
	int dataRemove;
	
	if(listIsEmpty(list))
		Throw(ERR_LIST_IS_EMPTY);
	
	// printf("buffer1: %d\n" , *list->buffer);
	// list->buffer++;
	// printf("buffer2: %d\n" , *list->buffer);
	// dataRemove = *list->buffer;
	list->size--;
	dataRemove = list->buffer[list->length - (list->size + 1)];
	// printf("dataRemove: %i\n", dataRemove);
	
	return dataRemove;
}

/*
 * To check list is empty
 *
 * Input
 *		list	is a pointer to List object
 *
 * Return
 *		0	to indicate list is not empty
 *		1	to indicate list is empty
 */
int listIsEmpty(List *list)
{
	if(list->size == 0)
		return 1;
	
	return 0;
}

/*
 * To check list is full
 *
 * Input
 *		list	is a pointer to List object
 *
 * Return
 *		0	to indicate list is not full
 *		1	to indicate list is full
 */
int listIsFull(List *list)
{
	if(list->size == list->length)
		return 1;
	
	return 0;
}