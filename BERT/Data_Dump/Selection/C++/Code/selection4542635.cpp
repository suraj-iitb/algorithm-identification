#include <bits/stdc++.h>
using namespace std;
int num[101];
int main()
{
    int cnt=0,n,m;
    scanf("%d",&n);
    for(int i=0;i<n;i++)
        scanf("%d",&num[i]);
    for(int i=0;i<n;i++)
    {
        m=i;
        for(int j=i;j<n;j++)
            if(num[j]<num[m]) m=j;
       if(m!=i)
       {
           swap(num[i],num[m]);
           cnt++;
       }
    }
    for(int i=0;i<n;i++)
        if(i==0) printf("%d",num[i]);
    else printf(" %d",num[i]);
    printf("\n");
    printf("%d\n",cnt);
    return 0;
}

