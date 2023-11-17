#include<stdio.h>
int main(){
    int sp,ep,start;
    printf("enter start and end position track number and starting track");
    scanf("%d%d%d",&sp,&ep,&start);
    int i,n;
    printf("enter no.of tracks:");
    scanf("%d",&n);
    int t[n];
    printf("enter track no.s:");
    for(i=0;i<n;i++){
        scanf("%d",&t[i]);
    }
    int s=0;
    if(start<=t[0]){
        s=s+t[0]-start;
    }
    else{
        s=s+start-t[0];
    }
    for(i=0;i<n-1;i++){
        if(t[i+1]>=t[i]){
            s=s+t[i+1]-t[i];
        }
        else{
            s=s+t[i]-t[i+1];
        }
    }
    printf("No.of head movements=%d\n",s);
    printf("sequence of tracks served:");
    for(i=0;i<n;i++){
        printf("%d ",t[i]);
    }
return 0;
}