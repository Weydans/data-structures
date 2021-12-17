/* **************************************************************************
test.c

Responsible to chech linked list functions

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

void assert_int ( int expected, int given );
void test_linked_list_new ( LINKLED_LIST* list );

/* *********************************************************************** */

int main ( int argc, char* argv[] )
{
	int add_first_int = 3;
	LINKLED_LIST* list = linked_list_new();
	
	test_linked_list_new( list );

	linked_list_add( list, &add_first_int );
	
	assert_int( 1, linked_list_length( list ) );

	return 0;
}

/* *********************************************************************** */

void assert_int ( int expected, int given )
{
	char message[50 + 1];

	if ( expected != given ) 
	{
		sprintf( message, "Erro: %d expected, %d given", expected, given );
		ERROR( message, -1 );
	}
}

void test_linked_list_new ( LINKLED_LIST* list )
{
	if ( !list ) ERROR("Fail to create 'linked-list'", -1);
	
	assert_int( 0, linked_list_length( list ) );
}



