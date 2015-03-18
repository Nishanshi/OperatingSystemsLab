#include<stdio.h>

int main()
{
	int p_num, r_num;
	printf("\nEnter number of processes: ");
	scanf("%d",&p_num);
	printf("\nEnter number of resources: ");
	scanf("%d",&r_num);
	
	int resource[r_num], available[r_num], done[p_num]={0}, flag[p_num]={1};
	int claim[p_num][r_num], allocation[p_num][r_num], need[p_num][r_num];
	int i, j, temp1, temp2, flag1, flag2;
	
	for(j=0; i<r_num; j++)
	{
		printf("\nTotal available instances of resource %d: ",j);
		scanf("%d",&resource[j]);
	}
	
	for(i=0; i<p_num; i++)
	{
		for(j=0; j<r_num; j++)
		{
			printf("\nNumber of instances of resource %d claimed by process %d: ",j, i);
			scanf("%d",&claim[i][j]);
		}
	}
	
	for(i=0; i<p_num; i++)
	{
		for(j=0; j<r_num; j++)
		{
			printf("\nNumber of instances of resource %d allocated to process %d: ",j, i);
			scanf("%d",&allocation[i][j]);
		}
	}


	for(i=0; i<p_num; i++)
	{
		for(j=0; j<r_num; j++)
		{
			need[i][j] = claim[i][j] - allocation[i][j];
		}
	}
	
	for(j=0; j<r_num; j++)
	{
		temp1 = 0;
		for(i=0; i<p_num; i++)
		{
			temp1 = temp1 + claim[i][j];
		}
		if(temp1 < resource[j])
		{
			printf("\nDemand more than resource");
			return(0);
		}
	}
	
	for(j=0; i<r_num; j++)
	{
		temp1 = 0;
		for(i=0; j<p_num; i++)
		{
			temp1 = temp1 + allocation[i][j];
		}

		available[j] = resource[j] - temp1;
	}
	
	flag2 = 1;
	while(flag2==1)
	{
		for(i=0; i<p_num; i++)
		{
			if(done[i]!=1)
			{
				flag1 = 0;
				for(j=0; j<r_num; j++)
				{
					if(need[i][j] > available[j])
					{
						flag1 = 1;
					}
					
				}
	
				if(flag1==0)
				{
					printf("\nProcess %d done", i);
					done[i] = 1;
					flag[i]=1;
					for(j=0;j<r_num;j++)
					{
						available[j] = available[j] + need[i][j];
						need[i][j] = 0;
					}
				}
			}
		}
		
		for(i=0; i<p_num; i++)
		{
			if(done[i]!=1)
			{
				flag1 = 0;
				for(j=0; j<r_num; j++)
				{
					if(need[i][j]>available[j])
					{
						flag1 = 1;
						break;
					}
				}
				
				if(flag1==1)
				{
					flag[i] = 0;
				}
			}
		}
		
		for(i=0;i<p_num;i++)
		{
			temp1=0;
			if(done[i]!=1)
			{
				temp1=temp1+1;
			}
		}
		
		for(i=0;i<p_num;i++)
		{
			temp2=0;
			if(flag[i]!=1)
			{
				temp2=temp2+1;
			}
		}
		
		if(temp1==temp2)
		{
			printf("Deadlock");
			return(0);
		}
		
		for(i=0; i<p_num; i++)
		{
			for(j=0; j<r_num; j++)
			{
				if(need[i][j]==0)
				{
					flag2 = 0;
				}
				
				else
				{
					flag2 = 1;
					break;
				}
			}
			
			if(flag2==1)
			{
				break;
			}
		}
	}
	
	printf("\nProcess Done");
	return(0);
}
