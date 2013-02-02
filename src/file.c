#include <stdio.h>
#include <malloc.h>

#include "file.h"
#include "str.h"


// �ļ�����
void process(char filename_in[FILENAME_MAX])
{
	FILE *file_deal;
	FILE *file_out;

	char filename_out[FILENAME_MAX];

	char buffer[FILENAME_MAX];
	char *str = NULL;
	char *after;	

	if((file_deal = fopen(filename_in,"r")) == NULL)
	{
		printf("�ļ���ʧ��");
		return ;
	}

	sprintf(filename_out, "%s.en.c", filename_in);

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
}


/*
 * ��ȡ�����ļ�
 */
void ConfigInit()
{

}