#include <iostream>
#include <stdio.h>
#include <string>
using namespace std;


int bubbleSort(int A[],int N){
    int count = 0;
    bool flag = 1;
    for(int i = 0;flag;i++){
        flag = 0;
        for(int j = N-1;j>=i+1;j--){
            if(A[j] < A[j-1]){
                int tmp = 0;
                tmp = A[j];
                A[j] = A[j-1];
                A[j-1] = tmp;
                flag = 1;
                count++;
            }
        }
    }
    return count;
}
int main(void){
    int A[100];
    int N,sw;
    cin >> N;
    for(int i = 0;i<N;i++) cin >> A[i];
    
    sw = bubbleSort(A,N);
    
    for(int i = 0;i<N;i++){
        if(i) cout << " ";
        cout << A[i];
    }
    cout << endl;
    cout << sw << endl;
    return 0;
    
}

