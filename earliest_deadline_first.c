#include<stdio.h>
void main()
{

 int number,i,waiting;
 int q = 0;
 int flag2 = 1;
 int near = 10000;
 int j = -1;
 int cnt = 0;
 
 printf("\nEnter the no of processes:");
 scanf("%d",&number);
 
 int burst[number],begin[number],end[number], flag[number];
 for(i=0;i<number;i++)
	flag[number] = 0;
 
 waiting = 0;
 
 for(i=0;i<number;i++)
 {
 	printf("\nEnter absolute begin time, burst time and absolute end for process %d:",i+1);
 	scanf("%d %d %d", &begin[i], &burst[i], &end[i]);
 }

 while(flag2)
 {
	for(i = 0; i< number;i++)
	{
		if(begin[i] == q || burst[j] == 0)
		{
			if(flag[i] != 1)
			{
				if((end[i] - q < near)
				{
					near = (end[i] -q);
					j = i;
				}
			}
		}	
	}
	if(burst[j] == 0)
	{
		near = 10000;
		j=-1;
	}
	if(j!=-1)
	{
		printf("\n from time quantum %d to %d, proc %d", q,q+1, j+1);
		burst[j]--;
	
		if(burst[j] == 0)
		{
			flag[j]=1;
			cnt++;
		}
	}
	if(cnt == number)
		flag2 = 0;
	
 q++;
 }
 
}
