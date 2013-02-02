#include <stdio.h>
#include <malloc.h>

#include "list.h"

/*
 * 创建新节点
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
 * 获取节点
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
 * 链表初始化
 */
void list_init(LinkList *list)
{
	list->length = 0;
	list->head = NULL;
}

/*
 * 释放链表
 */
void list_free(LinkList *list)
{
	NODE *last;
	NODE *current;

	if ( list_empty(list) ) {
		printf("链表已空, 无需释放.");
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
 * 尾部追加
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
 * 头部添加
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
 * 插入到第pos个位置
 */
void list_insert(LinkList *list, ElementType data, int pos)
{
	NODE *current, *new_node;
	
	if( 0 == pos)
	{
		new_node = node_new(list->head, data);
		list->head = new_node;
	}else if(pos > list_length(list) || pos < 0){
		printf("插入位置超出索引.");
		return ;
	}else{
		current = find_node(list->head, pos-1);		
		new_node = node_new(current->next, data);
		current->next = new_node;
	}
	list->length++;
}


/*
 * 删除第pos个位置的节点
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
		printf("删除位置超出索引.");
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
 * 获取长度
 */
int	list_length(LinkList *list)
{
	return list->length;
}


/*
 * 判断链表是否为空
 */
int	list_empty(LinkList *list)
{
	return (0 == list->length);
}

/*
 * 遍历每个元素, 并对每个元素执行func方法
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
