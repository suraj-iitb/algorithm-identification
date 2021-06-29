#include<bits/stdc++.h>
using namespace std;

#define rep(i,n)  for(int i=0;i<n;++i)
#define sc1(a)  scanf("%d",&a)

int main(){
    int mod=1000000007;
    int n,m,ans;
    sc1(n);
    vector <int> a(n);
    for(auto&e:a) sc1(e);
    rep(i,n) {
        int x;
        x=a[i];
        for(int j=i;j>0;j--) {
            if(x<a[j-1]) {
                a[j]=a[j-1];
                a[j-1]=x;
            } else {
                break;
            }
        }
        rep(i,n) printf("%d%c",a[i],(i<n-1)?' ':'\n');
    }
    return 0;
}

