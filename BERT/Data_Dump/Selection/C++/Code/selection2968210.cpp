#include<iostream>
using namespace std;
int selectionSort(int p[],int n){
    int sw=0;
    int min=0;
    for(int i=0;i<n-1;++i){
        min=i;
        for(int j=i+1;j<n;++j){
            if(p[j]<p[min])
               min=j;
        }
        if(min!=i){int t=p[i];p[i]=p[min];p[min]=t;sw++;}
    }
    return sw;
}
int main(){
    int n;
    cin>>n;
    int *p=new int[n];
    for(int i=0;i<n;++i)cin>>p[i];
    
    int m=selectionSort(p,n);
    
    for(int i=0;i<n-1;++i)cout<<p[i]<<' ';
    cout<<p[n-1]<<endl;
    cout<<m<<endl;
    return 0;
    
}
