#include <stdio.h>

int main()
{
	long iWellHeight,iDistanceSlide,iFatiguePercent;
	double lfClimbHeight,lfDistanceClimb,lfFatigue;
	long iDays;

	while(scanf("%d%lf%d%d",&iWellHeight,&lfDistanceClimb,&iDistanceSlide,&iFatiguePercent) , iWellHeight != 0)
	{
		iDays = 1;
		lfClimbHeight = 0.0;
		lfFatigue = lfDistanceClimb * (double)iFatiguePercent / (double)100;	/*每回递减量以初始爬坡能力为基数*/

		while(1)
		{
			if(iDays > 1) 
				lfDistanceClimb -= lfFatigue;							/*爬坡能力下降*/
			if(lfDistanceClimb < 0)
				lfDistanceClimb = 0;
			lfClimbHeight += lfDistanceClimb;									/*爬升！*/

			if(lfClimbHeight > iWellHeight)										/*爬出去*/
			{
				printf("success on day %d\n",iDays);
				break;
			}

			lfClimbHeight -= iDistanceSlide;									/*滑下！*/

			if(lfClimbHeight < 0)												/*滚到底！哈哈，出不去了！*/
			{
				printf("failure on day %d\n",iDays);
				break;
			}

			iDays++;
		}
	}

	return 0;
}