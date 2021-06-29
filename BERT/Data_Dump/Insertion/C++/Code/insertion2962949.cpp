#include<iostream>
using namespace std;
void printArray(int p[],int n){
    for(int i=0;i<n-1;i++)
      cout<<p[i]<<' ';
      cout<<p[n-1]<<endl;
}
void insertionSort(int p[],int n){
    int t;
    for(int i=1;i<n;i++){
        t=p[i];
        int j=i-1;
        for(;j>=0;j--){
            if(p[j]>t)
                p[j+1]=p[j];
            else
                break;
        }
        p[j+1]=t;
      printArray(p,n);
        
    }
   
}
int main(){
    int n;
    cin>>n;
    int *p=new int[n];
    for(int i=0;i<n;i++) cin>>p[i];
    printArray(p,n);
    insertionSort(p,n);
    
    return 0;
}
