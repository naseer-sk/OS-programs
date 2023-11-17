#include<stdio.h>
void sort(int n,int P[],int AT[],int BT[],int PR[])
{
	int i,j;
	for(i=0;i<n;i++)
	{
		for(j=0;j<n-i-1;j++)
		{
			if(AT[j]>AT[j+1])
			{
				swap(&P[j],&P[j+1]);
				swap(&AT[j],&AT[j+1]);
				swap(&BT[j],&BT[j+1]);
				swap(&PR[j],&PR[j+1]);
			}
		}
	}
}
int findmin(int completion,int n,int AT[],int BT[],int PR[],int V[])
{
	int i=0,min=999,index,flag=0;
	while(AT[i]<=completion && i!=n)
	{
		if(V[i]!=1 && PR[i]<min)
		{
			min=PR[i];
			index=i;
			flag=1;
		}
		i++;
	}
	if(flag==0)
	{
		return -1;
	}
	else
	{
		return index;
	}
}

int swap(int *a,int *b)
{
	int temp=*a;
	*a=*b;
	*b=temp;
}
int main()
{
	int n,i;
	printf("Enter the No.of Processes: \t");
	scanf("%d",&n);
	int P[n],AT[n],BT[n],PR[n],CT[n],TAT[n],WT[n],V[100];
	printf("Enter the Arrival Times:  ");
	for(i=0;i<n;i++)
	{
		scanf("%d",&AT[i]);
		P[i]=i+1;
	}
	printf("Enter the Burst Times:  ");
	for(i=0;i<n;i++)
	{
		scanf("%d",&BT[i]);
	}
	printf("Enter the Priorities: ");
	for(i=0;i<n;i++)
	{
		scanf("%d",&PR[i]);
	}
	sort(n,P,AT,BT,PR);
	printf("GHANTTCHART IS: \n");
	printf("|0");
	int completion=0,min;
	int j=0;
	while(j<n)
	{
		min=findmin(completion,n,AT,BT,PR,V);
		if(min!=-1)
		{
			CT[min]=completion+BT[min];
			TAT[min]=CT[min]-AT[min];
			WT[min]=TAT[min]-BT[min];
			V[min]=1;
			completion=CT[min];
			printf("|P%d|%d",P[min],CT[min]);
			j=j+1;
		}
		else
		{
			completion=completion+1;
			printf("|IdealCase|%d",completion);
		}
	}
	printf("\n\tPID\tAT\tBT\tPR\tCT\tTAT\tWT");
	printf("\n");
	for(i=0;i<n;i++)
	{
		printf("\t%d\t%d\t%d\t%d\t%d\t%d\t%d",P[i],AT[i],BT[i],PR[i],CT[i],TAT[i],WT[i]);
		printf("\n");
	}
	int TATsum=0,WTsum=0;
	for(i=0;i<n;i++)
	{
		TATsum=TATsum+TAT[i];
		WTsum=WTsum+WT[i];
	}
	float TATavg=(float)TATsum/(float)n;
	float WTavg=(float)WTsum/(float)n;
	printf("\n TURN AROUND TIME AVERGE IS :\t%.2f",TATavg);
	printf("\n WAITING TIME AVERGE IS     :\t%.2f",WTavg);
}
