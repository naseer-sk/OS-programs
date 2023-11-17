#include <stdio.h>
int main()
{
	int n;
	printf("eneter the num of page num :");
	scanf("%d",&n);
	int pages[n];
	printf("enter the pages:");
	for(int i=1;i<=n;i++)
	{
		scanf("%d",&pages[i]);
	}
	int m;
	printf("enter the num of frames:");
	scanf("%d",&m);
	int frames[m];
	for(int i=1;i<=m;i++)
	{
		frames[i]=-1;
	}
	int flag=0;
	int count=0;
//	int min=999;
	int res=-1;
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=m;j++)
		{
			flag=0;
			if(frames[j]==pages[i])
			{
				flag=1;
				break;
			}
			if(frames[j]==-1)
			{
				flag=1;
				frames[j]=pages[i];
				break;
			}
		}
		if(flag==0)
		{
			count++;
			int min=999;
			for(int j=1;j<=m;j++)
			{
				for(int k=i-1;k>=1;k--)
				{
					if(frames[j]==pages[k])
					{
						if(min>k)
						{
							min=k;
							res=j;
						}
						break;
					}
					
				}
			}
			frames[res]=pages[i];
			
		}
	}
	printf("the final sequence is:");
		for(int i=1;i<=m;i++)
		{
			printf("%d",frames[i]);
		}
		printf("the pages fault is%d\n",(count+m));
		printf("num of replacemens:%d",count);
}
