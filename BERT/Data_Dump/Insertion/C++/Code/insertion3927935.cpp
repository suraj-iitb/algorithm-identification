#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for(int i = 0; i < (int)(n); i++)
#define REP(i, n) for(int i = 1; i <= (int)(n); i++)
const long long INF = 1LL << 60;

void trace(int A[],int N){
    int i;
    for(int i=0;i<N;i++){
        if(i>0){
            cout << " ";
        }
        cout << A[i];
    }
    cout << endl;
}

void insertionSort(int A[],int N){
    int i, j, v;
    for(i=1;i<N;i++){
        v= A[i];
        j=i-1;
        while(j>=0 && A[j] > v ){
            A[j+1]=A[j];
            j--;
        }
        A[j+1]=v;
        trace(A,N);
    }

}
int main(){
    int n;
    cin >> n;

    int A[n];
    rep(i,n){
        cin >> A[i];
    }

    trace(A,n);
    insertionSort(A,n);

    return 0;


}
