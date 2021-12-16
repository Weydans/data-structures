#include <stdlib.h> 
#include "linked-list.h" 

struct LINKLED_LIST {
	size_t length;
};

LINKLED_LIST* linked_list_new ()
{
	LINKLED_LIST* list = ( LINKLED_LIST* ) calloc( 1, sizeof( LINKLED_LIST ) ); 

	list->length = 0;

	return list;
}

