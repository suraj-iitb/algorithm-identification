#include<iostream>
using namespace std;
int main()
{
    int n;
    cin>>n;
    int *a=new int [n];
    for(int i=0;i<n;i++)
        cin>>a[i];
    int SortNext=0;
    int times=0;
    int Min=0;
    int Min_i=0;
    while(SortNext<n){
        Min=a[SortNext];
        Min_i=SortNext;
        for(int i=SortNext;i<n;i++){
            if (a[i]<Min){
                Min=a[i];
                Min_i=i;
            }
        }
        if(Min_i!=SortNext){
            swap(a[Min_i],a[SortNext]);
            times++;
            SortNext++;
        }
        else{
            SortNext++;
        }
    }
    for(int i=0;i<n-1;i++)
        cout<<a[i]<<" ";
    cout<<a[n-1]<<endl;
    cout<<times<<endl;

    return 0;
}

