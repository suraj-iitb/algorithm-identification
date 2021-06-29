#include<bits/stdc++.h>
using namespace std;

#define rep(i,n)  for(int i=0;i<n;++i)
#define sc1(a)  scanf("%d",&a)


int main(){
    int mod=1000000007;
    int n,ans=0;
    sc1(n);
    vector <int> a(n);
    for(auto&e:a) sc1(e);
    for(int i=0;i<n;i++) {
        for(int j=n-1;j>0+i;j--) {
            if (a[j]<a[j-1]) {
                ans++;
                swap(a[j],a[j-1]);
            }
        }
    }
    rep(i,n) printf("%d%c",a[i],(i<n-1)?' ':'\n');
    printf("%d\n",ans);
    return 0;
}

