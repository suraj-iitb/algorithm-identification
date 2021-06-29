#include <bits/stdc++.h>
using namespace std;

int main() {
    int N;
    cin >> N;
    vector<int> A(N);
    for (int i=0; i<N; i++) cin >> A[i];
    
    // Selection Sort
    int minj=0, tmp, cnt=0;
    bool flag=false;
    for (int i=0; i<N; i++) {
        minj = i;
        flag=false;
        for (int j=i; j<N; j++) {
            if (A[j]<A[minj]) {
                minj=j;
                flag=true;
            }
        }
        if (flag) {
            tmp = A[minj];
            A[minj] = A[i];
            A[i] = tmp;
            cnt++;
            
        }
    }
    
    for (int i=0; i<N-1; i++) cout << A[i] << ' ';
    cout << A[N-1] << endl;
    cout << cnt << endl;
}
