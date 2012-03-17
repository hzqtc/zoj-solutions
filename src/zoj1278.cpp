#include <iostream>

using namespace std;

int main()
{
    const int MAX = 10000;
    int l,z,i,m;
    int rndnum[MAX],count,next;
    int caseindex = 1;
    int j;

    while(cin>>z>>i>>m>>l ,!(z == 0 && i == 0 && m == 0 && l == 0))
    {
	rndnum[0] = l;
	count = 1;
	while(1)
	{
	    next = (rndnum[count - 1] * z + i) % m;
	    for(j = 0;j<count;j++)
	    {
		if(next == rndnum[j])
		    break;
	    }
	    if(j >= count)
		rndnum[count++] = next;
	    else
	    {
		cout<<"Case "<<caseindex<<": "<<count - j<<endl;
		break;
	    }
	}
	caseindex++;
    }

    return 0;
}

