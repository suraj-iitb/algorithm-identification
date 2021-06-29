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



int SelectionSort(int A[],int N){
    int cnt = 0;
    rep(i,N){
        int minj = i;
        for (int j = i; j < N; j++)
        {
            if(A[minj] > A[j]) minj = j;
        }
        if(i != minj){
            swap(A[i],A[minj]);
            cnt++;
        }
    }
    return cnt;
}

int main(){
    int N; cin >> N;
    int A[N]; rep(i,N) cin >> A[i];
    
    int ans = SelectionSort(A,N);
    trace(A,N);
    cout << ans << endl;
    return 0;
}
