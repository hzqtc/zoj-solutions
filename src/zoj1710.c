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
		lfFatigue = lfDistanceClimb * (double)iFatiguePercent / (double)100;	/*ÿ�صݼ����Գ�ʼ��������Ϊ����*/

		while(1)
		{
			if(iDays > 1) 
				lfDistanceClimb -= lfFatigue;							/*���������½�*/
			if(lfDistanceClimb < 0)
				lfDistanceClimb = 0;
			lfClimbHeight += lfDistanceClimb;									/*������*/

			if(lfClimbHeight > iWellHeight)										/*����ȥ*/
			{
				printf("success on day %d\n",iDays);
				break;
			}

			lfClimbHeight -= iDistanceSlide;									/*���£�*/

			if(lfClimbHeight < 0)												/*�����ף�����������ȥ�ˣ�*/
			{
				printf("failure on day %d\n",iDays);
				break;
			}

			iDays++;
		}
	}

	return 0;
}