#include <math.h>
#include <ctype.h>
#include <bits/stdc++.h>
using namespace std;
#define FOR(i, a, n) for (int i = a; i < n; i++)
#define REP(i, n) for(int i = 0; i < n; i++)
struct omt{omt(){ios::sync_with_stdio(false);cin.tie(0);}}star;

int main(){
    int n;
    cin >> n;
    vector<int> A(n);
    for(auto &x : A) cin >> x;

    REP(i, n){
        if(i != n - 1) cout << A[i] << " ";
        else cout << A[i] << endl;
    }
    FOR(i, 1, n){
        if(A[i - 1] > A[i]){
            for(int j = i; j > 0; j--){
                int tmp = A[j];
                if(A[j - 1] > A[j]){
                    A[j] = A[j - 1];
                    A[j - 1] = tmp;
                }else break;
            }
        }
        REP(i, n){
            if(i != n - 1) cout << A[i] << " ";
            else cout << A[i] << endl;
        }
    }


    return 0;
}
