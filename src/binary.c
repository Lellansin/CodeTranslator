#include <stdio.h>

#include "binary.h"
#include "keywords.h"

extern _CONFIG Config;

/*
 * 打印字符串每一字节的值
 * 比如用来打印中文每1字节的值
 */
void printByte(char *string)
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
void printByteKeywords()
{
	int i;
	char *start;

	for(i = 0; i < Config.count; i++)
	{
		printf("%s - %s", Config.keywords[i].name, Config.keywords[i].value);
		start = Config.keywords[i].name;

		printf("\n");
		
		while(*start)
		{
			printf("%d ", *(start++) );
		}

		printf("\n\n");
	}
}