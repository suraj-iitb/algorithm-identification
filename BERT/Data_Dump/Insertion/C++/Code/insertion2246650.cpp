#include<algorithm>
#include<set>
#include<map>
#include<vector>
#include<cstring>
#include<string>
#include<cctype>
#include<iostream>
#include<cstdio>
#include<cmath>
#include<queue>
using namespace std;
const int maxn = 100 + 8;

int n;
int a[maxn];
int v,j;
void see(int a[])
{
    for(int i = 0; i < n; ++i){
        if(i) printf(" ");
        printf("%d",a[i]);
    }
    printf("\n");
    return;
}

int main()
{
    memset(a,0,sizeof a);
    scanf("%d",&n);
    for(int i = 0; i < n; ++i){
        scanf("%d",&a[i]);
    }

    see(a);

    for(int i = 1; i < n; ++i){
        v = a[i];
        j = i-1;
        while(j >= 0 && a[j] > v){
            a[j+1] = a[j];
            j--;
        }
        a[j+1] = v;
        see(a);
    }

}
