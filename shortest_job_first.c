#include<stdio.h>
int main()
{

	int num,cnt1,cnt2,temp1,temp2,proc[10],burst[10],wait[10], turn_arnd[10];
	
	for(cnt1=0;cnt1<10;cnt1++)
        {
        	burst[cnt1]=0;
		wait[cnt1]=0;
        }
	printf("\nNumber of process: ");
	scanf("%d",&num);
	
	for(cnt1=0;cnt1<num;cnt1++)
        {
		printf("Burst time for process %d: ",cnt1);
        	scanf("%d",&burst[cnt1]);
                proc[cnt1]=cnt1;
        }
	
	for(cnt1=0;cnt1<num;cnt1++)
        {
        	for(cnt2=cnt1;cnt2<num;cnt2++)
                {
                	if(burst[cnt1]>burst[cnt2])
                        {
                        	temp1=burst[cnt1];
                                temp2=proc[cnt1];
                                burst[cnt1]=burst[cnt2];
                                proc[cnt1]=proc[cnt2];
                                burst[cnt2]=temp1;
                                proc[cnt2]=temp2;
                        }
		}
	}
	
	wait[0]=0;
	for(cnt1=0;cnt1<num;cnt1++)
		wait[cnt1+1]=wait[cnt1]+burst[cnt1];

	for(cnt1=0;cnt1<num;cnt1++)
        {
		turn_arnd[cnt1]=wait[cnt1]+burst[cnt1];
        }
	
	printf("\n\t process \t waiting time \t turn-around time \n");
	for(cnt1=0;cnt1<num;cnt1++)
		printf("\t %d \t %d \t\t %d \n",proc[cnt1],wait[cnt1],turn_arnd[cnt1]);

	return 0;
}
