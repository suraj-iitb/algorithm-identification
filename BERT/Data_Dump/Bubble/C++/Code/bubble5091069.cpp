#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define MAX 200000
#define LARGE 2000000000

void res(int A[], int N, int cnt) {
    for(int i=0; i<N; i++) {
        if(i != 0) cout << ' ';
        cout << A[i];
    }
    cout << endl;
    cout << cnt << endl;

}

int main() {
	int N;
	cin >> N;
    int A[N];
    rep(i, N) cin >> A[i];

    int t=0;
    int cnt=0;

    while(t <= N) {
        for(int i=(N-1); i>t; i--) {
            if(A[i] < A[i-1]) {
                swap(A[i], A[i-1]);
                cnt++;
            }
        }
        t++;
    }
    res(A, N, cnt);

	return 0;
}

