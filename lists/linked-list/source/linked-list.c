#include <stdlib.h> 
#include "linked-list.h" 

typedef struct NODE NODE;

struct NODE {
	void* data;
	NODE* next;
};

struct LINKED_LIST {
	int length;
	NODE* head;
};

LINKED_LIST* linked_list_new ()
{
	LINKED_LIST* list = ( LINKED_LIST* ) calloc( 1, sizeof( LINKED_LIST ) ); 

	if ( !list ) return NULL;

	list->length = 0;
	list->head 	 = NULL;

	return list;
}

int linked_list_empty ( LINKED_LIST* list )
{
	if ( !list ) return NULL_POINTER;
	return ( list->length == 0 );	
}

int linked_list_length ( LINKED_LIST* list )
{
	if ( !list ) return NULL_POINTER;
	return list->length;
}

int linked_list_add( LINKED_LIST* list, void* item )
{
	NODE* swap = NULL;
	NODE* new_node = NULL;

	if ( !list ) return NULL_POINTER;
	if ( !item ) return INVALID_ITEM;

	if ( linked_list_empty( list ) ) 
	{
		list->head = (NODE*) calloc( 1, sizeof( NODE ) );
	
		if ( !list->head ) return ITEM_MEMMORY_ALLOCATION_ERROR;

		list->head->data = item;
		list->head->next = NULL;

	} 
	else if ( !linked_list_empty( list ) )
	{
		new_node = list->head;

		while ( swap = new_node->next ) new_node = new_node->next;

		new_node->next = ( NODE* ) calloc( 1, sizeof( NODE ) );

		new_node->next->data = item;
		new_node->next->next = NULL;
	}

	list->length++;

	return 0;
}

void* linked_list_iterator ( LINKED_LIST* list )
{
	static NODE* current_node = NULL;

	if ( !list ) return NULL;

	if ( !current_node ) 
		current_node = list->head;

	else if ( current_node ) 
		current_node = current_node->next;
	
	return current_node ? current_node->data : NULL;
}

