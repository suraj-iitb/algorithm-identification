#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for(int i = 0; i < (int)(n); i++)
#define REP(i, n) for(int i = 1; i <= (int)(n); i++)
const long long INF = 1LL << 60;

int selectionSort(int A[],int N){
    int minj,cnt=0;
    for(int i=0;i<N;i++){
        minj=i;
        for(int j=i;j<N;j++){
            if(A[minj]>A[j]){
                minj=j;
            }
        }
      	if(A[i] != A[minj]){
        	swap(A[i],A[minj]);
          	cnt++;
        }
    }
    return cnt;
}

int main() 
{
    int n,res;
    cin >> n;
    int A[n];
    rep(i,n){
        cin >> A[i];
    }

    res = selectionSort(A,n);

    rep(i,n){
        if(i){
            cout << " ";
        }
        cout << A[i];
    }
    cout << endl << res << endl;
}

