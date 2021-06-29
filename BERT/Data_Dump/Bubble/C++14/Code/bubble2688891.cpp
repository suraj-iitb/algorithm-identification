#include <math.h>
#include <ctype.h>
#include <bits/stdc++.h>
using namespace std;
#define FOR(i, a, n) for (int i = a; i < n; i++)
#define REP(i, n) for(int i = 0; i < n; i++)
struct omt{omt(){ios::sync_with_stdio(false);cin.tie(0);}}star;

bool sortCheck(int n, vector<int> A){
    int f = 1;
    REP(i, n - 1){
        if(A[i] > A[i + 1]){
            f = 0;
            break;
        }
    }
    if(f) return true;
    else return false;
}

int main(){
    int n;
    cin >> n;
    vector<int> A(n);
    for(auto &x : A) cin >> x;

    int cnt = 0, tmp;
    while(1){
        if(sortCheck(n, A)) break;
        else{
            REP(i, n - 1){
                if(A[i] > A[i + 1]){
                    tmp = A[i];
                    A[i] = A[i + 1];
                    A[i + 1] = tmp;
                    cnt++;
                }
            }
        }
    }
    REP(i, n){
        if(i != n - 1) cout << A[i] << " ";
        else cout << A[i] << endl;
    }
    cout << cnt << endl;

    return 0;
}
