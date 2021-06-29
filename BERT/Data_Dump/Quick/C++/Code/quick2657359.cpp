#include<cstdio>
#include<iostream>
#define SENTINEL 1000000000
using namespace std;
struct   card
{
    char c;
    int k;
}a[100010],A[100010],temp;
int partition(int p,int r)
{
    int x=a[r].k,i=p-1;
    int j;
    for (j=p;j<r;j++)
        if(a[j].k<=x)
        {
            i++;
            temp = a[j];
            a[j] = a[i];
            a[i]=temp;
        }
        temp = a[i+1];
        a[i+1] = a[r];
        a[r] =temp;
        return i+1;
}
void quicksort(int p,int r)
{
    if(p < r)
    {
        int q = partition(p,r);
        quicksort(p,q-1);
        quicksort(q+1,r);
    }
}
void Merge (int left,int mid,int right)
{
    int n1,n2,i,j,m;
    n1=mid-left;
    n2=right-mid;
    struct card L[n1+10],R[n2+10];
    for(i=0;i<n1;i++)
        L[i]=A[left+i];
      for(i=0;i<n2;i++)
        R[i]=A[mid+i];
    i=j=0;
      L[n1].k=R[n2].k=SENTINEL;
    for(m=left;m<right;m++) {
            if(L[i].k<=R[j].k)
                A[m]=L[i++];
            else
                A[m]=R[j++];
        }
}
void Merge_Sort(int left,int right)
{
    if(left+1<right)
    {
         int mid=(left+right)/2;
         Merge_Sort(left,mid);
         Merge_Sort(mid,right);
         Merge(left,mid,right);
    }
}
int main()
{
    int n,i,flag=0;
    cin >> n;
    for(i=0;i<n;i++)
    {
          cin >> a[i].c >>a[i].k ;
           A[i].c=a[i].c;
           A[i].k=a[i].k;
    }
    quicksort(0,n-1);
    Merge_Sort(0,n);
    for(i=0;i<n;i++)
        if(a[i].c!=A[i].c)
    {
        flag = 1;
        break;
    }
    if(flag == 0)
        printf("Stable\n");
    else
        printf("Not stable\n");
    for (i=0;i<n;i++)
        printf("%c %d\n",a[i].c,a[i].k);
    return 0;
}
