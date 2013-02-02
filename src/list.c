#include <stdio.h>
#include <malloc.h>

#include "list.h"

/*
 * �����½ڵ�
 */
static NODE *node_new(NODE *next, ElementType data)
{
	NODE *new_node;

	new_node = (NODE *)malloc(sizeof(NODE));	
	new_node->data = data;
	new_node->next = next;

	return new_node;
}

/*
 * ��ȡ�ڵ�
 */
static NODE *find_node(NODE *current, int pos)
{
	int i;
	for (i = 0; i < pos; i++) {
		current = current->next;
	}
	return current;
}


/*
 * �����ʼ��
 */
void list_init(LinkList *list)
{
	list->length = 0;
	list->head = NULL;
}

/*
 * �ͷ�����
 */
void list_free(LinkList *list)
{
	NODE *last;
	NODE *current;

	if ( list_empty(list) ) {
		printf("�����ѿ�, �����ͷ�.");
		return ;
	} else {
		current = list->head->next;
		last = list->head;

		while (NULL != current) {
			last = current;
			current = current->next;
			free(last);
		}

		list->length = 0;
		list->head = NULL;
	}
}

/*
 * β��׷��
 */
void list_append(LinkList *list, ElementType data)
{
	NODE *new_node, *prev;
	int i;
	
	if ( list_empty(list) ) {
		new_node = node_new(NULL, data);
		new_node->next = new_node;
		list->head = new_node;
	} else {		
		prev = find_node(list->head, list_length(list) - 1 );
		new_node = node_new(prev->next, data);
		prev->next =  new_node;
	}
	
	list->length++;
}

/*
 * ͷ�����
 */
void list_prepend(LinkList *list, ElementType data)
{
	NODE *new_node;
	if( list_empty(list) ) {
		new_node = node_new(NULL, data);
	} else {
		new_node = node_new(list->head->next, data);
	}
	list->head = new_node;
	list->length++;
}


/*
 * ���뵽��pos��λ��
 */
void list_insert(LinkList *list, ElementType data, int pos)
{
	NODE *current, *new_node;
	
	if( 0 == pos)
	{
		new_node = node_new(list->head, data);
		list->head = new_node;
	}else if(pos > list_length(list) || pos < 0){
		printf("����λ�ó�������.");
		return ;
	}else{
		current = find_node(list->head, pos-1);		
		new_node = node_new(current->next, data);
		current->next = new_node;
	}
	list->length++;
}


/*
 * ɾ����pos��λ�õĽڵ�
 */
void list_delete(LinkList *list, int pos)
{
	NODE *current, *to_delete;

	if(0 == pos)
	{
		list->head = list->head->next;
	}
	else if(pos > list_length(list) || pos < 0)
	{
		printf("ɾ��λ�ó�������.");
		return ;
	}else
	{
		current = find_node(list->head, pos-1);
		to_delete = current->next;
		current->next = to_delete->next;
		free(to_delete);
	}

	list->length--;
}


/*
 * ��ȡ����
 */
int	list_length(LinkList *list)
{
	return list->length;
}


/*
 * �ж������Ƿ�Ϊ��
 */
int	list_empty(LinkList *list)
{
	return (0 == list->length);
}

/*
 * ����ÿ��Ԫ��, ����ÿ��Ԫ��ִ��func����
 */
void list_for_each(LinkList *list, FUNC func)
{
	NODE *tmp;
	int i;
	
	for (i = 0; i < list_length(list); i++) {
		tmp = find_node(list->head, i);
		func(&tmp->data);
	}
}
