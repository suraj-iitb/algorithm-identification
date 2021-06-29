#include <cstdio>
#include <cstring>
#include <algorithm>
#include <iostream>
using namespace std;
const int maxn=105;
int n;
int a[maxn];
void InsertSort ()
{
    for (int i=0;i<n;i++)
    {
        int temp=a[i];
        int loc=i-1;
        while (loc>=0&&a[loc]>temp)
               {
                   a[loc+1]=a[loc];
                   loc--;
               }
        a[loc+1]=temp;
        for (int j=0;j<n;j++)
            printf("%d%c",a[j],j==n-1? '\n':' ');
    }
}
int main()
{
    scanf("%d",&n);
    for (int i=0;i<n;i++)
        scanf("%d",&a[i]);
    InsertSort();
    return 0;
}
