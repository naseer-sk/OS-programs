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
        //m2[i]=m1[i];
    }
    for(i=0;i<n-1;i++){
        for(j=0;j<n-i-1;j++){
            if(p[j+1]<p[j]){
                int t=p[j+1];
                p[j+1]=p[j];
                p[j]=t;
            }
        }
    }
    for(i=0;i<m-1;i++){
        for(j=0;j<m-i-1;j++){
            if(m1[j+1]>m1[j]){
                int t=m1[j+1];
                m1[j+1]=m1[j];
                m1[j]=t;
            }
        }}
    
    for(i=0;i<m;i++){
        m2[i]=m1[i];
    }
    for(i=0;i<n;i++){
        int f=0;
        for(j=0;j<m;j++){
            if(p[i]<=m1[j]){
                m1[j]=m1[j]-p[i];
                f=1;
                printf("process %d in memory block %d\n",p[i],m2[j]);
                p[i]=0;
                break;
            }
        }
        if(f==0){
            printf("process %d is not fitted in any block\n",p[i]);
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
    else if(ps<=ef){
        printf("EXTERNAL FRAGMENTATION\n");
    }
    else{
        printf("NO EXTERNAL FRAGMENTATION\n");
    }
    printf("NO INTERNAL FRAGMENTATION");
return 0;
}