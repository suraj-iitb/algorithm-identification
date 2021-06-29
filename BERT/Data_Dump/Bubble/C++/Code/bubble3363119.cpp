#include<iostream>
using namespace std;

int bubbleSort(int a[],int n){

    int c = 0;
    for(int i=0;i<n-1;i++){
        for(int j=n-1;j>0;j--){
            if(a[j]<a[j-1]){
                int tmp = a[j];
                a[j]=a[j-1];
                a[j-1]=tmp;
                c++;
            }
        }
    }

    for(int i=0;i<n;i++){
        cout<<a[i];
        if(i!=n-1)cout<<" ";
    }
    cout<<endl;

    return c;
}

int main(void){

    int n;
    cin >> n;
    int a[n];
    for(int i=0;i<n;i++)cin>>a[i];

    int c = bubbleSort(a,n);

    cout<<c<<endl;

    return 0;
}
