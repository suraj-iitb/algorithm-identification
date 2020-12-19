#include<stdio.h>
#include<iostream>
#include<list>
#include<map>
#include<math.h>
#include<vector>
#include<algorithm>
#include<string.h>
#include<iomanip>
#define range(i,a,b) for(int i = (a); i < (b); i++)
#define rep(i,b) range(i,0,b)
#define debug(x) cout << "debug" << x << endl;
using namespace std;

int main(){
    int n;
    while(cin >> n){
        int A[101];
        rep(i, n){
            cin >> A[i];
        }
        int ans = 0;
        bool flag = true;
        while(flag){
            flag = false;
            for(int j = n - 1; j > 0; j--){
                if(A[j] < A[j - 1]){
                    int num = A[j];
                    A[j] = A[j - 1];
                    A[j - 1] = num;
                    ans++;
                    flag = 1;
                }
            }
        }
        rep(i, n){
            if(!i) cout << A[i];
            else cout << ' ' << A[i];
        }
        cout << endl << ans << endl;
    }
}
