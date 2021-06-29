#include <iostream>
#include <algorithm>
using namespace std;

static const int MAX = 1000;

void trace(int A[], int N){
    int i;
    for (i=0;i<N;i++){
        if(i>0) cout << " ";
        cout << A[i];
    }
    cout << endl;
}

void bubbleSort(int A[],int N){
    int flag = 1;
    int v0;
    int cnt = 0;
    while (flag == 1){
        flag = 0;
        for (int j=N-1;j>=1;j--){
            if(A[j] < A[j-1]){
                v0 = A[j-1];
                A[j-1] = A[j];
                A[j] = v0;
                flag = 1;
                cnt ++;
            }
        }
    }
    trace(A,N);
    cout << cnt << endl;;
}

int main(){
    int n, A[MAX];
    cin >> n;
    for (int i=0;i<n;i++) cin >> A[i];
    bubbleSort(A,n);
    return 0;
}

