#include <stdio.h>
int main()
{
	int n;
	printf("enter the num of processors:");
	scanf("%d",&n);
	int p[n];
	int visit[n];
	int m;
	printf("eneter the num of resources:");
	scanf("%d",&m);
	for(int i=0;i<n;i++)
	{
		p[i]=i;
		visit[i]=0;
	}
	printf("eneter the allocation values:");
	int all[n][m];//n rows m columns
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<m;j++)
		{
			scanf("%d",&all[i][j]);
		}
		
	}
	printf("eneter the max need values:");
	int maxneed[n][m];
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<m;j++)
		{
			scanf("%d",&maxneed[i][j]);
		}
		
	}
	printf("enter the total available:");
	int k=0;//0 rows
	int totava[k][m];
	for(int i=0;i<=k;i++)
	{
		for(int j=0;j<m;j++)
		{
			scanf("%d",&totava[i][j]);
		}
	}
	printf("the remaining need is maxneed - allocation:");
	int remneed[n][m];
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<m;j++)
		{
			remneed[i][j]=maxneed[i][j]-all[i][j];
			printf("%d",remneed[i][j]);
		}
		printf("\n");
	}
	printf("comparing n allocating the resources:");
	int f=0,l=0;
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<m;j++)
		{
			if(remneed[i][j]<=totava[k][j] && visit[i]==0)
			{
				f=1;
			}
			else
			{
				f=0;
				break;
			}
		}
		if(f==1)
		{
			int t;
			visit[i]=1;
			p[l]=i;
			l++;
			for(t=0;t<m;t++)
			{
				totava[k][t]=totava[k][t]+all[i][t];
				
			}
			f=0;
		}
		if(i==n-1 && l<n)
		{
			i=-1;
		}
	}
	printf("the processor sequences is:");
	for(int i=0;i<n;i++)
	{
		printf("[p%d]-->-",p[i]);
	}
}
