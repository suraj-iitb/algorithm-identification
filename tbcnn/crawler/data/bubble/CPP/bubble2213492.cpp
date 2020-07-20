#include<bits/stdc++.h>
typedef long long ll;
typedef unsigned long long ull;
using namespace std;
#define pb push_back
int dy[]={0, 0, 1, -1, 0};
int dx[]={1, -1, 0, 0, 0};

#define FOR(i,a,b) for (int i=(a);i<(b);i++)
#define RFOR(i,a,b) for (int i=(b)-1;i>=(a);i--)
#define REP(i,n) for (int i=0;i<(n);i++)
#define RREP(i,n) for (int i=(n)-1;i>=0;i--)

int a[200];

int main(void){
    int n;
    ll c = 0;

    scanf("%d",&n);
    REP(i,n)
        scanf("%d",&a[i]);

    REP(i,n){
        RFOR(j,i + 1,n)
            if(a[j] < a[j - 1]){
                swap(a[j],a[j - 1]);
                c++;
            }
    }

    REP(i,n){
        if(i < n - 1)
            printf("%d ",a[i]);
        else
            printf("%d\n",a[i]);
    }
    printf("%lld\n",c);
    return 0;
}
