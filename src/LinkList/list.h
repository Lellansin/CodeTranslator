#ifndef LIST_H
#define LIST_H

typedef int ElementType;

typedef struct node {
	ElementType data;
	struct node *next;
} NODE;

typedef struct list {
	int length;
	NODE *head;
} LinkList;

typedef void(*FUNC)(ElementType *data);

void list_init(LinkList *list);
void list_free(LinkList *list);
void list_append(LinkList *list, ElementType data);
void list_prepend(LinkList *list, ElementType data);
void list_insert(LinkList *list, ElementType data, int pos);
void list_delete(LinkList *list, int pos);
int	 list_length(LinkList *list);
int	 list_empty(LinkList *list);
void list_for_each(LinkList *list, FUNC func);

#endif
