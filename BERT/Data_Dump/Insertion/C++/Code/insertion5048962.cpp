#include <iostream>
#include <algorithm>
using namespace std;

const int N = 1e5+3;
int a[104] ,n;

void insertionSort(){

    for(int i=1;i<n;i++){

        int k = a[i] , j=i-1;
        while(j>=0 && a[j]>k){
            a[j+1] =a[j];
            j--;
        }
        a[j+1]=k;

        for(int i=0;i<n;i++)
            i+1==n?cout<<a[i]<<"\n":cout<<a[i]<<" ";
    }
}

int main(){

    cin>>n;
    for(int i=0;i<n;i++)
        cin>>a[i];
     for(int i=0;i<n;i++)
            i+1==n?cout<<a[i]<<"\n":cout<<a[i]<<" ";
    insertionSort();
    



  

    return 0;
}
