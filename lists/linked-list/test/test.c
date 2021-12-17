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

void test_linked_list_new ( LINKLED_LIST* list );

/* *********************************************************************** */

int main ( int argc, char* argv[] )
{
	LINKLED_LIST* list = linked_list_new();

	test_linked_list_new( list );

	return 0;
}

/* *********************************************************************** */

void test_linked_list_new ( LINKLED_LIST* list )
{
	if ( !list ) ERROR("Fail to create 'linked-list'", -1);		
}

