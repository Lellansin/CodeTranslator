#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <malloc.h>

#include "file.h"
#include "str.h"

char * getFilename(char *filename_in, char *origin, char *suffix )
{
	char *p = filename_in;
	char *dot;

	while( *p ){
		if(*p == '.')
		{
			dot = p;
		}
		p++;
	}
	memcpy(origin, filename_in, dot - filename_in);
	*(origin + (dot - filename_in)) = '\0';

	sprintf(origin, "%s.%s\0", origin, suffix);
	
	return origin;
}

// �ļ�����
void process(char filename_in[FILENAME_MAX])
{
	FILE *file_deal;
	FILE *file_out;
	char filename_out[FILENAME_MAX] = { 0, };
	char buffer[FILENAME_MAX];
	char *str = NULL;
	char *after;	
	char command[50];

	if((file_deal = fopen(filename_in,"r")) == NULL)
	{
		printf("�ļ���ʧ��");
		return ;
	}

	getFilename(filename_in, filename_out, "en.c");

	if((file_out = fopen(filename_out,"w")) == NULL)
	{
		printf("�ļ�����ʧ��");
		return ;
	}


	while( (str = fgets(buffer, FILENAME_MAX, file_deal)) != NULL){		
		after = (char *)malloc(sizeof(char) * FILENAME_MAX);

		// �жϴ����Ƿ���ע��

			// ����ע��,�滻���Ĺؼ���
			replace_ZhToEn(str, after);

			// ��ע��,�����滻ֱ�����

	    fputs(after,file_out);
		free(after);
	}

	fclose(file_deal);
	fclose(file_out);

	printf("�ļ�����ɹ�");

	// ���ñ�������������
	system("config.bat");
	printf("\n");

	// ʹ�ñ������������ɵĴ���
	sprintf(command, "cl.exe %s", filename_out);
	system(command);

	// �������ɹ�,ִ�����ɵ�exe�ļ�
	getFilename(filename_out, command, "exe");
	printf("\n");
	system(command);

}


/*
 * ��ȡ�����ļ�
 */
void ConfigInit()
{

}