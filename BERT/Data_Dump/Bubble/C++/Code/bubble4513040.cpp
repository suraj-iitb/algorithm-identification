#include <bits/stdc++.h>
#define rep(i, a) for (ll i = 0; i < (a); ++i)
#define pb push_back
#define all(v) v.begin(),v.end()
#define sort_1(v) sort(v.begin(),v.end())
#define sort_2(v) sort(v.begin(),v.end(),greater<ll>())
#define reverse(v) reverse(v.begin(),v.end())
typedef long long ll;
typedef long double la;
using namespace std;

int ct = 0;

void bubbleSort(int A[], int N){
    bool flag = 1;
    while(flag){
        flag = 0;
        for(int i=N-1;i>=1;i--){
            if(A[i] < A[i-1]){
                swap(A[i],A[i-1]);
                ct++;
                flag = 1;
            }
        }
    }
}

int main(){
    int n;
    cin >> n;
    int a[n];
    rep(i,n) cin >> a[i];
    bubbleSort(a,n);
    rep(i,n){
        if(i == n-1){
            cout << a[i];
        }else{
            cout << a[i] << ' ';    
        }
    }
    cout << endl;
    cout << ct << endl;

}
