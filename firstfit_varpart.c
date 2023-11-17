#include<stdio.h>
int main(){
    int n,m,i,j;
    printf("enter no.of processes and no.of memory blocks:");
    scanf("%d%d",&n,&m);
    int m1[m],m2[m],p[n];
    printf("enter processes:");
    for(i=0;i<n;i++){
        scanf("%d",&p[i]);
    }
    printf("enter memory block sizes:");
    for(i=0;i<m;i++){
        scanf("%d",&m1[i]);
        m2[i]=m1[i];
    }
    for(i=0;i<n;i++){
        int f=0;
        for(j=0;j<m;j++){
            if(p[i]<=m1[j]){
                m1[j]=m1[j]-p[i];
                f=1;
                printf("process %d in memory block %d\n",i+1,m2[j]);
                p[i]=0;
                break;
            }
        }
        if(f==0){
            printf("process %d is not fitted in any block\n",i+1);
        }
    }
    int ef=0;
    for(i=0;i<m;i++){
        if(m1[i]==m2[i]){
            ef=ef+m1[i];
        }
    }
    int ps=0;
    for(i=0;i<n;i++){
        ps=ps+p[i];
    }
    if(ps==0){
        printf("NO EXTERNAL FRAGMENTATION\n");
    }
    if(ps<=ef){
        printf("EXTERNAL FRAGMENTATION\n");
    }
    else{
        printf("NO EXTERNAL FRAGMENTATION\n");
    }
    printf("NO INTERNAL FRAGMENTATION");
return 0;
}