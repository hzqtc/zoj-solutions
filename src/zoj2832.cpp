#include <iostream>
#include <string>
#include <cstring>

using namespace std;

int main()
{
    int headercount,i;
    const int MAX = 100;
    class header
    {
    public:
        string name;
        string include[MAX];
        int inclucount;
        bool included;
    }myh[MAX];
    const int LEN = 30;
    char out[MAX][LEN];
    int outcount;
    int caseindex = 0;
    int cmp(const void *a,const void * b);

    while(cin>>headercount)
    {
        if(caseindex++ > 0)
            cout<<endl;

        for(i=0;i<headercount;i++)
        {
            cin>>myh[i].name;
            cin>>myh[i].inclucount;
            for(int j = 0;j<myh[i].inclucount;j++)
            {
                cin>>myh[i].include[j];
            }
            myh[i].included = false;
        }

        outcount = 0;
        for(i=0;i<headercount;i++)
        {
            for(int j = 0;j<headercount;j++)
            {
                if(j != i)
                {
                    for(int k = 0;k<myh[j].inclucount;k++)
                    {
                        if(myh[j].include[k] == myh[i].name)
                        {
                            myh[i].included = true;
                            break;
                        }
                    }
                }
                if(myh[i].included == true)
                    break;
            }
            if(myh[i].included == false)
                strcpy(out[outcount++],myh[i].name.c_str());
        }

        qsort(out,outcount,sizeof(char) * LEN,cmp);
        for(int index = 0;index<outcount;index++)
        {
            cout<<out[index]<<endl;
        }
    }

    return 0;
}

int cmp(const void *a,const void * b)
{
    return strcmp((char *)a,(char *)b);
}

