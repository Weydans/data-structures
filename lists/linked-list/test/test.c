/* **************************************************************************
test.c

Responsible to check linked list functions

Author: Weydans Barros
Date:	16/12/2021

Compile:
gcc -I./include source/linked-list.c test/test.c -o test-linked-list 

************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include "linked-list.h"

/* *********************************************************************** */

#define ERROR(m,c) {\
			printf("\033[31;01m%s:%d: %s\n\033[00m", __FILE__, __LINE__, m);\
			exit(c);\
		}

void test_linked_list_new 	 ( LINKED_LIST* list );
void test_linked_list_empty  ( int expected, int given );
void test_linked_list_length ( int expected, int given );
void test_linked_list_get_at ( void* expected, void* given );
void test_linked_list_end 	 ( void* expected, void* given );
void test_linked_list_start  ( void* expected, void* given );

/* *********************************************************************** */

int main ( int argc, char* argv[] )
{
	int i			= 0;
	int add_int[] 	= { 1, 3, 5, 7, 9 };
	int* acumulator = NULL;

	LINKED_LIST* list = linked_list_new();
	
	test_linked_list_new( list );
	test_linked_list_empty( 1, linked_list_empty( list ) );
	test_linked_list_length( 0, linked_list_length( list ) );

	linked_list_add( list, &add_int[0] );

	test_linked_list_empty( 0, linked_list_empty( list ) );
	test_linked_list_length( 1, linked_list_length( list ) );
	test_linked_list_get_at( &add_int[0], linked_list_get_at( list, 1 ) );

	linked_list_add( list, &add_int[1] );

	test_linked_list_length( 2, linked_list_length( list ) );
	test_linked_list_get_at( &add_int[1], linked_list_get_at( list, 2 ) );
	
	linked_list_add( list, &add_int[2] );
	linked_list_add( list, &add_int[3] );
	linked_list_add( list, &add_int[4] );

	test_linked_list_length( 5, linked_list_length( list ) );

	for ( i = 0; acumulator = (int*) linked_list_iterator( list ); i++ ) 
	{
		test_linked_list_get_at( &add_int[i], acumulator );
		// printf(" %d ->", *acumulator );
	}
	// puts(" (nil)");

	test_linked_list_end( &add_int[4], linked_list_end( list ) );	

	test_linked_list_start( &add_int[0], linked_list_start( list ) );

	return 0;
}

/* *********************************************************************** */

void test_linked_list_new ( LINKED_LIST* list )
{
	if ( !list ) ERROR("Fail to create 'linked-list'", -1);
}

void test_linked_list_empty (int expected, int given )
{
	char message[50 + 1];

	if ( expected != given )
	{	
		sprintf( message, "Erro: %d expected, %d given", expected, given );
		ERROR( message, -1 );
	}
}

void test_linked_list_length ( int expected, int given )
{
	char message[50 + 1];

	if ( expected != given )
	{	
		sprintf( message, "Erro: %d expected, %d given", expected, given );
		ERROR( message, -1 );
	}
}

void test_linked_list_get_at ( void* expected, void* given )
{
	char message[50 + 1];

	if ( expected != given )
	{	
		sprintf( message, "Erro: %p expected, %p given", expected, given );
		ERROR( message, -1 );
	}
}

void test_linked_list_end ( void* expected, void* given )
{
	char message[50 + 1];

	if ( expected != given )
	{	
		sprintf( message, "Erro: %p expected, %p given", expected, given );
		ERROR( message, -1 );
	}
}

void test_linked_list_start ( void* expected, void* given )
{
	char message[50 + 1];

	if ( expected != given )
	{	
		sprintf( message, "Erro: %p expected, %p given", expected, given );
		ERROR( message, -1 );
	}
}



