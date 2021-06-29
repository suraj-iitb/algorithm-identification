#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;

int main(){
    int N;
    int A[1000];
    cin >> N;
    for(int i=0;i<N;i++) cin >> A[i];

    for(int k=0;k<N;k++) cout << A[k] << (k<N-1?" ":"\n");
    for(int i=1;i<N;i++){
        int v=A[i];
        int j;
        for(j=i-1;j>=0 && A[j]>v;j--) A[j+1]=A[j];
        A[j+1]=v;

        for(int k=0;k<N;k++) cout << A[k] << (k<N-1?" ":"\n");
    }
    
    return 0;
}
