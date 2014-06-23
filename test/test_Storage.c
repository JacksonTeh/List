#include "unity.h"
#include "Storage.h"
#include "stdio.h"
#include "mock_List.h"

void setUp(void)
{
}

void tearDown(void)
{
}

void test_store_with_mock(void)
{
	List list;
	int storeIntegerSize;
	int integer[] = {5, 25, 10, 50};
	int *storedInteger;
	
	//Mock
	listNew_ExpectAndReturn(256, &list);
	listAdd_Expect(&list, 5);
	storeIntegerSize++;
	listAdd_Expect(&list, 25);
	storeIntegerSize++;
	listAdd_Expect(&list, 10);
	storeIntegerSize++;
	listAdd_Expect(&list, 50);
	storeIntegerSize++;
	
	listIsEmpty_ExpectAndReturn(&list, 0);
	listRemove_ExpectAndReturn(&list, 5);
	listIsEmpty_ExpectAndReturn(&list, 0);
	listRemove_ExpectAndReturn(&list, 25);
	listIsEmpty_ExpectAndReturn(&list, 0);
	listRemove_ExpectAndReturn(&list, 10);
	listIsEmpty_ExpectAndReturn(&list, 0);
	listRemove_ExpectAndReturn(&list, 50);
	listIsEmpty_ExpectAndReturn(&list, 1);
	
	//Run store
	store(&list, integer, 4);
	
	//Run retrieve
	storedInteger = retrieve(&list, &storeIntegerSize);
	
	TEST_ASSERT_EQUAL(integer[0], storedInteger[0]);
	TEST_ASSERT_EQUAL(integer[1], storedInteger[1]);
	TEST_ASSERT_EQUAL(integer[2], storedInteger[2]);
	TEST_ASSERT_EQUAL(integer[3], storedInteger[3]);
}
