#include<bits/stdc++.h>

using namespace std;

int n;
int a[500010];
int b[500010];

int cnt;

void mg(int l,int r)
{
    int mid=(l+r)/2;

    int tmp=0;
    int i,j;
    cnt+=r-l;
    for(i=l,j=mid;i<mid&&j<r;)
    {
        if(a[i]>a[j])
        {
            b[tmp++]=a[j++];
        }else
        {
            b[tmp++]=a[i++];
        }
    }

    while(i<mid)
    {
        b[tmp++]=a[i++];
    }

    while(j<r)
    {
        b[tmp++]=a[j++];
    }

    for(int i=l;i<r;i++)
    {
        a[i]=b[i-l];
    }
}

void merge_sort(int l,int r)
{
    int mid=(l+r)/2;

    if(l+1==r)
    {
        return;
    }

    merge_sort(l,mid);
    merge_sort(mid,r);
    mg(l,r);
}

int main()
{

    while(scanf("%d",&n)!=EOF)
    {

        for(int i=0;i<n;i++)
        {
            scanf("%d",&a[i]);
        }

        cnt=0;
        merge_sort(0,n);

        for(int i=0;i<n;i++)
        {
            if(i)
            {
                printf(" ");
            }
            printf("%d",a[i]);

        }
        printf("\n%d\n",cnt);
    }

    return 0;
}

