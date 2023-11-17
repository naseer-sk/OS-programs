#include<stdio.h>
int main(){
    int sp,ep,start;
    printf("enter start and end position track number and starting track");
    scanf("%d%d%d",&sp,&ep,&start);
    int i,n;
    printf("enter no.of tracks:");
    scanf("%d",&n);
    int t[n],p[n+2],t1[n],j,k;
    printf("enter track no.s:");
    for(i=0;i<n;i++){
        scanf("%d",&t[i]);
        t1[i]=t[i];
    }
    p[0]=start;
    for(i=0;i<n;i++){
        for(j=0;j<n-i-1;j++){
            if(t1[j+1]<t1[j]){
                int t2=t1[j+1];
                t1[j+1]=t1[j];
                t1[j]=t2;
            }
        }
    }
    int s=0;
    s=s+ep-start;
    s=s+ep-t1[0];
    for(i=0;i<n;i++){
        if(t1[i]>start){
            k=i;
            break;
        }
    }
    int m=1;
    for(i=k;i<n;i++){
        p[m]=t1[i];
        m++;
    }
    p[m]=ep;
    m++;
    for(i=k-1;i>=0;i--){
        p[m]=t1[i];
        m++;
    }
    printf("No.of head movements=%d\n",s);
    printf("sequence of tracks served:");
    for(i=0;i<(n+2);i++){
        printf("%d ",p[i]);
    }
return 0;
}