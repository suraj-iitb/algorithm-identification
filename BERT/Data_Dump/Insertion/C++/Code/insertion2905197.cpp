#include<stdio.h>
#include<iostream>

#define MAX_N 105

using namespace std;

int arr[MAX_N];

int main(){
    int N;
    scanf("%d", &N);
    for(int i=0; i<N; i++)
        scanf("%d", arr+i);
    for(int j=0; j<N; j++){
        int i, temp;
        for(i=j-1; i>=0; i--){
            if(arr[j]>=arr[i])
                break;
        }
        temp = arr[j];
        for(int cur=j; cur>i+1; cur--)
            arr[cur] = arr[cur-1];
        arr[i+1] = temp;
        //print
        printf("%d", arr[0]);
        for(int cur=1; cur<N; cur++)
            printf(" %d", arr[cur]);
        printf("\n");
    }
    return 0;
}

