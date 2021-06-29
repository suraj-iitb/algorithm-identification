#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <climits>
#include <cmath>
#include <set>
#include <vector>
using namespace std;
const int maxn=100+10;
int a[maxn];
int n;
void bubble_sort(int a[],int n)
{
    int swap_cnt=0;
    for(int i=0;i<n;i++)
    {
        for(int j=n-1;j>0;j--)
        {
            if(a[j]<a[j-1])
            {
                int tmp=a[j];
                a[j]=a[j-1];
                a[j-1]=tmp;
                swap_cnt++;
            }
        }
    }
    for(int i=0;i<n;i++)
    {
        if(i) printf(" ");
        printf("%d",a[i]);
    }
    printf("\n%d\n",swap_cnt);


}
int main()
{
//    freopen("in.txt","r",stdin);
    scanf("%d",&n);
    for(int i=0;i<n;i++)
    {
        scanf("%d",&a[i]);
    }
bubble_sort(a,n);
    return 0;
}
