#include <iostream>
using namespace std;
int sab(int a[],int n){
    int ans=0;
    for (int i=0; i<n; i++) {
        int minj=i;
        for (int j=i+1; j<n; j++) {
            if(a[j]<a[minj]){
                minj=j;
            }
        }
        if (a[i]!=a[minj]) {
            swap(a[i],a[minj]);
            ans++;
        }
    }
    return ans;
}
int main() {
    int A[100];
    int N;
    cin>>N;
    for(int i=0;i<N;i++){
        cin>>A[i];
    }
    
    int ans= sab(A,N);
    
    for (int i=0;i<N-1;i++) {
        cout<<A[i]<<" ";
    }
    cout<<A[N-1]<<endl<<ans<<endl;
}
