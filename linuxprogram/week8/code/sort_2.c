#include "head.h"

void sort_2() {
	char filename[100]; //文件名称
	char txt[10000]; //文件内容
	FILE *fp; //文件指针

	printf("请输入文件名称(后缀为.txt):");
	scanf("%s", &filename);

	if ((fp = fopen(filename, "w")) == NULL) {
		printf("打开失败！");
	}
	printf("请输入内容（以回车结束）:");
	scanf("%s", &txt);
	fprintf(fp, "%s ", txt);
	printf("输入成功！\n");
	printf("  \n");


	fclose(fp);
}
