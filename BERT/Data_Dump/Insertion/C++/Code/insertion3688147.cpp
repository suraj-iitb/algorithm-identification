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
    int temp=0;
    for(int i=0;i<n;i++){
        temp=a[i];
        for(int j=0;j<SortDone;j++){
            if(a[i]<=a[j]){
                for(int k=i;k>j;k--){
                    a[k]=a[k-1];
                }
                a[j]=temp;
                break;
            }
        }
        for (int p=0;p<n-1;p++)
            cout<<a[p]<<" ";
        cout<<a[n-1];
        if(SortDone!=n)
            cout<<endl;
        SortDone++;
    }
    return 0;
}

