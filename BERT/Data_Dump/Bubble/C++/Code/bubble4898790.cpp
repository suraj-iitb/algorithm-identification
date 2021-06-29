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
        flag=0;//如果在一轮循环中没有交换，说明已经排序完毕，就终止循环
        for(int j=n-1;j>i;j--){//从后往前排
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
}
