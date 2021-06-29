#include<bits/stdc++.h>
using namespace std;
void insertion_sort(int *a, int n){
    for(int k = 0;k < n; k++){
        if(k != n-1){
            printf("%d ",a[k]);
        }else{
            printf("%d\n",a[k]);
        }
    }
    for(int i=1;i<n;i++){
        int key = a[i];
        int j = i-1;
        while(j>=0 and a[j]>key){
            a[j+1] = a[j];
            j--;
        }
        a[j+1]= key;
        for(int k = 0;k < n; k++){
        if(k != n-1){
            printf("%d ",a[k]);
        }else{
            printf("%d\n",a[k]);
        }
        }
    }
}
int main(){
    int n;
    cin>>n;
    int a[n];
    for(int i=0;i<n;i++)cin>>a[i];
    insertion_sort(a,n);
    return 0;
}
