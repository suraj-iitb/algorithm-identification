#include <bits/stdc++.h>
using namespace std;
int A[110];
int main(){
    int N;
    cin>>N;
    int ans=0;
    for(int i=0;i<N;i++)cin>>A[i];
    for(int i=0;i<N;i++){
        int minj=i;
        for(int j=i;j<N;j++){
            if(A[j]<A[minj])minj=j;
        }
        swap(A[i],A[minj]);
        if(i!=minj)ans++;
    }
    for(int i=0;i<N;i++)cout<<A[i]<<(i==N-1?'\n':' ');
    cout<<ans<<endl;
}
