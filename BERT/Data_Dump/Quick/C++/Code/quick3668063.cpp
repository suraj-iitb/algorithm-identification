#include <bits/stdc++.h>

using namespace std;

int sz;

void print(pair<char,int> a[])
{
    for(int i=0; i<sz; i++)
        cout<<a[i].first<<" "<<a[i].second<<"\n";
}


int Partition(pair<char,int> a[],int p,int r)
{
    int x= a[r].second;
    int i= p-1;
    for(int j=p ; j<=r-1; j++)
    {
        if(a[j].second<=x)
        {
            i++;
            swap(a[i],a[j]);
        }

    }
    swap(a[i+1],a[r]);
    return (i+1);
}

void QuickSort(pair<char,int>a[],int p,int r)
{
    if(p<r)
    {
        int q=Partition(a,p,r);
        QuickSort(a,p,q-1);
        QuickSort(a,q+1,r);
    }

}

int main()
{
    //freopen("inp.txt","r",stdin);
    //freopen("outp.txt","w",stdout);
    int n,a2,p,r;
    char a1;
    cin>>n;
    sz=n;
    pair<char,int> a[n],b[n];
    for(int i=0; i<n; i++)
    {
        cin>>a1>>a2;
        a[i]=make_pair(a1,a2);
        b[i]=make_pair(a1,a2);
    }
    QuickSort(a,0,n-1);
    ///////////
    int f=0;
    for(int i=0; i<sz; i++)
    {
        if(f==1)
            break;
        for(int j=0; j<sz; j++)
        {
            if(a[i].second==b[j].second)
            {
                if(a[i].first==b[j].first)
                {
                    b[j].second=0;
                    break;
                }
                else
                {
                    f=1;
                    break;
                }
            }

        }
    }
    if(f==0)
        cout<<"Stable"<<"\n";
    else
        cout<<"Not stable"<<"\n";
    ///////////
    print(a);
    return 0;
}

