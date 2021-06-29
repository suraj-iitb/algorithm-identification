#include<bits/stdc++.h>

using namespace std;

typedef struct
{
    char ch;
    int num;
}Card;

Card a[100010],b[100010],c[100010];

int part(int l,int r)
{
    int x=a[r-1].num;

    int i=l-1;
    for(int j=l;j<r-1;j++)
    {
        if(a[j].num<=x)
        {
            swap(a[++i],a[j]);
        }
    }
    swap(a[++i],a[r-1]);

    return i;
}
void quick_sort(int l,int r)
{
    if(l+1<r)
    {
        int idx=part(l,r);
        quick_sort(l,idx);
        quick_sort(idx+1,r);
    }
}

void mg(int l,int r)
{
    int mid=(l+r)/2;
    int tmp=0;
    int i,j;
    for(i=l,j=mid;i<mid&&j<r;)
    {
        if(b[i].num>b[j].num)
        {
            c[tmp++]=b[j++];
        }else
        {
            c[tmp++]=b[i++];
        }
    }

    while(i<mid)
    {
        c[tmp++]=b[i++];
    }

    while(j<r)
    {
        c[tmp++]=b[j++];
    }

    for(i=l;i<r;i++)
    {
        b[i]=c[i-l];
    }
}

void merge_sort(int l,int r)
{
    if(l+1==r)
    {
        return;
    }

    int mid=(l+r)/2;

    merge_sort(l,mid);
    merge_sort(mid,r);

    mg(l,r);
}

int main()
{
    int n;

    while(cin>>n)
    {
        for(int i=0;i<n;i++)
        {
            getchar();
            scanf("%c %d",&a[i].ch,&a[i].num);
            b[i]=a[i];
        }

        quick_sort(0,n);
        merge_sort(0,n);

        bool flag=true;
        for(int i=0;i<n&&flag;i++)
        {
            if(a[i].ch!=b[i].ch||a[i].num!=b[i].num)
            {
                flag=false;
            }
        }

        if(flag)
        {
            cout<<"Stable"<<endl;
        }else
        {
            cout<<"Not stable"<<endl;
        }

        for(int i=0;i<n;i++)
        {
            printf("%c %d\n",a[i].ch,a[i].num);
        }
    }

    return 0;
}

