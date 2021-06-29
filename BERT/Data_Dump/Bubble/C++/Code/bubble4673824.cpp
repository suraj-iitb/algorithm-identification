#include <bits/stdc++.h>
#include <string>
using namespace std;
static const int MAX = 100;

int main(){
    int n, A[MAX], ans = 0, t;
    cin >> n;
    for (int i = 0; i < n; i++) cin >> A[i];

    int flag = 1;

    while (flag){
        flag = 0;
        for (int j = n-1; j > 0; j--){
            if(A[j] < A[j-1]){
                t = A[j];
                A[j] = A[j-1];
                A[j-1] = t;
                flag = 1;
                ans++;
            }
        }
    }

    for (int k = 0; k < n; k++){
        cout << A[k];
        if(k < n-1){
            cout << " ";
        }else{
        cout << endl;
        }
    }
    cout << ans << endl;

}
