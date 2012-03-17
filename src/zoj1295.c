#include <stdio.h>

int main()
{
    int count,i,j,k;
    char str[71],c;
    
    scanf("%d",&count);
    
    getchar();
    
    for(i=0;i<count;i++)
    {
        j=0;
        while((c=getchar())!='\n')
        {
            str[j++]=c;
        }
        str[j]='\0';
        
        for(k=j-1;k>=0;k--)
        {
            putchar(str[k]);
        }
        putchar('\n');
    }
    
    return 0;
}
