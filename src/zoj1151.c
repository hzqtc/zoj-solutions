#include <stdio.h>
#include <ctype.h>
#include <string.h>

#define MAX 100
void reverseput(void);
void reverse(char *);

int main()
{
	int block,line;
	int i,j;

	scanf("%d",&block);

	for(i=0;i<block;i++)/*block个语句块循环*/
	{
		scanf("%d",&line);
		while(getchar() != '\n')/*跳过数字后面的空格直到遇到回车*/
			;

		for(j=0;j<line;j++)
		{
			reverseput();
		}
		if(i < block - 1) putchar('\n');
	}

	return 0;
}

void reverseput(void)/*处理一行的子程序*/
{
	char word[MAX];

	while(scanf("%s",word) != EOF)/*从该行中读入一个单词*/
	{
		reverse(word);/*将单词倒序*/
		printf(word);/*输出之*/

		if(getchar() == '\n')/*如果换行了，就输出换行，退出循环*/
		{
			putchar('\n');
			break;
		}
		else/*否则输出单词间的空格一个*/
			putchar(' ');
	}
}

void reverse(char * word)
{
	int i;
	int len = strlen(word);
	char temp;

	for(i = 0;i < len / 2;i++)
	{
		temp= word[i];
		word[i] = word[len - i - 1];
		word[len - i - 1] = temp;
	}
}