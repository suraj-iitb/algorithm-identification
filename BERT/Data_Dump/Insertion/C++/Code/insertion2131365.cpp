#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <climits>
#include <cmath>
#include <set>
#include <vector>
using namespace std;
const int maxn=100+5;
int n;
int a[maxn];

void print()
{
    for(int i=0;i<n;i++)
    {
        if(i) printf(" ");
        printf("%d",a[i]);
    }
    printf("\n");
}
void insert_sort()
{
    for(int i=0;i<n;i++)
    {
        int k=a[i];
        int j=i-1;
        while(j>=0&&a[j]>k)
        {
            a[j+1]=a[j];
            j--;
        }
        a[j+1]=k;
        print();
    }
}
int main()
{
//    freopen("in.txt","r",stdin);
    scanf("%d",&n);
    for(int i=0;i<n;i++) scanf("%d",&a[i]);
    insert_sort();
    return 0;
}
