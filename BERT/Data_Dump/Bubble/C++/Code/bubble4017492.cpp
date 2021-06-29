#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

void solve(int ar[],int n)
{
    int s=0;
    for(int i=0;i<n-1;i++){
        for(int j=0;j<n-i-1;j++){
            if(ar[j]>ar[j+1]){
                swap(ar[j],ar[j+1]);
                s++;
            }
        }
    }
    
    for(int i=0;i<n;i++){
        cout<<ar[i]<<((i == n-1) ? "\n" : " ");
    }
    cout<<s<<"\n";
}

int main()
{
    int n;
    cin>>n;

   int ar[n];

    for(int i=0; i<n; i++)
    {
        cin>>ar[i];
    }

    solve(ar,n);

    return 0;
}

