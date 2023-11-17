#include<stdio.h>
void sort(int n,int P[],int AT[],int BT[])
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
			}
		}
	}
}
int swap(int *a,int *b)
{
	int temp=*b;
	*b=*a;
	*a=temp;
}
int findmin(int completion,int n,int AT[],int BT[],int V[])
{
	int i=0,index,flag=0;
	while(AT[i]<=completion && i!=n)
	{
		if(V[i]!=1)
		{
			index=i;
			flag=1;
			break;
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
int main()
{
	int n,i;
	printf("Enter the No.of Processors:\t");
	scanf("%d",&n);
	int P[n],AT[n],BT[n],CT[n],TAT[n],WT[n],V[100];
	printf("Enter the Arrival Times :\n");
	for(i=0;i<n;i++)
	{
		scanf("%d",&AT[i]);
		P[i]=i+1;
		V[i]=0;
	}
	printf("Enter the Burst Times :\n");
	for(i=0;i<n;i++)
	{
		scanf("%d",&BT[i]);
	}
	sort(n,P,AT,BT);
	printf("GHANTTCHART IS: \n");
	printf("|0");
	int completion=0,min;
	int j=0;
	if(AT[0]!=0)
	{
		completion=AT[0];
		printf("|Ideal Time|%d",AT[0]);
	}
	else if(AT[0]==0)
	{
		CT[0]=AT[0]+BT[0];
		TAT[0]=CT[0]-AT[0];
		WT[0]=TAT[0]-BT[0];
		completion=CT[0];
		V[0]=1;
		j++;
		printf("|P%d|%d",P[0],CT[0]);
	}
	while(j<n)
	{
		min=findmin(completion,n,AT,BT,V);
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
	for(i=0;i<n;i++)
	{
		for(j=0;j<n-i-1;j++)
		{
			if(P[j]>P[j+1])
			{
				swap(&P[j],&P[j+1]);
				swap(&AT[j],&AT[j+1]);
				swap(&BT[j],&BT[j+1]);
				swap(&CT[j],&CT[j+1]);
				swap(&TAT[j],&TAT[j+1]);
				swap(&WT[j],&WT[j+1]);
			}
		}
	}
	printf("\n");
	printf("\tPROCESS\tAT\tBT\tCT\tTAT\tWT\n");
	for(i=0;i<n;i++)
	{
		printf("\t%d\t%d\t%d\t%d\t%d\t%d\n",P[i],AT[i],BT[i],CT[i],TAT[i],WT[i]);
	}
	int sum1=0,sum2=0;
	for(i=0;i<n;i++)
	{
		sum1=sum1+TAT[i];
		sum2=sum2+WT[i];
	}
	float TATavg=(float)sum1/(float)n;
	float WTavg=(float)sum2/(float)n;
	printf("\nAverage Turn Around Time is: %.2f",TATavg);
	printf("\nAverage Waiting Time is: %.2f",WTavg);
}

