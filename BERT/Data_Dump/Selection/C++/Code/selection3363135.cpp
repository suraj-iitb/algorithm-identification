#include<iostream>
#include<algorithm>
using namespace std;

int selectionSort(int a[],int n){
    int c = 0;

    for(int i = 0;i<n;i++){
        int minj=i;
        for(int j=i+1;j<n;j++){
            if(a[minj]>a[j])minj=j;
        }
        if(minj!=i){
            swap(a[minj],a[i]);
            c++;
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

    int c = selectionSort(a,n);

    cout<<c<<endl;

    return 0;
}
