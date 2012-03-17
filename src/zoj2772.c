#include <stdio.h>

#define QUARTER	25
#define DIME	10
#define NICKEL	5
#define PENNY	1

int main()
{
	int Quarter,Dime,Nickel,Penny;
	int AllChange;
	int CaseCount,i;

	scanf("%d",&CaseCount);

	for(i=0;i<CaseCount;i++)
	{
		scanf("%d",&AllChange);

		Quarter = Dime = Nickel = Penny = 0;
		
		while(AllChange >= QUARTER)
		{
			AllChange -= QUARTER;
			Quarter++;
		}
		while(AllChange >= DIME)
		{
			AllChange -= DIME;
			Dime++;
		}
		while(AllChange >= NICKEL)
		{
			AllChange -= NICKEL;
			Nickel++;
		}
		while(AllChange >= PENNY)
		{
			AllChange -= PENNY;
			Penny++;
		}

		printf("%d %d QUARTER(S), %d DIME(S), %d NICKEL(S), %d PENNY(S)\n",i + 1,Quarter,Dime,Nickel,Penny);
	}

	return 0;
}