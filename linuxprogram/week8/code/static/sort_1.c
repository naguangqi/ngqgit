#include "head.h"

void sort_1() {
	FILE *fp;//创建文件指针
	char filename[100];//创建文件的名称

	printf("请输入文件名称(需要加上.txt)：");
	scanf("%s", &filename);

	if ((fp = fopen(filename, "w")) == NULL){
		printf("无法读取或创建文件！");
	}
	fclose(fp);
}
