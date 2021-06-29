//IN THE NAME OF GOD

#include <iostream>
using namespace std;
typedef long long int ll;
int n,a[110],ans;
int main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    for(int i=0;i<n;i++){
        int m=i;
        for(int j=i+1;j<n;j++){
            if(a[j]<a[m])
                m=j;
        }
        if(m!=i)
            ans++;
        swap(a[m],a[i]);
    }
    for(int i=0;i<n-1;i++)
        cout<<a[i]<<" ";
    cout<<a[n-1]<<endl;
    cout<<ans<<endl;
    return 0;
}
