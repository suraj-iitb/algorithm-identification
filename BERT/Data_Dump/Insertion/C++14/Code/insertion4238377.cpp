#include<bits/stdc++.h>
using namespace std;
//#define int long long
#define debug(x) cout<<#x<<"->"<<x<<endl
#define sz(data) sizeof(data)/sizeof(data[0])

void insertion(int a[],int n){
    for(int i=1;i<n;i++)
    {
        int temp=a[i];
        int j=i-1;
        while(a[j]>temp && j>=0)
        {
            a[j+1]=a[j];
            j--;
        }
        a[j+1]=temp;
        for(int i=0;i<n;i++){
                if(i!=n-1) cout<<a[i]<<' ';
                else cout<<a[i]<<endl;;
        }
    }

}

int main()
{
    //freopen("input.txt" ,"r", stdin);

    int n;
    cin>>n;
    int a[n];
    for(int i=0;i<n;i++)
    {
        cin>>a[i];
    }
    for(int i=0;i<n;i++){
                if(i!=n-1) cout<<a[i]<<' ';
                else cout<<a[i]<<endl;;
        }
    insertion(a,n);

  return 0;
}

