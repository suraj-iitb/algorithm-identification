#include <stdio.h>
void bubbleSort(int[],int);
int main()
{
    int N;
    int arr[101];
    scanf("%d",&N);
    for(int i=0;i<N;i++){
        scanf("%d",&arr[i]);
    }
    bubbleSort(arr,N);
    return 0;
}
void bubbleSort(int arr[],int N)
{   
    int count=0;
    bool flag = 1;
    while(flag){
        flag = 0;
        for(int i=N-1;i>0;i--){
            if(arr[i]<arr[i-1]){
                int hoge;
                hoge=arr[i];
                arr[i]=arr[i-1];
                arr[i-1]=hoge;
                flag = 1;
                count++;
            }
        }
    }
    for(int j=0;j<N;j++){
        if(j>0) printf(" ");
        printf("%d",arr[j]);
    }
    printf("\n%d\n",count);
    return;
}
