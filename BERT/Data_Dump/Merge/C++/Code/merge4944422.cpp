#include<iostream>
#include<cstdio>
#include<vector>
using namespace std;
vector<unsigned int> vect;
unsigned int js=0;

void _Merge(vector<unsigned int> &a, int left, int mid, int right)
{
    int n1 = mid-left;
    int n2 = right - mid;
    vector<unsigned int> L,R;
    for(int i=0;i<n1;i++)
        L.push_back(a[left+i]);
    for(int i=0;i<n2;i++)
        R.push_back(a[mid+i]);
    L.push_back(1000000009);
    R.push_back(1000000009);
    int m=0,n=0;

    for(int i=left;i<right;i++)
    {
        if(L[m]<=R[n])
        {
            a[i]=L[m];
            m++;
        }
        else
        {
            a[i]=R[n];
            n++;
        }
    }
    js += m+n;
}


void mergeSort(vector<unsigned int> &a,int left, int right)
{
    if(left+1<right)
    {
        int mid = (left+right)/2;
        mergeSort(a,left,mid);
        mergeSort(a,mid,right);
        _Merge(a,left,mid, right);
    }
}


int main()
{
    int n;
    cin>>n;
    unsigned int tmp;
    for(int i=0;i<n;i++)
    {
        cin>>tmp;
        vect.push_back(tmp);
    }
    mergeSort(vect,0,n);
    for(int i=0;i<n;i++)
    {
        cout<<vect[i];
        if(i!=n-1) cout<<" ";
    }
    cout<<endl<<js<<endl;
}

