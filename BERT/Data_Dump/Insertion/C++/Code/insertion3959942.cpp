#include<bits/stdc++.h>
using namespace std;

int main(){// N個の要素を含む0-オリジンの配列A
    int N;
    cin >> N;
    int A[N];
    for(int i=0;i<N;i++) cin >> A[i]; 
    for(int i=0;i<N;i++){
        int v = A[i];
        int j = i;
        while(j>=1&&A[j-1]>v){
            A[j] = A[j-1];
            j--;
            A[j] = v;
        }
        for(int k=0;k<N-1;k++) cout << A[k] << " ";
        cout << A[N-1] << endl;
    }
}
