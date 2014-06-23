#include "stdio.h"
#include "malloc.h"
#include "Storage.h"
#include "List.h"

void store(List *list, int value[], int length)
{
	int i;
	list = listNew(256);
	
	for(i = 0; i < length; i++)
	{
		listAdd(list, value[i]);
		printf("%d ", value[i]);
	}
	
	printf("\ni: %d\n", i);
}

int *retrieve(List *list, int *size)
{
	int i = 0;
	int *value;
	
	value = malloc(sizeof(int) * (*size));
	
	while(!listIsEmpty(list))
	{
		value[i++] = listRemove(list);
		printf("%d ", value[i-1]);
	}
	
	return value;
}