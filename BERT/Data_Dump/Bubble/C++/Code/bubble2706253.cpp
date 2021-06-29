#include <iostream>
#include <vector>
using namespace std;

void swap(int *a,int *b){
    int t = *a;
    *a = *b;
    *b = t;
}
int main() {
    int n,ans=0;
    cin>>n;
    vector<int> a(n);
    for (int i=0;i<n;i++) cin>>a[i];
    for (int i=0;i<n-1;i++) {
        for (int j=n-1;j>i;j--) {
           if (a[j]<a[j-1]){
               swap(a[j],a[j-1]);
               ans++;
           }
        }
        cout<<a[i]<<" ";
    }
    cout<<a[n-1]<<endl;
    cout<<ans<<endl;
    return 0;
}
