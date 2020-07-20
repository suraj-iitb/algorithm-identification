#include<iostream>
using namespace std;

int main()
{
    int n;
    cin>>n;
    int *a=new int [n];
    for(int i=0;i<n;i++)
        cin>>a[i];
    int SortDone=0;
    int times=0;
    while(SortDone<n){
        for(int i=n-1;i>SortDone;i--){
            if(a[i]<a[i-1]){
                swap(a[i],a[i-1]);
                times++;
            }
        }
        SortDone++;
    }
    for(int i=0;i<n-1;i++)
        cout<<a[i]<<" ";
    cout<<a[n-1]<<endl;
    cout<<times<<endl;
    return 0;
}

