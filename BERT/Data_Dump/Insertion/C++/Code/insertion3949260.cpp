#include<bits/stdc++.h>
using namespace std;

int main()
{
    int N;
    cin >> N;
    int A[N];
    for(int i = 0; i< N; ++i) cin >> A[i];
    for(int i = 0; i < N-1; ++i) printf("%d ", A[i]);
    printf("%d\n", A[N-1]);
    for(int i = 1; i < N; ++i) {
        
        int v = A[i];
        int j = i-1;
        while(j >= 0 && A[j] > v){
            A[j+1] = A[j];
            --j;
        }
        A[j+1] = v;
        for(int j = 0; j < N-1; ++j) cout << A[j] << " ";
        cout << A[N-1] << endl;
    }
    return 0;
}
