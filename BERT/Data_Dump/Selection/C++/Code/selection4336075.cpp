#include<iostream>
using namespace std;

int main(){
    int n;
    cin>>n;
    int a[110];
    for(int i=0;i<n;i++)cin>>a[i];
    int cnt=0;
    //SelectionSort
    for(int i=0;i<n-1;i++){
        int mini=i;
        for(int j=i+1;j<n;j++){
            if(a[j]<a[mini]){
                mini=j;
            }
        }
        if(i!=mini){
            cnt++;
            swap(a[i],a[mini]);
        }
    }
    //Output
    for(int i=0;i<n;i++){
        cout<<a[i];
        if(i<n-1)cout<<" ";
        else cout<<""<<endl;
    }
    cout<<cnt<<endl;
    return 0;
}
