#include "head.h"

void sort_3() {
	char filename[100]; //文件名称
	char ch; //文件内容
	FILE *fp; //文件指针

	printf("请输入文件名称(后缀为.txt):");
	scanf("%s", &filename);

	if ((fp = fopen(filename, "r")) == NULL) {
		printf("打开失败！");
	}
	printf("   \n");

	ch = fgetc(fp); //从fp所指文件的当前指针位置读取一个字符
	while (ch != EOF) //判断刚读取的字符是否是文件结束符
	{
		putchar(ch); //若不是结束符，将它输出到屏幕上显示
		ch = fgetc(fp); //继续从fp所指文件中读取下一个字符
	} 

	printf("\n");

	fclose(fp);

}
