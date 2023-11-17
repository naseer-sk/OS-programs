#include<stdio.h>
int main()
{
	int n,m,i,j,sum=0,count=0,esum=0;
	printf("Enter the No.of Process: ");
	scanf("%d",&n);
	int P[n],v1[n];
	printf("\nEnter the Process Sizes: \n");
	for(i=0;i<n;i++)
	{
		scanf("%d",&P[i]);
		v1[i]=0;
	}
	printf("Enter the No.of MemoryBlocks: ");
	scanf("%d",&m);
	int M[m],v[m];
	printf("\nEnter the MemoryBlock Sizes: \n");
	for(i=0;i<m;i++)
	{
		scanf("%d",&M[i]);
		v[i]=0;
	}
	for(i=0;i<n;i++)
	{
		sum=sum+FIRSTFIT(i,m,n,v,v1,P,M);
	}
	printf("\nIntegral Fragmentation is : %d",sum);
	for(j=0;j<m;j++)
	{
		if(v[j]!=1)
		{
			count=count+M[j];
		}
	}
	for(i=0;i<n;i++)
	{
		if(v1[i]!=1 && P[i]<=count)
		{
			if(esum<P[i])
			esum=P[i];
		}
	}
	printf("\nExternal Fragmentation is : %d",esum);
}
int FIRSTFIT(int i,int m,int n,int v[],int v1[],int P[],int M[])
{
	int j,IF=0,flag=0;
	for(j=0;j<m;j++)
	{
		if(M[j]>=P[i] && v[j]!=1)
		{
			v1[i]=1;
			v[j]=1;
			flag=1;
			printf("\nProcess %d is Allocated to MemoryBlock %d:",P[i],M[j]);
			IF=M[j]-P[i];
			break;
		}
	}
	if(flag==0)
	{
		printf("\n MemoryBlock is not allocated to %d Process",P[i]);
	}
	return IF;
}
