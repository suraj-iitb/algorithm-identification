#include <iostream>
#include <algorithm>
using namespace std;
void printArray(int a[],int n){
    for(int i=0;i<n;i++){
        cout << a[i];
        if(i<n-1){
            cout << " ";
        }
    }
    cout << endl;
}
void insertSort(int a[],int n){
    for(int i=1;i<n;i++){
        int v = a[i];
        int j = i - 1;
        while(j>=0 && a[j]>v){
            a[j+1] = a[j];
            j--;
        }
        a[j+1] = v;
        printArray(a,n);
    }
}
int main(){
    int n;
    cin >> n;
    int a[n];
    if(n>=1 && n<=100){
        for(int i=0;i<n;i++){
            cin >> a[i];
        }
        printArray(a,n);
        insertSort(a,n);
    }else{
        return 0;
    }
    return 0;
}
