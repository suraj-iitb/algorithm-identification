#include<iostream>
using namespace std;

void bubbleSort(int a[],int n){
    int c=0;
    for(int i=0;i<n;i++){
        for(int j=n-1;j>i;j--){
            if(a[j-1]>a[j]){
                swap(a[j-1],a[j]);
                c++;
            }
        }
    }
    for(int i=0;i<n;i++) cout<<a[i]<<((i==n-1)?'\n':' ');
    cout<<c<<endl;
}

int main(){
    int n,a[100];
    cin>>n;
    for(int i=0;i<n;i++) cin>>a[i];
    bubbleSort(a,n);
}
