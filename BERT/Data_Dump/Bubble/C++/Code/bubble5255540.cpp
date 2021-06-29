#include<iostream>
using namespace std;

int main(){
    int N, i, j, k;
    int cnt = 0;
    int A[100];
    cin >> N;
    for(i=0; i<N; i++){
        cin >> j;
        A[i] = j;
    }

    int flag = 1;
    while (flag){
        flag = 0;
        for(j=N-1; j>0; j--){
            if(A[j] < A[j-1]){
                cnt++;
                flag = 1;
                k = A[j];
                A[j] = A[j-1];
                A[j-1] = k;
            }
        }
    }

    for(i=0; i<N; i++){
        if(i == N-1) cout << A[i] << endl;
        else cout << A[i] << " ";
    }
    cout << cnt << endl;

}
