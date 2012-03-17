#include <iostream>
#include <cstdlib>
#include <string>

using namespace std;

const int LEN = 100;
struct book
{
	char name[LEN];
	int year;
	int price;
};

int cmp_name(const void* a,const void* b);
int cmp_year(const void* a,const void* b);
int cmp_price(const void* a,const void* b);

int main()
{
	const int MAX = 100;
	book bk[MAX];
	int bookcount;
	string type;
	int caseindex = 1;
	
	while(cin >> bookcount , bookcount > 0)
	{
		if(caseindex++ > 1)
			cout << endl;
		
		int i;
		for(i=0;i<bookcount;i++)
			cin >> bk[i].name >> bk[i].year >> bk[i].price;
		
		/*
		 *Note: That Name is the first criteria, Year is the second, and Price the third.
		 *It means that if the sorting criteria is Year and you got two books with the same Year,
		 *you'd sort them according to their Name. If they equals again, according to their Price.
		 *No two books will be same in all the three parameters.
		 */
		qsort(bk,bookcount,sizeof(book),cmp_price);
		qsort(bk,bookcount,sizeof(book),cmp_year);
		qsort(bk,bookcount,sizeof(book),cmp_name);
		
		cin >> type;
		
		if(type == "Name")
			qsort(bk,bookcount,sizeof(book),cmp_name);
		else if(type == "Year")
			qsort(bk,bookcount,sizeof(book),cmp_year);
		else if(type == "Price")
			qsort(bk,bookcount,sizeof(book),cmp_price);
		
		for(i=0;i<bookcount;i++)
			cout << bk[i].name << ' ' << bk[i].year << ' ' << bk[i].price << endl;
	}
	
	return 0;
}

int cmp_name(const void* a,const void* b)
{
	return strcmp(((book*)a)->name,((book*)b)->name); 
}

int cmp_year(const void* a,const void* b)
{
	return ((book*)a)->year - ((book*)b)->year;
}

int cmp_price(const void* a,const void* b)
{
	return ((book*)a)->price - ((book*)b)->price;
}

