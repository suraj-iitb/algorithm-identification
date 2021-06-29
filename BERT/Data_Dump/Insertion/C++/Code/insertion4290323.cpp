#include<iostream>
using namespace std;
void insertion_sort(int array[],int n){
    for(int i = 1;i<n;i++){
       int key = array[i];
       int j = i-1;
       while(j>=0 && array[j] > key){
           array[j+1] = array[j];
           j = j-1;
       }
       array[j+1] = key;
       for(int k =0;k<n;k++){
           
           if(k == n-1){
               cout<<array[k]<<endl;
           }else{
               cout<<array[k]<<" ";
           }
       }
    }
}
int main(){
    int n;
    cin>>n;
    int array[100];
    for(int i =0;i<n;i++){
        cin>>array[i];
        
        if(i == n-1){
            cout<<array[i]<<endl;
        }else{
            cout<<array[i]<<" ";
        }
    }
    insertion_sort(array,n);
}
