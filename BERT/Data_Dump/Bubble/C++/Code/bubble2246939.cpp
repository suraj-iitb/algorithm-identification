#include<string>
#include<cctype>
#include<iostream>
#include<cstdio>
#include<cmath>
#include<queue>
using namespace std;
#define inf 0x3f3f3f3f
const int maxn = 100 + 8;

int n;
int bubbleSort(int a[])
{
    int num = 0;
    bool flag = 1;
    for(int i = 0; flag; ++i){
        flag = 0;
        for(int j = n-1; j >= i+1; j--){
            if(a[j] < a[j-1]){
                swap(a[j],a[j-1]);
                flag = 1;
                num++;
            }
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
    int ans = bubbleSort(a);

    for(int i = 0; i < n; ++i){
        printf("%s%d",i == 0 ? "":" ",a[i]);
    }
    printf("\n%d\n",ans);
}
