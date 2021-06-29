#include <vector>
#include <algorithm>
#include <utility>
#include <iostream>
#include<stdio.h>
 
using namespace std;

void trace(int A[], int N){
    for(int i=0;i<N;++i){
        if(i<N-1){
        cout << A[i] << " ";
    }
    else{
        cout << A[i] << endl;
    }
    }
} 

void insert(int A[], int N){
    int j=0,i=0,v=0;
    for(int i=1;i<N;++i){
        v = A[i];
        j = i-1;
        while(j>=0 && A[j]>v){
            A[j+1]=A[j];
            --j;
        }
        A[j+1]=v;
        trace(A,N);
    }
}

int main(){
    int   N;
    cin >> N;
    int A[N];
    for(int i=0;i<N;++i){
        cin >> A[i];
    }
    int v=0;
    int j=0;

    trace(A,N);
    insert(A,N);

    return 0;
}
