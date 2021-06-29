#include<cstdlib>
#include<cstdio>
#include<algorithm>
#include<vector>
#include<queue>
#include<set>
using namespace std;
const int MAXN = (int) 2e5 + 10;
const int INF = (int) 0x3f3f3f3f;
typedef long long LL;

int n;
int a[MAXN];

void work(){
    scanf("%d",&n);
    for(int i=1;i<=n;i++) scanf("%d",&a[i]);
    int cnt=0;
    for(int i=1;i<n;i++){
        int mi=i;
        for(int j=i;j<=n;j++){
            if(a[mi]>a[j]) mi=j;
        }
        if(mi!=i) cnt++;
        swap(a[i],a[mi]);
    }
    for(int i=1;i<n;i++) printf("%d ",a[i]);
    printf("%d\n%d\n",a[n],cnt);
}

int main(){
    work();
    return 0;
}






