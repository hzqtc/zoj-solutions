#include <stdio.h>
#include <string.h>

#define Code2Text(i)	((i) == 0 ? '_' : ((i) == 27 ? '.' : (i) - 1 + 'a'))
#define Text2Code(c)	((c) == '_' ? 0 : ((c) == '.' ? 27 : (c) - 'a' + 1))

#define MAX				80

int main()
{
	int key,length,index;
	char ciphertext[MAX],plaintext[MAX],alpha;
	int plaincode,ciphercode;
	
	while(scanf("%d",&key) , key != 0)
	{
		scanf("%s",ciphertext);
		length = strlen(ciphertext);
		
		for(index = 0;index < length;index++)
		{
			alpha = ciphertext[index];
			ciphercode = Text2Code(alpha);
			
			while(index + ciphercode > 27)
				ciphercode -= 28;
			
			plaincode = index + ciphercode;
			plaintext[key * index % length] = Code2Text(plaincode);
		}
		plaintext[length] = '\0';
		printf("%s\n",plaintext);
	}
	
	return 0;
}

