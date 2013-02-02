
#include <stdio.h>

#include "keywords.h"
#include "file.h"
#include "list.h"

void help(void);

void prn_list(ElementType *data)
{
	printf("%d \n", *data);
}


int main(int argc, char *argv[])
{
	char text1[20];
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
	getchar();

	
/*
	// 初始化配置
	init_keywords();

	if(argc == 1)
	{
		help();
	}else if(argc == 2)
	{
		process(argv[1]);
	}else if(argc == 3){
		//process(argv[1], argv[2]);
	}
*/
	return 0;
}

void help()
{
	printf("代码翻译工具 v0.1\n");
	printf("语法：Linh 代码文件\n");
}

