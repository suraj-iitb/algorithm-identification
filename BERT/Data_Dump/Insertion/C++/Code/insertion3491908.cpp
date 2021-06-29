#include<stdio.h>
#include<iostream>
using namespace std;

int main()
{
    int N;
    int A[100];
    cin >> N;
    
    for(int i = 0; i < N; i++){
        cin >> A[i];
        }
        
    for(int i = 0;i < N; i++){
        if(i == N-1){
            printf("%d\n",A[i]);
            }else{
                printf("%d ",A[i]);
            }
    }

    for(int i = 1; i < N; i++){
        int v = A[i];
        int j;
        j = i-1;
        while(j >= 0 && A[j] > v){
            A[j+1] = A[j];
            j--;
        }
        A[j+1] = v;
        for(int a = 0; a < N; a++){
            if(a == N-1){
            printf("%d\n",A[a]);
            }else{
                printf("%d ",A[a]);
            }
        }
    }
}
