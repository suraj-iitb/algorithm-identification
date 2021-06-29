#include<iostream>
using namespace std;

int main(){
    int n;
    cin>>n;
    int* array = new int[n];
    for(int i=0;i<n;i++){
        cin>>array[i];
    }
    for(int i=0;i<n;++i){
        int x=array[i];
        int j=i-1;
        while(j>=0 && array[j]>x){
            array[j+1]=array[j];
            --j;
        }
        array[j+1]=x;
        for(int k=0;k<n;++k){
            cout<<array[k];
            if(k!=n-1)
                cout<<" ";
        }
        cout<<"\n";
    }
}
