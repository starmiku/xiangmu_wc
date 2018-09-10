#include <stdio.h>
#include <stdlib.h>
#include "func.h"
#define _CRT_SECURE_NO_WARNINGS

int main()
{
	test();
	system("pause");
	return 0;
}

void test()
{
	int ch;
	FILE * fp;
	char fname[50];
	printf("Enter the name of the file: ");
	scanf("%s", fname);
	fp = fopen(fname, "r");
	if (fp == NULL)
	{
		printf("Failed to open file.\n");
		exit(1);

	}
	GetLine(fp);
	rewind(fp);
	GetWord(fp);
	fclose(fp);
}

void GetLine(FILE *f)
{
	int letter = 0, line = 0;
	int mark = 0;
	while (!feof(f))
	{
		letter = fgetc(f);
		if (letter == '\n') //换行行数+1
			line++;
	}
	printf("line = %d\n", line);
}

void GetWord(FILE *f)
{
	int letter = 0, word = 0;
	int mark = 0;
	while (!feof(f))
	{
		letter = fgetc(f);
		if ((letter >= 'a'&&letter <= 'z') || (letter >= 'A'&&letter <= 'Z') || letter == '_')
		{
			if (mark == 0)
				mark = 1; //标记为字符串
		}
		else if (letter == '.') //防止头文件和浮点数的'.'被误判
		{
			if (mark == 0 || mark == 1)
				continue;
		}
		else
		{
			if (mark == 1) //当前为非字符串且前面为字符串视为字符串结束
			{
				word++;
				mark = 0;
			}
			else 
				continue;
		}
	}
	printf("word = %d\n", word);
}