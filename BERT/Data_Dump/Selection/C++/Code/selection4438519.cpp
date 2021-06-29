#include<iostream>
#include<math.h>
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

int bubble_sort(int array[],int n){
    int count = 0;
   for(int i = 0;i < n;i++){
       for(int j = n-1;j> i;j--){
           if(array[j] < array[j-1]){
               int temp = array[j];
               array[j] = array[j - 1];
               array[j - 1] = temp;
               count++;
           }
       }
   }
   for(int k = 0;k<n;k++){
       cout<<array[k]<<" ";
       if(k == n-1){
           cout<<endl;
       }
   }
   cout<<count<<endl;
   return count;
}

int selectionSort(int array[],int n){
    int count = 0;
    for(int i = 0;i<n;i++){
        int min = i;
        for(int j = i;j<n;j++){
            if(array[j] < array[min]){
                min = j;       
            }
        }
        if(i != min){
            int temp = array[i];
            array[i] = array[min];
            array[min] = temp;
            count++;
        }
    }
    for(int k = 0;k<n;k++){
        if(k < n-1){
        cout<<array[k]<<" ";
        }
       else{
           cout<<array[k]<<endl;
       }
   }
   cout<<count<<endl;
   return count;
}

int main(){
    int n,a,b;
    cin>>n;
    int array[100] = {0};
    for(int i = 0;i<n;i++){
        cin>>array[i];           
    }
    int count = selectionSort(array,n);
    
}
