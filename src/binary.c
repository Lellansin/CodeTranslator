#include <stdio.h>

#include "binary.h"
#include "keywords.h"

extern _CONFIG Config;

/*
 * ��ӡ�ַ���ÿһ�ֽڵ�ֵ
 * ����������ӡ����ÿ1�ֽڵ�ֵ
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
 * �����ؼ��֣���ӡ1�ֽڵ�ֵ
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