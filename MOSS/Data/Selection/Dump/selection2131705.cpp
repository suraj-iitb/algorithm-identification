#include<iostream>
using namespace std;

int main(void){
    int i, j, N, A[100], minj, cnt=0;
    cin >> N;
    for (i=0; i<N; i++) cin >> A[i];
    for (i=0; i<N-1; i++){
        minj = i;
        for(j=i+1; j<N; j++){
            if(A[j] < A[minj]){
                minj = j; 
            }
        }
        if(minj!=i){
            cnt++;
            swap(A[i], A[minj]);
        }

    }
    for(i=0; i<N; i++){
        if(i) cout << " ";
        cout << A[i];
    }
    cout << endl;
    cout << cnt << endl;
    return 0;
}
