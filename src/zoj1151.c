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

	for(i=0;i<block;i++)/*block������ѭ��*/
	{
		scanf("%d",&line);
		while(getchar() != '\n')/*�������ֺ���Ŀո�ֱ�������س�*/
			;

		for(j=0;j<line;j++)
		{
			reverseput();
		}
		if(i < block - 1) putchar('\n');
	}

	return 0;
}

void reverseput(void)/*����һ�е��ӳ���*/
{
	char word[MAX];

	while(scanf("%s",word) != EOF)/*�Ӹ����ж���һ������*/
	{
		reverse(word);/*�����ʵ���*/
		printf(word);/*���֮*/

		if(getchar() == '\n')/*��������ˣ���������У��˳�ѭ��*/
		{
			putchar('\n');
			break;
		}
		else/*����������ʼ�Ŀո�һ��*/
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