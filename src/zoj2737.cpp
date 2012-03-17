#include <iostream>
#include <string>
#include <map>

using namespace std;

int main()
{
	string a,b;
	int total;
	
	while(cin >> a >> b)
	{
		b += b;
		int i,len = b.length() / 2;
		map<string,int> rot;
		
		for(i=0;i<len;i++)
		{
			string search = b.substr(i,len);
			
			int begin = 0,count = 0;
			while((begin = a.find(search,begin) + 1) != string::npos + 1)
				count++;
			
			rot[search] = count;
		}
		
		total = 0;
		map<string,int>::iterator iter = rot.begin();
		while(iter != rot.end())
		{
			total += iter->second;
			iter++;
		}
		cout << total << endl;
	}
	
	return 0;
}

