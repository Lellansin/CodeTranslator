#include <stdio.h>

#include "binary.h"
#include "keywords.h"

extern keyword keywords[100];
extern int kw_count;


/*
 * 打印中文每1字节的值
 */
void printChineseBinary(char *string)
{
	int i;
	char *start = string;
	
	printf("%s : \n", string);

	while(*start)
	{
		printf("%d ", *(start++) );
	}

	printf("\n");
}


/*
 * 遍历关键字，打印1字节的值
 */
void printBinary()
{
	int i;
	char *start;

	for(i = 0; i < kw_count; i++)
	{
		printf("%s - %s", keywords[i].name, keywords[i].value);
		start = keywords[i].name;

		printf("\n");
		
		while(*start)
		{
			printf("%d ", *(start++) );
		}

		printf("\n\n");
	}
}