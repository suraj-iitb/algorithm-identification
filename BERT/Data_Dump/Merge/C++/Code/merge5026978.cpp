#include<iostream>
#include<limits.h>
using namespace std;
int changetime=0;
void cout_array(int n,int* arrays){
    for(int i=0;i<n;i++){
        if(i != n-1){
            cout<<arrays[i]<<" ";
        }else{
            cout<<arrays[i]<<endl;
        }
        
    }
}
int *mergesort(int lft,int rgt,int *A,int depth){
    int mid=(lft+rgt)/2;
    if(lft==mid){
        return A;
    }else{
        int *B=new int[mid-lft];
        int *C=new int[rgt-mid];
        for(int i=0;i<mid-lft;i++){
            B[i]=A[lft+i];
        }
        for(int i=0;i<rgt-mid;i++){
            C[i]=A[mid+i];
        }
        B=mergesort(0,mid-lft,B,depth+1);
        C=mergesort(0,rgt-mid,C,depth+1);
        B[mid-lft]=INT_MAX;
        C[rgt-mid]=INT_MAX;
        int i=0,j=0;
        for(int k=0;k<rgt-lft;k++){
            if(B[i]<C[j]){
                A[k]=B[i];
                i++;
                changetime++;
            }else if(B[i]>C[j]){
                A[k]=C[j];
                j++;
                changetime++;
            }else{
                A[k]=B[i];
                i++;
                changetime++;
            }
        }
        if(depth==0){
            cout_array(rgt,A);
            cout<<changetime<<endl;
        }
        return A;
    }
}
int main(){
    int thelen;
    cin>>thelen;
    int *unsorted=new int[thelen];
    for(int i=0;i<thelen;i++)cin>>unsorted[i];
    int *sorted=new int[thelen];
    sorted=mergesort(0,thelen,unsorted,0);
    return 0;
}
