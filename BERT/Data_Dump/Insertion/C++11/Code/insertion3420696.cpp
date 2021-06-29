#include <bits/stdc++.h>
using namespace std;
void insertionSort(int A[],int N)
{
    int v,j;
    static int i=1;
    v=A[i];
    j=i-1;
    while(j>=0&&A[j]>v){
        A[j+1]=A[j];
        j--;
    }
    A[j+1]=v;
    i++;
}

int main()
{
    int n;
    cin>>n;
    int a[100];

    for(int i=0;i<n;i++)
        cin>>a[i];
    for(int i=0;i<n;i++){
        cout<<a[i];
        if(i!=n-1)
            cout<<" ";
    }
    cout<<endl;
    for(int i=1;i<n;i++)
    {
        insertionSort(a,n);
        for(int i=0;i<n;i++){
            cout<<a[i];
            if(i!=n-1)
                cout<<" ";
        }
        cout<<endl;
    }
    return 0;
}

