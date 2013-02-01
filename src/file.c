#include <stdio.h>
#include <malloc.h>

#include "file.h"
#include "str.h"

// 文件处理
void process(char filename_in[256])
{
	FILE *file_deal;
	FILE *file_out;

	char filename_out[256];

	char buffer[256];
	char *str = NULL;
	char *after;	

	if((file_deal = fopen(filename_in,"r")) == NULL)
	{
		printf("文件打开失败");
		return ;
	}

	sprintf(filename_out, "%s.en.c", filename_in);

	if((file_out = fopen(filename_out,"w")) == NULL)
	{
		printf("文件生成失败");
		return ;
	}


	while( (str = fgets(buffer,256,file_deal)) != NULL){		
		after = (char *)malloc(sizeof(char) * 256);

		// 判断代码是否是注释

			// 不是注释,替换中文关键字
			replace_ZhToEn(str, after);

			// 是注释,忽略替换直接输出

	    fputs(after,file_out);
		free(after);
	}

	fclose(file_deal);
	fclose(file_out);

	printf("文件处理成功");
}
