#ifndef _LINKED_LIST_H_
#define _LINKED_LIST_H_

#define NULL_POINTER					-1
#define INVALID_ITEM					-2
#define ITEM_MEMMORY_ALLOCATION_ERROR	-3

typedef struct LINKLED_LIST LINKLED_LIST;

LINKLED_LIST* linked_list_new ();
int linked_list_empty ( LINKLED_LIST* list ); 
int linked_list_length ( LINKLED_LIST* list);
int linked_list_add ( LINKLED_LIST* list, void* item );
void* linked_list_iterator ( LINKLED_LIST* list );

#endif
