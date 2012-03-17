#include <iostream>
#include <string>
#include <cstring>

using namespace std;

int cmp(const void * a,const void * b);

int main()
{
	int casecount,i;
	int diccount,j;
	int strcount,k;

	const int MAX = 110;
	const int LENGTH = 30;
	string dic[MAX],str;
	char out[MAX][LENGTH];
	int outcount;

	bool output,first;

	cin>>casecount;
	for(i=0;i<casecount;i++)
	{
		if(i > 0)
			cout<<endl;

		cin>>diccount;
		for(j=0;j<diccount;j++)
		{
			cin>>dic[j];
		}
		cin>>strcount;
		for(k=0;k<strcount;k++)
		{
			cin>>str;
			output = false;

			for(j=0;j<diccount;j++)//rule 1
			{
				if(str == dic[j])
				{	
					cout<<str<<endl;
					output = true;
					break;
				}
			}

			if(output == true)//rule 2
				continue;

			first = true;
			outcount = 0;

			for(int index = 0;index<str.length() - 1;index++)
			{
				char swap;
				string temp;

				temp = str;
				swap = temp[index];
				temp[index] = temp[index + 1];
				temp[index + 1] = swap;
				for(j=0;j<diccount;j++)
				{
					if(temp == dic[j])
					{	
						strcpy(out[outcount++],temp.c_str());
						output = true;
						break;
					}
				}
			}
		
			if(output == false)//rule 3
				cout<<str<<endl;
			else
			{
				qsort(out,outcount,LENGTH * sizeof(char),cmp);
				for(int c = 0;c<outcount;c++)
				{
					if(first == true)
						first = false;
					else
						cout<<',';
					cout<<out[c];
				}
				cout<<endl;
			}
		}
	}

	return 0;
}

int cmp(const void * a,const void * b)
{
	return strcmp((char *)a,(char *)b);
}
