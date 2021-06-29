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


int main(void){
    int a[200],key,n;

    scanf("%d",&n);

    REP(i,n){
        scanf("%d",&a[i]);
    }
    REP(i,n)
        if(i < n - 1)
            printf("%d ",a[i]);
        else
            printf("%d\n",a[i]);

    REP(i,n - 1){
        key = a[i + 1];
        int j = i;
        while(j >= 0 && a[j] > key){
            a[j + 1] = a[j];j--;
        }
        a[j + 1] = key;
        REP(k,n){
            if(k < n - 1)
                printf("%d ",a[k]);
            else
                printf("%d\n",a[k]);
        }
    }
}
