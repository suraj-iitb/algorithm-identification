#include<iostream>

using namespace std;
/*
 * 冒泡排序思路：
 * 1. 进行n-1轮冒泡
 * 2. 每一轮冒泡排序，通过相邻元素比较和交换将排序后的最后一个元素归位
 * */

int bubbleSort(int a[], int n){
    int count = 0;
    for (int i = 0; i < n-1; i++){
        for (int j = 0; j < n-i-1; j++){
            if (a[j] > a[j+1]){
                swap(a[j], a[j+1]);
                count++;
            }
        }
    }
    return count;
}

int main(){
    int n, count;
    int a[100];
    cin>>n;
    for (int i = 0; i < n; i++){
        cin>>a[i];
    }
    count = bubbleSort(a, n);
    for (int i = 0; i < n; i++){
        if (i != n-1){
            cout<<a[i]<<" ";
        }else{
            cout<<a[i]<<endl;
        }
    }
    cout<<count<<endl;
    return 0;
}
