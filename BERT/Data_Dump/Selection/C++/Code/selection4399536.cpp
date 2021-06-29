#include <bits/stdc++.h>
using namespace std;
int main(){
    int N;
    cin>>N;
    int A[N];
    for(int i=0;i<N;i++){
        cin>>A[i];
    }
    int ans=0;
    for(int i=0;i<N;i++){
        int minj=i;
        for(int j=i;j<N;j++){
            if(A[j]<A[minj]){
                minj=j;
            }
        }
        if(i!=minj) ans++;
        swap(A[i],A[minj]);
    }
    for(int i=0;i<N;i++){
        cout<<A[i];
        if(i==N-1) cout<<endl;
        else cout<<' ';
    }
    cout<<ans<<endl;
}
