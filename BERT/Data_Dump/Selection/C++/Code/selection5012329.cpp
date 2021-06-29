#include<bits/stdc++.h>
using namespace std;

void cout_array(int n,int* arrays){
    for(int i=0;i<n;i++){
        if(i != n-1){
            cout<<arrays[i]<<" ";
        }else{
            cout<<arrays[i]<<endl;
        }
        
    }
}

int *selection_sort(int n,int* A){
    int changetime=0;
    for(int i=0; i<n+1;i++){
        int min =A[i],min_num=i;
        for(int j= i+1;j<n;j++){
            if(min>A[j]){
                min=A[j];
                min_num=j;
            }
        }
        if(min<A[i]){
            A[min_num]=A[i];
            A[i]=min;
            changetime++;
        }
    }
    cout_array(n,A);
    cout<<changetime<<endl;
    return A;
}

int main(){
    int len;
    cin>>len;
    int *unsorted=new int[len],*sorted=new int[len];
    for(int i=0;i<len;i++){
        cin>>unsorted[i];
    }
    sorted=selection_sort(len,unsorted);
    return 0;
}
