#include <stdio.h>

/*
 * Á´±í²âÊÔ
 */

void prn_list(ElementType *data)
{
	printf("%d \n", *data);
}

int main()
{
	LinkList list;

	list_init( &list );

	list_append( &list, 1);
	list_append( &list, 5);
	list_append( &list, 12);
	list_append( &list, 36);
	list_append( &list, 56);
	list_append( &list, 88);

	//list_insert(&list, 0, 3);

	//list_prepend(&list, 10);

	list_delete( &list, 1);

	list_for_each( &list, prn_list);

}