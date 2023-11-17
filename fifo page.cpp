#include <stdio.h>
int main()
{

	int n;
	printf("enter the num of pages:");
	scanf("%d",&n);
	int pages[n];
	printf("enter the pages:");
	for(int i=1;i<=n;i++)
	{
		scanf("%d",&pages[i]);
	}
	printf("enter the num of frames:");
	int m;
	scanf("%d",&m);
	int frame[m];
	for(int i=1;i<=m;i++)
	{
		frame[i]=0;
	}
	int k=0;
	int flag=0;
	int count=0;
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=m;j++)
		{
			flag=0;
			if(frame[j]==0)
			{
				flag=1;
				frame[j]=pages[i];
				
				break;
			}
			if(frame[j]==pages[i])
			{
				flag=1;
				break;
			}
		}
		if(flag==0)
		{
			count++;
			if(k<m)
			{
				k++;
				frame[k]=pages[i];
			
			}
			else
			{
				k=1;
				frame[k]=pages[i];	
			}
		}
	}
	printf("final page elemnts ");
	for(int i=1;i<=m;i++)
	{
		printf("%d ",frame[i]);
	}
	printf("\n");
	printf("no of page faults:%d",(count+m));
	
	
}
