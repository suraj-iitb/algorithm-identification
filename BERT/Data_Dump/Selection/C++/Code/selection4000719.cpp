#include<iostream>
using namespace std;

int ssort(int a[],int n){
    int min;
    int count=0;
    for(int i=0;i<n-1;i++){
        min=i;
        for(int j=i;j<n;j++){
            if(a[j]<a[min])
                min=j;
            
        }
        if(i!=min){
        swap(a[min],a[i]);
        count++;
        }
    }
    
    
    return count;
}


int main (void){
    int n;
    cin>>n;
    
    int a[200];
    for(int i=0;i<n;i++)
    cin>>a[i];
    
    int count;
    count=ssort(a,n);
    
    for(int i=0;i<n;i++){
        if(i)cout<<" ";
        cout<<a[i];
    }
    cout<<endl;
    cout<<count<<endl;
    
}




