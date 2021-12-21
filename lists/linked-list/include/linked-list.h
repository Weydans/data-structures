#ifndef _LINKED_LIST_H_
#define _LINKED_LIST_H_

#define NULL_POINTER					-1
#define INVALID_ITEM					-2
#define ITEM_MEMMORY_ALLOCATION_ERROR	-3

typedef struct LINKED_LIST LINKED_LIST;

LINKED_LIST* linked_list_new ();

int 	linked_list_empty 		( LINKED_LIST* list ); 
int 	linked_list_length 		( LINKED_LIST* list );
int 	linked_list_add 		( LINKED_LIST* list, void* item );
void* 	linked_list_iterator 	( LINKED_LIST* list );

#endif
