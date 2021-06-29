//
// Created by MengHaitao on 2019/11/27 0027.
//
//insert sort
#include <iostream>
using namespace std;
int arr[1005],n;
void print()
{
    for (int i = 0; i < n; ++i) {
        cout<<arr[i];
        if(i!=n-1) cout<<" ";
    }
    cout<<endl;
}
void insertSort()
{
    for (int key,j, i = 1; i < n; ++i) {
        key=arr[i];
        j=i;
        while(j>0&&arr[j-1]>=key)
        {
            arr[j]=arr[j-1];
            j--;
        }
        arr[j]=key;
        print();
    }
}
void solve()
{
    cin>>n;
    for (int i = 0; i < n; ++i) {
        cin>>arr[i];
    }
    print();
    insertSort();
}
int main(){
    solve();
    return 0;
}
