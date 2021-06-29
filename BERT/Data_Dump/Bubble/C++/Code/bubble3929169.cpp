#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for(int i = 0; i < (int)(n); i++)
#define REP(i, n) for(int i = 1; i <= (int)(n); i++)
const long long INF = 1LL << 60;

void bubbleSort(int A[],int N){
    bool flag = 1;
    int cnt = 0;
    while(flag){
        flag=0;
        for(int j=N-1;j>0;j--){
            if(A[j]<A[j-1]){
                swap(A[j],A[j-1]);
                flag = 1;
                cnt++;
            }
        }
    }
    rep(i,N){
        if(i > 0){
            cout << " ";
        }
        cout << A[i];
    }
    cout << endl << cnt << endl;


}

int main()
 {
    int n;
    cin >> n;
    int A[n];
    rep(i,n){
        cin >> A[i];
    }
    bubbleSort(A,n);

}

