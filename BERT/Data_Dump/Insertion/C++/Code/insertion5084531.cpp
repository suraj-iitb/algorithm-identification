#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define MAX 200000
#define LARGE 2000000000

int main() {
	int n;
	cin >> n;
    int A[n];
    rep(i, n) cin >> A[i];

    for(int i=0; i<n; i++) {
        int v = A[i];
        int j = i - 1;
        while ((j>=0) && (A[j] > v)) {
            A[j+1] = A[j];
            j--;
            A[j+1] = v;
        }
        for(int k=0; k<n; k++) {
            cout << A[k];
            if(k < n - 1) cout << ' ';
        }
        cout << endl;
    }

	return 0;
}

