#include <iostream>

using namespace std;

int main(){
    int n,ans=0;
    int a[101];

    cin>>n;
    for(int i=0; i<n; i++) cin>>a[i];

    for(int i=0; i<n-1; i++){
        int minn=i;
        for(int j=i+1; j<n; j++){
            if(a[minn]>a[j]){
                minn=j;
            }
        }
        if(minn==i) continue;
        int keep=a[i];
        a[i]=a[minn];
        a[minn]=keep;
        ans++;
    }

    for(int i=0; i<n; i++){
        cout<<a[i];
        if(i!=n-1) cout<<" ";
    }
    cout<<endl;
    cout<<ans<<endl;

    return 0;
}
