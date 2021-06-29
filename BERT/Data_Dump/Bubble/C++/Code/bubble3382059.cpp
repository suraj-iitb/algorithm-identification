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
    int v,j;
    bool flag=1;
    int cnt=0;
    while(flag){
        flag=0;
        for(int j=N-1;j>=1;j--){
            if(A[j]<A[j-1]){
                v=A[j];
                A[j]=A[j-1];
                A[j-1]=v;
                flag=1;
                cnt++;
            }
        }
    }
    for(int k=0;k<N;k++){
        if(k==N-1) cout << A[k] << endl;
        else if(k!=N-1) cout << A[k] << " ";
    }
    cout << cnt << endl;
}








