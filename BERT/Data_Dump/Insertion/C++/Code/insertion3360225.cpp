#include<bits/stdc++.h>
using namespace std;
const int maxn=100+10;
int n,arr[maxn];
int main()
{
    cin>>n;
    for(int i=0;i<n;i++) cin>>arr[i];
    for(int i=0;i<n;i++){
        int v=arr[i];
        int j=i-1;
        while(j>=0&&arr[j]>v){
            arr[j+1]=arr[j];
            j--;
        }
        arr[j+1]=v;
        for(int i=0;i<n;i++){
            if(i) cout<<" "<<arr[i];
            else cout<<arr[i];
        }cout<<"\n";
    }
    return 0;
}

