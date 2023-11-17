#include<stdio.h>
#include<stdlib.h>

int main()
{
    int n;
    printf("Enter n=");
    scanf("%d",&n);
    int p;
    printf("Enter p=");
    scanf("%d",&p);
    int l=n+3;
    int arr[l];
    arr[0]=0;
    arr[1]=p;
    arr[2]=199;
    printf("Enter sequence=");
    for(int i=3;i<l;i++){
        scanf("%d",&arr[i]);
    }
    for(int i=0;i<l-1;i++){
        for(int j=i+1;j<l;j++){
            if(arr[i]>arr[j]){
                int temp=arr[i];
                arr[i]=arr[j];
                arr[j]=temp;
            }
        }
    }
        int q;
        for(int i=0;i<l;i++){
            if(arr[i]==p){
                q=i;
                break;
            }
        }
        int sum1=0;
        int sum2=0;
        sum1+=abs(arr[q]-arr[l-2]);
        sum1+=abs(arr[l-2]-arr[1]);
        printf("\nThe head= %d",sum1);
        printf("\n");
        for(int i=q+1;i<l-1;i++){
            printf("%d ",arr[i]);
        }
        for(int i=q-1;i>0;i--){
            printf("%d ",arr[i]);
        }

    
    return 0;
}