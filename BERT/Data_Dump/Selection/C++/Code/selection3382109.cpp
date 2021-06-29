#include <bits/stdc++.h>
#include <vector>
#include <algorithm>
using namespace std;

int main ()
{
    int N;
    int A[1010];
    cin >> N ;
    for(int k=0;k<N;k++){
        cin >> A[k];
    }
    int minj,v;
    int cnt=0;
    int j;
    for(int i=0;i<N;i++){
        minj=i;
        for(j=i;j<N;j++){
            if(A[j]<A[minj]) minj=j;
        }
        if(i!=minj){
            v=A[i];
            A[i]=A[minj];
            A[minj]=v;
            cnt++;
        }
    }
    for(int k=0;k<N;k++){
        if(k==N-1) cout << A[k] << endl;
        else if(k!=N-1) cout << A[k] << " ";
    }
    cout << cnt << endl;
}








