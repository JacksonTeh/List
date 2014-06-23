#include "unity.h"
#include "List.h"
#include "CException.h"
#include "stdio.h"
#include "ErrorCode.h"

void setUp(void)
{
}

void tearDown(void)
{
}

void test_listIsFull_given_full_list_should_return_1(void)
{
	int result;
	List *list = listNew(1);

	list->size = 1;
	result = listIsFull(list);
	
	TEST_ASSERT_EQUAL(1, list->length);
	TEST_ASSERT_EQUAL(1, list->size);
	TEST_ASSERT_EQUAL(1, result);
	
	listDel(list);
}

void test_listIsFull_return_0_to_indicate_list_is_not_full(void)
{
	int result;
	List *list = listNew(1);

	list->size = 0;
	result = listIsFull(list);
	
	TEST_ASSERT_EQUAL(1, list->length);
	TEST_ASSERT_EQUAL(0, list->size);
	TEST_ASSERT_EQUAL(0, result);
	
	listDel(list);
}

void test_listAdd_full_list_should_raise_an_exeption(void)
{
	CEXCEPTION_T err;
	List *list = listNew(1);

	list->size = 1;
	
	Try{
		listAdd(list, 4);
		TEST_FAIL_MESSAGE("Should generate an exception due to the list full");
	}Catch(err)
	{	
		TEST_ASSERT_EQUAL_MESSAGE(ERR_LIST_IS_FULL, err, "Expected ERR_LIST_IS_FULL exception");
		printf("Success: Exception generated. Error code: %d.\n", err);
	}
	
	TEST_ASSERT_EQUAL(1, list->length);
	TEST_ASSERT_EQUAL(1, list->size);
	
	listDel(list);
}

void test_listAdd_adding_2_3_should_store_in_the_buffer_0_and_1(void)
{
	CEXCEPTION_T err;
	List *list = listNew(2);

	listAdd(list, 2);
	listAdd(list, 3);
	
	TEST_ASSERT_EQUAL(2, list->buffer[0]);
	TEST_ASSERT_EQUAL(3, list->buffer[1]);
	TEST_ASSERT_EQUAL(2, list->length);
	TEST_ASSERT_EQUAL(2, list->size);
	
	listDel(list);
}

void test_listIsEmpty_given_empty_list_should_return_1(void)
{
	int result;
	List *list = listNew(1);

	list->size = 0;
	result = listIsEmpty(list);
	
	TEST_ASSERT_EQUAL(1, list->length);
	TEST_ASSERT_EQUAL(0, list->size);
	TEST_ASSERT_EQUAL(1, result);
	
	listDel(list);
}

void test_listIsEmpty_return_0_to_indicate_the_list_is_not_empty(void)
{
	int result;
	List *list = listNew(1);

	list->size = 1;
	result = listIsEmpty(list);
	
	TEST_ASSERT_EQUAL(1, list->length);
	TEST_ASSERT_EQUAL(1, list->size);
	TEST_ASSERT_EQUAL(0, result);
	
	listDel(list);
}

void test_listRemove_empty_list_should_raise_an_exeption(void)
{
	CEXCEPTION_T err;
	List *list = listNew(1);

	list->size = 0;
	
	Try{
		listRemove(list);
		TEST_FAIL_MESSAGE("Should generate an exception due to the list empty");
	}Catch(err)
	{	
		TEST_ASSERT_EQUAL_MESSAGE(ERR_LIST_IS_EMPTY, err, "Expected ERR_LIST_IS_EMPTY exception");
		printf("Success: Exception generated. Error code: %d.\n", err);
	}
	
	TEST_ASSERT_EQUAL(1, list->length);
	TEST_ASSERT_EQUAL(0, list->size);
	
	listDel(list);
}

void test_listRemove_given_4_5_should_remove_4_then_5(void)
{
	int result;
	List *list = listNew(2);

	listAdd(list, 4);
	listAdd(list, 5);
	result = listRemove(list);
	TEST_ASSERT_EQUAL(4, result);
	result = listRemove(list);
	TEST_ASSERT_EQUAL(5, result);
	
	TEST_ASSERT_EQUAL(2, list->length);
	TEST_ASSERT_EQUAL(0, list->size);
	
	listDel(list);
}