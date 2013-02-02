#include <stdio.h>
#include <string.h>

#include "str.h"
#include "keywords.h"

extern _CONFIG Config;

/*
	��ȡ�ַ����е����ģ����滻��Ӣ��

	char *original	ԭ�ַ���
	char *after		�滻����ַ���

	ʾ����
	char a[50] = "Hey guys! �� i == 1";
	char b[50] = { 0 };
	char *ptr_in = a;
	char *ptr_out = b;
	replace_ZhToEn(ptr_in, ptr_out);
	printf(b);
*/
void replace_ZhToEn(char *original, char *after)
{
	char word[10][256] = {0};
	char *start = after;
	int i = 0;
	int j = 0;
	int flag = 0;

	while(*original)
	{
		if( *original < 0 )
		{
			word[i][j] = *original;
			j++;
			flag = 1;
		}

		if( *original > 0 )
		{	
			if(flag == 1)
			{
				// printf("%s\n", word[i]);
				// printChineseBinary(word[i]);
				after = getValueByName(word[i], after);
				i++;
				flag = 0;
				j = 0;
			}

			*after = *original;
			after++;
		}

		original++;
	}
	*after = '\0';
}

/*
 * ͨ���ؼ��ֵ����Ļ�ȡ��Ӣ��
 * 
 * char *name ���ҵ�����
 * char *add ���ص�Ӣ�ı������ʼ��ַ
 */
char * getValueByName(char *name, char *add)
{
	int i;
	char *start = add;
	int flag = 0;

	for(i = 0; i < Config.count; i++)
	{
		if( strcmp(Config.keywords[i].name, name) == 0 )
		{
			char *p = Config.keywords[i].value;

			while(*p)
			{
				*add = *p;
				add++;
				p++;
			}
			flag = 1;
		}
	}

	if(flag == 0)
	{
		char *p = name;

		while(*p)
		{
			*add = *p;
			add++;
			p++;
		}
	}
	
	*add = '\0';

	return add;
}

/*
 * (δʹ��)
 * ��ȡ�ַ����е�����
 */
void getChinese(char *str)
{
	char word[10][256] = {0};
	int i = 0;
	int j = 0;
	int flag = 0;

	while(*str)
	{
		if( *str < 0 )
		{
			word[i][j] = *str;
			j++;
			flag = 1;
		}

		if( *str > 0 )
		{	
			if(flag == 1)
			{
				printf("%s\n", word[i]);
				i++;
				flag = 0;
			}
			j = 0;
		}

		str++;
	}
}