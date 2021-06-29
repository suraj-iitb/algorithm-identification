#include <bits/stdc++.h>
using namespace std;
int N, A[2000001], i, j, k, freq[1000000];

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); 
    cout.tie(NULL);
    cin >> N;
    for (int i=1;i<=N;i++){
        cin >> A[i];
        freq[A[i]]++;
    }
    k=0;
    for (int i=0;i<=10000;i++){ //min dan max A[i]
        for (int j=1;j<=freq[i];j++){
            k++;
            A[k] = i;
        }
    }
    for(int i=1; i<=N; i++) {
        cout << A[i];
        if (i==N) {
            cout << endl;
        } else {
            cout << " ";
        }
    }
}
