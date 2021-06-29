#include <bits/stdc++.h>
#include <math.h>
#define _GLIBCXX_DEBUG
using namespace std;
int main() {
    
    int N;
    cin>>N;
    
    vector<int> A(N);
    for(int i=0;i<N;i++){
        cin>>A[i];
    }
    
    
    int ans=0;
    
    for(int i=0;i<N;i++){
        for(int j=N-1;j>=i;j--){
            if(A[j]<A[j-1]){
                swap(A[j],A[j-1]);
                ans++;
            }
        }
    }
    
    for(int k=0;k<N-1;k++){
        cout<<A[k]<<" ";
    }
    
    cout<<A[N-1]<<endl;
    cout<<ans<<endl;
}
