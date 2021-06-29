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

int selectionSort(int A[],int N){
    int cnt = 0;
    for(int i = 0;i < N;i++){
        int minj = i;
        for(int j = i; j < N; j++){
            if(A[minj] > A[j]){
                minj = j;
            }
        }
        swap(A[minj], A[i]);
        if(minj != i){
            cnt++;
        }
        
    }
    traceArray(A,N);
    return cnt;
}

int main(){
    int n;
    cin >> n;
    int a[n];
    for(int i = 0; i < n ; i++){
        cin >> a[i];
    }
    int cnt = selectionSort(a,n);
    cout << cnt << endl;
    return 0;
}
