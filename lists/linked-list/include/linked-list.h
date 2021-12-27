#ifndef _LINKED_LIST_H_
#define _LINKED_LIST_H_

#define LINKED_LIST_BEGIN				1
#define NULL_POINTER					-1
#define INVALID_ITEM					-2
#define ITEM_MEMMORY_ALLOCATION_ERROR	-3

typedef struct LINKED_LIST LINKED_LIST;

LINKED_LIST* linked_list_new ();

int 	linked_list_empty 		( LINKED_LIST* list ); 
int 	linked_list_length 		( LINKED_LIST* list );
int 	linked_list_add 		( LINKED_LIST* list, void* item );
int 	linked_list_add_begin	( LINKED_LIST* list, void* item );
int 	linked_list_add_at 		( LINKED_LIST* list, void* item, unsigned int position );
void* 	linked_list_iterator 	( LINKED_LIST* list );
void* 	linked_list_get_at		( LINKED_LIST* list, int position );
void* 	linked_list_end 		( LINKED_LIST* list );
void* 	linked_list_start 		( LINKED_LIST* list );

#endif
