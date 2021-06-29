#include<iostream>
using namespace std;
int bubbleSort(int p[],int n)
{
    int flag=1;
    int count=0;
    for(int i=0;i<n-1;i++){
        if(!flag)break;
        flag=0;
        for(int j=n-1;j>i;j--)
           if(p[j]<p[j-1]){
               flag=1;
               int t=p[j];
               p[j]=p[j-1];
               p[j-1]=t;
               count++;
           }
    }
    return count;
}
int main(){
    int n;
    cin>>n;
    int *p=new int[n];
    for(int i=0;i<n;i++) cin>>p[i];
    
    int m=bubbleSort(p,n);
    for(int i=0;i<n-1;i++) 
        cout<<p[i]<<' ';
    cout<<p[n-1]<<endl;
    cout<<m<<endl;
    
    
}
