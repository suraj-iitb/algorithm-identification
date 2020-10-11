#include <stdio.h>

void bubbleSort(int num[],int n){
    int flag=1,j,tmp,count=0;
    while(flag){
        flag=0;
        for(j=n-1;j>0;j--){
            if(num[j]<num[j-1]){
                tmp=num[j];
                num[j]=num[j-1];
                num[j-1]=tmp;
                count++;
                flag=1;
            }
        }
    }
    for(j=0;j<n;j++){
        printf("%d%s",num[j],(j==n-1?"\n":" "));
    }
    printf("%d\n",count);
} 

int main(void){
    int num[101];
    int n,i;
    scanf("%d",&n);
    for(i=0;i<n;i++){
        scanf("%d",&num[i]);
    }
    bubbleSort(num,n);
    return 0;
}

