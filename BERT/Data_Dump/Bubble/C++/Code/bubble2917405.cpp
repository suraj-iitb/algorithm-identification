#include<stdio.h>
#include<iostream>

#define MAX_N 105

using namespace std;

int BubbleSort(int arr[], int N){
    int swapNum=0;
    for(int i=0; i<N-1; i++){
        for(int j=N-1; j>=i+1; j--){
            if(arr[j]<arr[j-1]){
                swap(arr[j], arr[j-1]);
                swapNum++;
            }
        }
    }
    return swapNum;
}

int main(){
    int arr[MAX_N];
    int N;
    scanf("%d", &N);
    for(int i=0; i<N; i++)
        scanf("%d", arr+i);
    int res=BubbleSort(arr, N);
    printf("%d", arr[0]);
    for(int i=1; i<N; i++)
        printf(" %d", arr[i]);
    printf("\n");
    printf("%d\n", res);
    return 0;
}


