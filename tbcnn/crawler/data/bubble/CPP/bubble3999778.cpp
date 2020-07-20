#include<iostream>
using namespace std;


int bsort(int n,int a[]){
    bool flag=1;
    int count=0;
    for(int j=0;flag;j++){
        flag=0;
        for(int i=n-1;i>j;i--){
            if(a[i]<a[i-1]){
            swap(a[i],a[i-1]);
            flag=1;
            count++;
            }
        }
        
    }
    return count;
}

int main(void){
    
    int n;
    cin>>n;
    int array[100];
    int count;
    
    for(int i=0;i<n;i++)
    cin>>array[i];
    
    count=bsort(n,array);
    
    for(int j=0;j<n;j++){
        if(j)cout<<" ";
        cout<<array[j];
    }
    cout<<endl;
    
    cout<<count<<endl;
    
    return 0;
    
}

