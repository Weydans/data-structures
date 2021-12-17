#include <stdlib.h> 
#include "linked-list.h" 

typedef struct NODE NODE;

struct NODE {
	void* data;
	NODE* next;
};

struct LINKLED_LIST {
	int length;
	NODE* head;
};

LINKLED_LIST* linked_list_new ()
{
	LINKLED_LIST* list = ( LINKLED_LIST* ) calloc( 1, sizeof( LINKLED_LIST ) ); 

	if ( !list ) return NULL;

	list->length = 0;
	list->head 	 = NULL;

	return list;
}

int linked_list_empty ( LINKLED_LIST* list )
{
	if ( !list ) return NULL_POINTER;
	return ( list->length == 0 );	
}

int linked_list_length ( LINKLED_LIST* list )
{
	if ( !list ) return NULL_POINTER;
	return list->length;
}

int linked_list_add( LINKLED_LIST* list, void* item )
{
	if ( !list ) return NULL_POINTER;
	if ( !item ) return INVALID_ITEM;

	if ( list->length == 0 ) 
	{
		list->head = (NODE*) calloc( 1, sizeof( NODE ) );
	
		if ( !list->head ) return ITEM_MEMMORY_ALLOCATION_ERROR;

		list->head->data = item;
		list->head->next = NULL;

		list->length++;
	}

	return 0;
}
