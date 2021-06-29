#include <iostream>

using namespace std;

int main(){
    int n,ans=0;
    int a[101];

    cin>>n;
    for(int i=0; i<n; i++) cin>>a[i];

    for(int i=0; i<n-1; i++){
        for(int j=n-1; j>i; j--){
            if(a[j]<a[j-1]){
                int keep=a[j];
                a[j]=a[j-1];
                a[j-1]=keep;
                ans++;
            }
        }
    }

    for(int i=0; i<n; i++){
        cout<<a[i];
        if(i!=n-1) cout<<" ";
    }
    cout<<endl;
    cout<<ans<<endl;

    return 0;
}
