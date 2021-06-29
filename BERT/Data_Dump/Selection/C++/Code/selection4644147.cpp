#include<iostream>

using namespace std;
/*
 * 选择排序思路：
 * 1. 进行n-1次循环，执行2、3、4操作
 * 2. 设置变量i标记已排序位置的末尾后一位
 * 3. 设置pos变量标记未排序中最小（大）数的位置
 * 4. 将i位置的值与pos位置的值进行交换
 * */

int selectionSort(int a[], int n){
    int count = 0;
    for (int i = 0; i < n-1; i++){
        int pos = i;
        for (int j = i; j < n; j++){
            if (a[j] < a[pos]){
                pos = j;
            }
        }
        swap(a[pos], a[i]);
        if (a[pos] != a[i]){
            count++;
        }
    }
    return count;
}

int main(){
    int n, a[100];
    cin>>n;
    for (int i = 0; i < n; i++){
        cin>>a[i];
    }
    int count = selectionSort(a, n);
    for (int i = 0; i < n; i++){
        if (i != n-1){
            cout<<a[i]<<" ";
        }else{
            cout<<a[i]<<endl;
        }
    }
    cout<<count<<endl;
}
