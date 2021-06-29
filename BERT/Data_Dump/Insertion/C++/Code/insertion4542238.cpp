#include <bits/stdc++.h>
using namespace std;
int num[101];
int main()
{
    int n,temp,i,j;
    scanf("%d",&n);
    for(int i=0; i<n; i++)
        scanf("%d",&num[i]);
    for( i=0; i<n; i++)
    {
        temp=num[i];
        for( j=i-1; j>=0&&num[j]>=temp; j--)
            num[j+1]=num[j];
        num[j+1]=temp;
        for(j=0; j<n; j++)
            if(j==0) printf("%d",num[j]);
           else  printf(" %d",num[j]);
        printf("\n");
    }
    return 0;
}


