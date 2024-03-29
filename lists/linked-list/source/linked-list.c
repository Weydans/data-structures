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
	NODE* tail;
};

NODE* linked_list_get_node_at ( LINKED_LIST* list, int position )
{
	int i 	   = 0;
	NODE* swap = NULL;

	if ( !list ||
		 position <= 0 ||
		 linked_list_empty( list ) ||
		 position > linked_list_length( list ) )
			return NULL;

	swap = list->head;

	for ( i = 0; i < linked_list_length( list ); i++, swap = swap->next )
		if ( position == (i + 1) ) 
			return swap;
}

LINKED_LIST* linked_list_new ()
{
	LINKED_LIST* list = ( LINKED_LIST* ) calloc( 1, sizeof( LINKED_LIST ) ); 

	if ( !list ) return NULL;

	list->length = 0;
	list->head 	 = NULL;
	list->tail 	 = NULL;

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

int	linked_list_add_begin ( LINKED_LIST* list, void* item )
{
	NODE* temp = list->head;

	if ( !list ) return NULL_POINTER;
	if ( !item ) return INVALID_ITEM;

	list->head = (NODE*) calloc( 1, sizeof( NODE ) );

	if ( !list->head ) return ITEM_MEMMORY_ALLOCATION_ERROR;

	list->head->data = item;
	list->head->next = temp;
	
	if ( linked_list_empty( list ) ) list->tail = list->head;
		
	list->length++;

	return 0;
}

int	linked_list_add ( LINKED_LIST* list, void* item )
{
	NODE* temp = list->tail;

	if ( !list ) return NULL_POINTER;
	if ( !item ) return INVALID_ITEM;

	if ( linked_list_empty( list ) )  
		return linked_list_add_begin( list, item );

	list->tail = (NODE*) calloc( 1, sizeof( NODE ) );

	if ( !list->tail ) return ITEM_MEMMORY_ALLOCATION_ERROR;

	list->tail->data = item;
	list->tail->next = NULL;

	if ( temp ) temp->next = list->tail;
	
	list->length++;

	return 0;
}

int	linked_list_add_at ( LINKED_LIST* list, void* item, unsigned int position )
{
	NODE* temp = list->tail;

	if ( !list ) return NULL_POINTER;
	if ( !item ) return INVALID_ITEM;

	if ( linked_list_empty( list ) || position == LINKED_LIST_BEGIN ) 
		return linked_list_add_begin( list, item );
	
	else if ( linked_list_length( list ) < position )
	{
		temp = ( NODE* ) calloc( 1, sizeof( NODE ) );

		if ( !temp ) return ITEM_MEMMORY_ALLOCATION_ERROR;

		list->length++;

		return 0;
	}

	return linked_list_add( list, item );
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

void* linked_list_get_at ( LINKED_LIST* list, int position )
{
	NODE* node = linked_list_get_node_at( list, position );

	if ( !node ) return NULL;

	return node->data;
}

void* linked_list_end ( LINKED_LIST* list )
{
	return linked_list_get_at( list, linked_list_length( list ) );
}

void* linked_list_start ( LINKED_LIST* list )
{
	return linked_list_get_at( list, 1 );
}



