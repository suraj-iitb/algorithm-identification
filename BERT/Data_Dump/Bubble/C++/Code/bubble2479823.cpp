#include <algorithm>
#include <iostream>
#include <stdio.h>

//?????\?????????

const int MAX = 100;

using namespace std;

//?????????????´?????????????????????????
void trace(int a[],int n){
    for (int i=0;i<n;i++){
        if(i>0){cout << " ";}
        cout << a[i];
    }
    cout << endl;
}

int BubbleSort(int a[],int n){
    bool flag=true;
    int num=0;
    while(flag){
        flag=false;
        for(int i=n-1;i>0;i--){
            if(a[i]<a[i-1]){
                swap(a[i],a[i-1]);
                flag=true;
                num++;
            }
        }
    }
    trace(a, n);
    return num;
}

int main(){
    int A[MAX],n;
    cin >> n;
    for(int i=0;i<n;i++){
        scanf("%d", &A[i]);
    }
    cout << BubbleSort(A, n)<<endl;

    return 0;
}
