#include <bits/stdc++.h>
#include <string>
using namespace std;
static const int MAX = 100;

int main(){
    int n, A[MAX], ans = 0;
    cin >> n;
    for (int i = 0; i < n; i++) cin >> A[i];

    for (int i = 0; i < n; i++){
        int minj = i;
        for (int j = i; j < n; j++){
            if( A[j] < A[minj]){
                minj = j;
            }

        }
        swap(A[i],A[minj]);
        if (i != minj){
        ans++;
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
