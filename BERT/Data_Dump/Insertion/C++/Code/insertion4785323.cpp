#include<bits/stdc++.h>
#define int long long
using namespace std;
int A[110];
signed main(){
    int N;
    cin>>N;
    for(int i=0;i<N;i++)cin>>A[i];
    for(int i=0;i<N;i++){
        int v = A[i],j = i - 1;
        while(j >= 0 && A[j] > v)A[j+1] = A[j],j--;
        A[j+1] = v;
        for(int i=0;i<N;i++)cout<<A[i]<<(i==N-1?'\n':' ');
    }
}
