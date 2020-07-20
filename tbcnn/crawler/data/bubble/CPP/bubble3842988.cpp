#include <bits/stdc++.h>
using namespace std;

int bubbleSort(int A[],int N){
    int so = 0;
    bool gh = 1;
    for(int i = 0;gh;i++){
        gh = 0;
        for(int j = N-1;j >= i + 1;j--){
            if(A[j] < A[j - 1]){
                swap(A[j],A[j - 1]);
                gh = 1;
                so++;
            }
        }
    }
    return so;
} 

int main(){
    int A[100],N,so;
    cin >> N;
    for(int i = 0;i < N;i++)cin >> A[i];
    so = bubbleSort(A,N);
    for(int i = 0;i < N;i++){
        if(i)cout << " ";
        cout << A[i];
    }
    cout << endl;
    cout << so << endl;
}
