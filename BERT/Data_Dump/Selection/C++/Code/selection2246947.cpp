#include<string>
#include<cctype>
#include<iostream>
#include<cstdio>
#include<cmath>
#include<queue>
using namespace std;
#define inf 0x3f3f3f3f
const int maxn = 100 + 8;

int n,minj;
int selectSort(int a[])
{
    int num = 0;
    for(int i = 0; i < n; ++i){
        minj = i;
        for(int j = i; j < n; ++j){
            if(a[j] < a[minj]){
                minj = j;
            }
        }
        if(minj != i) {
            swap(a[minj],a[i]);
            num++;
        }
    }
    return num;
}
int a[maxn];
int main()
{
    fill(a,a+n,0);
    scanf("%d",&n);
    for(int i = 0; i < n; ++i){
        scanf("%d",&a[i]);
    }
    int ans = selectSort(a);

    for(int i = 0; i < n; ++i){
        printf("%s%d",i == 0 ? "":" ",a[i]);
    }
    printf("\n%d\n",ans);
}
