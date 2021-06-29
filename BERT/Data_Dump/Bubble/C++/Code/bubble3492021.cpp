#include<stdio.h>
#include<iostream>
#include <algorithm>
#include <utility>
using namespace std;

int main()
{
    int N;
    int A[100];
    bool flag = 1;
    int count = 0;
    cin >> N;
    //int a = N-1;
    
    for(int i = 0; i < N; i++){
        cin >> A[i];
        }
        
    while(flag){
        flag = 0;
        for(int j = N-1; j > 0; j--){
            if(A[j] < A[j-1]){
                 swap(A[j],A[j-1]);
                 flag = 1;
                 count++;
            }
        }
    }
    
    for(int i; i < N; i++){
        if(i == N-1){
            printf("%d\n",A[i]);
            }else{
            printf("%d ",A[i]);
            }
    }
    printf("%d\n",count);
    //cout << count << endl;
}
