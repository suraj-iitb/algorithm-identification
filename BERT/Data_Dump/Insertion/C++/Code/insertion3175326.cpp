#include<cstdlib>
#include<cstdio>
#include<algorithm>
using namespace std;
const int MAXN = (int)1e5 + 10;

int n;
int a[MAXN];

void work(){
    scanf("%d",&n);
    for(int i=1;i<=n;i++) scanf("%d",&a[i]);
    for(int i=1;i<=n;i++){
        for(int j=1;j<=i;j++){
            if(a[j]>a[i]) swap(a[i],a[j]);
        }
        for(int id=1;id<=n;id++){
            printf("%d",a[id]);
            if(id==n) printf("\n");
            else printf(" ");
        }
    }
}

int main(){
    work();
    return 0;
}

