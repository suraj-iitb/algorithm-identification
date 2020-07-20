#include <bits/stdc++.h>
using namespace std;

int N, temp, ans;

int main() {
    cin >> N;
    int a[N];
    for (int i=0; i<N; i++) cin >> a[i];
    for (int i=0; i<N; i++) {
        for (int j=i; j>0; j--) {
            if (a[j] < a[j-1]) {
                temp = a[j]; a[j] = a[j-1]; a[j-1] = temp; ans+=1;
            }
        }
    }
    cout << a[0];
    for (int k=1; k<N; k++) cout << " " << a[k];
    cout << endl << ans <<endl;
}
