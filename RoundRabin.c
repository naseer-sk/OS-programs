#include<stdio.h>
struct Process
{
	int ID;
	int AT;
	int BT;
	int Status;
	int CT;
	int BT2;
	int TAT;
	int WT;
};
int Front=-1,Rear=-1;
int QArray[100];
void enqueue(int temp)
{
	if(Front==-1)
	{
		Front=0;
		Rear=Rear+1;
	}
	else
	{
		Rear++;
	}
	QArray[Rear]=temp;
}
void dequeue()
{
	if(Front==Rear)
	{
		Front=-1;
		Rear=-1;
	}
	else
	{
		Front++;
	}
}


struct Process Array[100];
void TakeInput(int n)
{
	int i=0;
	printf("\nEnter the process ids:");
	for(i=0;i<n;i++)
	{
		scanf("%d",&Array[i].ID);
	}
	printf("\nEnter the process ATs':");
	for(i=0;i<n;i++)
	{
		scanf("%d",&Array[i].AT);
	}
	printf("\nEnter the process BTs:");
	for(i=0;i<n;i++)
	{
		scanf("%d",&Array[i].BT);
	}
	for(i=0;i<n;i++)
	{
		Array[i].Status=0;
	}
	for(i=0;i<n;i++)
	{
		Array[i].BT2=Array[i].BT;
	}
}
void PrintInput(int n)
{
	int i=0;
	printf("Pid\tAT\tBT\n");
	for(i=0;i<n;i++)
	{
		printf("P%d\t%d\t%d\t\n",Array[i].ID,Array[i].AT,Array[i].BT);
	}
}
void PrintOut(int n)
{
	int i=0;
	for(i=0;i<n;i++)
	{
		Array[i].BT=Array[i].BT2;
		Array[i].TAT=Array[i].CT-Array[i].AT;
		Array[i].WT=Array[i].TAT-Array[i].BT;
	}
	float ATAT=0,AWT=0,p=n;
	printf("\n\nPid\tAT\tBT\tCT\tTAT\tWT\n");
	for(i=0;i<n;i++)
	{
		printf("P%d\t%d\t%d\t%d\t%d\t%d\n",Array[i].ID,Array[i].AT,Array[i].BT,Array[i].CT,Array[i].TAT,Array[i].WT);
	}
	for(i=0;i<n;i++)
	{
		ATAT=ATAT+Array[i].TAT;
		AWT=AWT+Array[i].WT;
	}
	printf("\n Average Turn Around time is %.2f",ATAT/p);
	printf("\n Average Waiting time is %.2f",AWT/p);
}
void SortInput(int n)
{
	int i,j;
	for(i=0;i<n-1;i++)
	{
		for(j=0;j<n-i-1;j++)
		{
			if(Array[j].AT>Array[j+1].AT)
			{
				int temp=Array[j].BT;
				Array[j].BT=Array[j+1].BT;
				Array[j+1].BT=temp;
				temp=Array[j].AT;
				Array[j].AT=Array[j+1].AT;
				Array[j+1].AT=temp;
				temp=Array[j].ID;
				Array[j].ID=Array[j+1].ID;
				Array[j+1].ID=temp;
				temp=Array[j].BT2;
				Array[j].BT2=Array[j+1].BT2;
				Array[j+1].BT2=temp;
			}
			
		}
	}
}
void main()
{
	int n,q;
	printf("Enter the no.of processes :");
	scanf("%d",&n);
	printf("Enter the Quantum Number :");
	scanf("%d",&q);
	TakeInput(n);
	SortInput(n);
	PrintInput(n);
	enqueue(0);
	Array[0].Status=1;
	int T=Array[0].AT;
	int PastCount=0,PastIndex,i,Final=0,Ideal=0;
	//Statring of the main loop
	printf("\nGantt Chart : ");
	printf("%d",0);
	if(T!=0)
	{
		printf("[Ideal]%d",T);
	}
	while(Final!=n)
	{
		
		for(i=0;i<n;i++)
		{	
			if(T>=Array[i].AT && Array[i].Status==0)
			{
				enqueue(i);
				Array[i].Status=1;
			}
			else if( Array[i].Status==0)
			{
				if(Front==-1 && Rear==-1 && PastCount==0)
				{
					enqueue(i);
					Array[i].Status=1;
					T=Array[i].AT;
					printf("[Ideal]%d",T);
					break;
				}
				else
				{
					break;
				}
			}
		}
		if(PastCount==1)  
		{
			enqueue(PastIndex);
		}
		//printf("\n the emelents in Queue at %d : ",T);
		//for(i=Front ;i<=Rear;i++)
		//	printf("%d ",QArray[i]);
		if(Array[QArray[Front]].BT>q)
		{
			T=T+q;
			Array[QArray[Front]].BT=Array[QArray[Front]].BT-q;
			if(Array[QArray[Front]].BT!=0)
			{
			
				PastCount=1;
				PastIndex=QArray[Front];
			}
			printf("[P%d]%d",Array[QArray[Front]].ID,T);
				dequeue();
			
		}
		else
		{
			T=Array[QArray[Front]].BT+T;
			Array[QArray[Front]].BT=0;
			PastCount=0;
			Array[QArray[Front]].CT=T;
			Final++;
			printf("[P%d]%d",Array[QArray[Front]].ID,T);
			dequeue();
		}
	}	
	//ending of the main looop
	PrintOut(n);
}
