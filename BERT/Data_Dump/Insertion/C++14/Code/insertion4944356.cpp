#include <bits/stdc++.h>
using namespace std;

int main() {
    int N;
    cin >> N;
    vector<int> A(N);
    for(int i=0;i<N;i++){
        cin >> A[i];
    }
    for(int i=0;i<N;i++){
        int v = A[i];
        int j = i-1;
        while(j>=0&&v<A[j]){
            A[j+1]=A[j];
            j--;
        }
        A[j+1]=v;
        for(int k=0;k<N;k++){
            if(k==N-1){
                cout << A[k];
            }else{
                cout << A[k] << " ";
            }
        }
        cout << endl;
    }
    return 0;
}
