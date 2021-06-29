#include <iostream>
#include <stdio.h>
using namespace std;

int insertionSort(int A[], int N, int count){
    int flag = 1;
    while(flag == 1){
        flag = 0;
        for(int j = N - 1; j >= 1; j--){
            if(A[j] < A[j-1]){
                int a = A[j];
                A[j] = A[j-1];
                A[j-1] = a;
                flag = 1;
                count++;
            }
        }
    }
    return count;
}

int main(){
    int N;
    cin >> N;
    int A[N];
    for(int i = 0; i < N; i++){
        cin >> A[i];
    }
    
    int count = 0;
    int ans = insertionSort(A, N, count);
    for(int i = 0; i < N; i++){
        if(i > 0) cout << " ";
        cout << A[i];
    }
    cout << endl;
    cout << ans << endl;
    
    return 0;
}
