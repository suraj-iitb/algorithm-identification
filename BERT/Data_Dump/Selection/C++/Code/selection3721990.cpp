#include<iostream>

using namespace std;

static int sw=0;

void selectionSort(int a[], int n){
    for(int i=0;i<n;i++){// i: start index of non-sorted
        int minj=i;

        int j;
        for(j=i+1;j<n;j++){   // swap start index of non-sorted and min 
            if(a[j]<a[minj]){
                minj=j;
            }
        }
        if(i!=minj){    // actually swapping
            swap(a[i],a[minj]);
            sw++;
        }
        
    }
}

int main(){

    int n;
    cin>>n;
    int a[n];
    for(int i=0;i<n;i++)cin>>a[i];

    selectionSort(a,n);

    for(int i=0;i<n;i++){
        if(i)cout<<" ";
        cout<<a[i];
    }
    cout<<endl;
    cout<<sw<<endl;

    return 0;
}
