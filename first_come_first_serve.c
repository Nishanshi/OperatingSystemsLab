#include<stdio.h>
int main()
{
    int num,burst_tim[50],wait_tim[50],turn_arnd_tim[50],cnt1,cnt2;
    printf("Enter total number of processes(not more than 50):");
    scanf("%d",&num);
    printf("\nAs all process come at same time, Enter Process Burst Time\n");
    for(cnt1=0;cnt1<num;cnt1++)
    {
        printf("Process %d:",cnt1+1);
        scanf("%d",&burst_tim[cnt1]);
    }
   wait_tim[0]=0;
   for(cnt1=1;cnt1<num;cnt1++)
   {
        wait_tim[cnt1]=0;
        for(cnt2=0;cnt2<cnt1;cnt2++)
        wait_tim[cnt1]+=burst_tim[cnt2];
   }
   printf("\nProcess\t\tBurst Time\tWaiting Time\tTurnaround Time");
   for(cnt1=0;cnt1<num;cnt1++)
   {
       turn_arnd_tim[cnt1]=burst_tim[cnt1]+wait_tim[cnt1];
       avwait_tim+=wait_tim[cnt1];
       avtat+=turn_arnd_tim[cnt1];
       printf("\nP[%d]\t\t%d\t\t%d\t\t%d",cnt1+1,burst_tim[cnt1],wait_tim[cnt1],turn_arnd_tim[cnt1]);
   }
   return 0;
}