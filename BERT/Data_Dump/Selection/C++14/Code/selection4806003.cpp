#include<bits/stdc++.h>
using namespace std;

#define rep(i,n)  for(int i=0;i<n;++i)
#define sc1(a)  scanf("%d",&a)

int main(){
    int n,ans=0;
    sc1(n);
    vector <int> a(n);
    for(auto&e:a) sc1(e);
    for(int i=0;i<n-1;i++){
        int p=a[i],q=i;
        for(int j=i+1;j<n;j++) {
            if (p>a[j]) {
                p=a[j];
                q=j;
            }
        }
        if(p<a[i]) {
            ans++;
            swap(a[i],a[q]);
        }
    }
    rep(i,n) printf("%d%c",a[i],(i<n-1)?' ':'\n');
    printf("%d\n",ans);
    return 0;
}

