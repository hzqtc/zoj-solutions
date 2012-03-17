#include <stdio.h>
#include <math.h>

#define BaseColorCount 16

struct RGBColor
{
	int r;
	int g;
	int b;
};

double GetDistance(struct RGBColor *,struct RGBColor *);

int main()
{
	struct RGBColor BaseColor[BaseColorCount];
	struct RGBColor TempColor, * MinBase;
	double MinDistance,TempDistance;
	int i;

	for(i=0;i<BaseColorCount;i++)
	{
		scanf("%d%d%d",&BaseColor[i].r,&BaseColor[i].g,&BaseColor[i].b);
	}

	while(scanf("%d %d %d",&TempColor.r,&TempColor.g,&TempColor.b) , TempColor.r != -1 && TempColor.g != -1 && TempColor.b != -1)
	{
		for(i=0;i<BaseColorCount;i++)
		{
			if(i == 0)
			{
				MinDistance = GetDistance(&BaseColor[0],&TempColor);
				MinBase = &BaseColor[0];
			}
			else
			{
				if((TempDistance = GetDistance(&BaseColor[i],&TempColor)) < MinDistance)
				{
					MinDistance = TempDistance;
					MinBase = &BaseColor[i];
				}
			}
			if(MinDistance == 0.0) break;
		}

		printf("(%d,%d,%d) maps to (%d,%d,%d)\n",TempColor.r,TempColor.g,TempColor.b,MinBase->r,MinBase->g,MinBase->b);
	}

	return 0;
}

double GetDistance(struct RGBColor * c1,struct RGBColor * c2)
{
	int temp,sum = 0.0;
	
	temp = c1->r - c2->r;
	sum += temp * temp;
	temp = c1->g - c2->g;
	sum += temp * temp;
	temp = c1->b - c2->b;
	sum += temp * temp;

	return sqrt((double)sum);
}
