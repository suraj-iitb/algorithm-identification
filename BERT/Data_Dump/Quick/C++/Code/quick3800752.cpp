#include<iostream>
#define ss second
#define ff  first
using namespace std;
pair<char,int>a[100005],b[100005];
pair<char,int>L[100005],R[100005];
const int INF=1e9+7;
int Parttion(pair<char,int> a[],int l,int r)
{
    pair<char,int>x=a[r];
    int i=l-1;
    for(int j=l;j<r;j++)if(a[j].ss<=x.ss)swap(a[++i],a[j]);
    swap(a[++i],a[r]);

    return i;
}
int quickSort(pair <char ,int> a[],int l,int r)
{
    if(l<r)
    {
        int q=Parttion(a,l,r);
        quickSort(a,l,q-1);
        quickSort(a,q+1,r);
    }
}

void Merge(pair <char,int>a[],int l, int  m , int r )
{
    int n1=m-l;
    int n2=r-m;
    for(int i=0;i<n1;i++)L[i]=a[l+i];
    for(int i=0;i<n2;i++)R[i]=a[m+i];
    L[n1].ss=R[n2].ss=INF;      //归并排序的这里很重要
    for(int k=l,i=0,j=0;k<r;k++)
    {
        if(L[i].ss<=R[j].ss)a[k]=L[i++];    //排序的时候<=一定要加上，不然可能会有不稳定排序的情况发生。
        else a[k]=R[j++];
    }
}

int MergeSort(pair<char,int>a[],int l ,int r )
{
    if(l+1<r)
    {
        int m=l+r>>1;
        MergeSort(a,l,m);
        MergeSort(a,m,r);
        Merge(a,l,m,r);
    }
}

int main()
{
    int n;
    cin>>n;
    for(int i=0;i<n;i++)cin>>a[i].ff>>a[i].ss,b[i]=a[i];
    quickSort(a,0,n-1);
    MergeSort(b,0,n);
    int flag=0;
    for(int i=0;i<n;i++)if(a[i]!=b[i]){flag=1;break;}
    if(flag)cout<<"Not stable"<<endl;
    else cout<<"Stable"<<endl;
    for(int i=0;i<n;i++)cout<<a[i].ff<<' '<<a[i].ss<<endl;//<<b[i].ff<<' '<<b[i].ss<<endl;
    return 0;
}

