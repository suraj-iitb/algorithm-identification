#include<bits/stdc++.h>
using namespace std;
const int maxn=100+10;
int n,arr[maxn],cnt=0;
int main()
{
    cin>>n;
    for(int i=0;i<n;i++) cin>>arr[i];
    for(int i=0;i<n;i++){
        int minj=i;
        for(int j=i;j<n;j++){
            if(arr[j]<arr[minj]){
                minj=j;
            }
        }
        if(i!=minj){
            cnt++;
            swap(arr[i],arr[minj]);
        }
    }
    for(int i=0;i<n;i++){
        if(i) cout<<" ";
        cout<<arr[i];
    }
    cout<<"\n"<<cnt<<"\n";
}
/*
#include<bits/stdc++.h>
using namespace std;
const int maxn=100+10;
int n,arr[maxn],cnt=0;
int main()
{
    cin>>n;
    for(int i=0;i<n;i++) cin>>arr[i];
    bool flag=1;
    for(int i=0;flag;i++){
        flag=0;
        for(int j=n-1;j>i;j--){
            if(arr[j-1]>arr[j]){
                flag=1;
                swap(arr[j],arr[j-1]);
                cnt++;
            }
        }
    }
    for(int i=0;i<n;i++){
        if(i) cout<<" ";
        cout<<arr[i];
    }
    cout<<"\n"<<cnt<<"\n";
    return 0;
}
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
*/

