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



int BubbleSort(int A[],int N){
    bool flag = true;
    int cnt = 0;
    while(flag){
        flag = false;
        for (int i = N-1; i >0; --i)
        {
            if(A[i] < A[i-1]){
                swap(A[i],A[i-1]);
                flag = true;
                cnt++;
            }
        }
    }
    return cnt;
}

int main(){
    int N; cin >> N;
    int A[N]; rep(i,N) cin >> A[i];
    int ans = BubbleSort(A,N);
    trace(A,N);
    cout << ans << endl;
    return 0;
}
