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
int bubbleSort(int a[],int n){
    int flag = 1;
    int switchNum = 0;
    while(flag){
        flag = 0;
        for(int i=n-1;i>0;i--){
            if(a[i]<a[i-1]){
                int temp = a[i];
                a[i] = a[i-1];
                a[i-1] = temp;
                switchNum = switchNum + 1;
                flag = 1;
            }
        }
    }
    return switchNum;
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
        num = bubbleSort(a,n);
        printArray(a,n);
        cout << num << endl;
    }else{
        return 0;
    }
    return 0;
}
