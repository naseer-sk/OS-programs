#include <stdio.h>
#include <stdlib.h>

struct process
{
    int pid;
    int at;
    int bt;
    int pri;
    int ct;
    int tat;
    int st;
    int rt;
    int wt;
};

int main()
{
    struct process p[40];
    int n;
    int total_tat;
    int total_wt;
    int total_rt;
    int total_ideal;

    float avg_tat;
    float avg_wt;
    int bt_remain[40];
    printf("Enter n=");
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
    {
        printf("Enter AT %d=", i + 1);
        scanf("%d", &p[i].at);
        printf("Enter BT %d=", i + 1);
        scanf("%d", &p[i].bt);
        bt_remain[i] = p[i].bt;
        printf("Enter PRI %d=", i + 1);
        scanf("%d", &p[i].pri);
        p[i].pid = i + 1;
    }
    int is_completed[40];
    for (int i = 0; i < n; i++)
    {
        is_completed[i] = 0;
    }
    int completed = 0;
    int curr_time = 0;
    int prev = 0;
    while (completed != n)
    {
        int idx = -1;
        int mn = 9999;
        for (int i = 0; i < n; i++)
        {
            if (p[i].at <= curr_time && is_completed[i] == 0)
            {
                if (p[i].pri < mn)
                {
                    mn = p[i].pri;
                    idx = i;
                }
                if (p[i].pri == mn)
                {
                    if (p[i].at <= p[idx].at)
                    {
                        mn = p[i].pri;
                        idx = i;
                    }
                }
            }
        }
        if (idx != -1)
        {
            if(p[idx].bt==bt_remain[idx]){
                p[idx].st=curr_time;
                total_ideal=total_ideal+(p[idx].st-prev);
            }
            bt_remain[idx]-=1;
            curr_time++;
            prev=curr_time;
            if(bt_remain[idx]==0){
                p[idx].ct=curr_time;
                p[idx].tat=p[idx].ct-p[idx].at;
                p[idx].wt=p[idx].tat-p[idx].bt;
                p[idx].rt=p[idx].st-p[idx].at;
                is_completed[idx]=1;
                completed++;
                printf(" P[%d] ",p[idx].pid);
            }
        }
        else{
            curr_time++;
        }
    }
      printf("\nPID\tAT\tBT\tCT\tPRI\tTAT\tST\tWT\n");
    for(int i=0;i<n;i++){
        printf("%d\t%d\t%d\t%d\t%d\t%d\t%d\t%d\n",p[i].pid,p[i].at,p[i].bt,p[i].ct,p[i].pri,p[i].tat,p[i].st,p[i].wt);
    }

    return 0;
}