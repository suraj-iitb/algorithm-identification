#include<iostream>
#include<algorithm>
using namespace std;

void traceArray(int A[],int N){
    for(int i = 0; i < N; i++){
        if(i > 0){
            cout << " ";
        }
        cout << A[i];
    }
    cout << endl;
}

int bubbleSort(int A[],int N){
    int cnt = 0;
    for(int i = 0; i< N; i++){
        for(int j = N-1; j >= i+1; j--){
            if(A[j] < A[j-1]){
                swap(A[j],A[j-1]);
                cnt++;
            }
        }
    }
    traceArray(A,N);
    return cnt;
}

int main(){
    int n;
    cin >> n;
    int a[n];
    for(int i = 0; i < n; i++){
        cin>>a[i];
    }
    int cnt = bubbleSort(a,n);
    cout << cnt << endl;
    return 0;
}
