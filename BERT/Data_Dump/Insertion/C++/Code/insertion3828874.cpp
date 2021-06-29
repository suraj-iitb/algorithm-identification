#include<bits/stdc++.h>
typedef long long ll;
#define rep(i,n) for(int i = 0; i < (n); ++i)
#define sz(x) int(x.size())
#define MOD 1000000007
using namespace std;

void trace(int A[],int N){
    rep(i,N-1) cout << A[i] << " ";
    cout << A[N-1] << endl;
}

void InsertionSort(int A[],int N){
    for (int i = 1; i < N; i++)
    {
        int temp = A[i];
        int j = i-1;
        while(j >= 0 && A[j] > temp){
            A[j+1] = A[j];
            j--;
        }
        A[j+1] = temp;
        trace(A,N);
    }
}
int main(){
    int N; cin >> N;
    int A[N]; rep(i,N) cin >> A[i];
    trace(A,N);
    InsertionSort(A,N);
    return 0;
}
