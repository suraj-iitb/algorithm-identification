#include <bits/stdc++.h>
using namespace std;
const int MAX = 101;
int num[MAX];
int main()
{
    int n,cnt=0;
    scanf("%d",&n);
    for(int i=0;i<n;i++)
        scanf("%d",&num[i]);
    for(int i=0;i<n-1;i++)
        for(int j=0;j<n-i-1;j++)
         if(num[j]>num[j+1])
    {
        cnt++;
        swap(num[j],num[j+1]);
    }
    for(int i=0;i<n;i++)
        if(i==0) printf("%d",num[i]);
        else printf(" %d",num[i]);
    printf("\n");
    printf("%d\n",cnt);
    return 0;
}


