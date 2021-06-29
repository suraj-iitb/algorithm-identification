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
int selectionSort(int a[],int n){
    int sortNum = 0;
    for(int i=0;i<n;i++){
        int minj = i;
        for(int j=i;j<n;j++){
            if(a[j]<a[minj]){
                minj = j;
            }
        }
        if(i != minj){
            int temp = a[i];
            a[i] = a[minj];
            a[minj] = temp;
            sortNum = sortNum + 1;
        }
    }
    return sortNum;
}
int main(){
    int n;
    cin >> n;
    int a[n];
    int num;
    if(n>=1 && n<=100){
        for(int i=0;i<n;i++){
            cin >> a[i];
        }
        num = selectionSort(a,n);
        printArray(a,n);
        cout << num << endl;
    }else{
        return 0;
    }
    return 0;
}
