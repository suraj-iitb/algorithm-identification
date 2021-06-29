#include<iostream>
using namespace std;

int main(){
    int N, i, minj, a, cnt;
    cin >> N;
    int A[100];
    cnt = 0;

    for(i=0; i<N; i++){
        cin >> a;
        A[i] = a;
    }

    for(i=0; i<N; i++){
        minj = i;
        for(int j=i; j<N; j++){
            if(A[j] < A[minj]) minj = j;
        }
        if(A[i] > A[minj]){
            a = A[i];
            A[i] = A[minj];
            A[minj] = a;
            cnt++;
        }

    }

    for(i=0; i<N; i++){
        if(i == N-1) cout << A[i] << endl;
        else cout << A[i] << " ";
    }
    cout << cnt << endl;
}
