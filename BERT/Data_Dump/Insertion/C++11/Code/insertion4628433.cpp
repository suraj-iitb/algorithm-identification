#include<iostream>

using namespace std;
// 插入排序思路：
// 1. 将第i个位置的元素的值保存，即v = a[i]；
// 2. 从第i-1个元素开始依次向前挪动一位,给即将插入的元素腾出位置，即a[i] = a[i-1]; i--;
// 3. 直到插入位置j，挪动停止，即a[j] = v;
// 4. 重复以上三步，直到最后一个元素归位


/*输出函数*/
void trace(int a[], int n){
    for (int i = 0; i < n; i++){
        if (i != n-1){
            printf("%d ", a[i]);
        }else{
            printf("%d\n", a[i]);
        }
    }
}


/*插入排序函数*/
void insertionSort(int a[], int n){
    int j , v;
    // 题目要求，未排序时也要输出一次
    trace(a, n);
    for (int i = 1; i < n; i++){
        v = a[i];
        j = i-1;
        while(j >= 0&& a[j] > v){
            a[j+1] = a[j];
            j--;
        }
        a[j+1] = v;
        // 题目要求，每归位一个输出一次
        trace(a, n);
    }
}

int main(){
    int n, i;
    int a[100];
    scanf("%d", &n);
    for (int i = 0; i < n; i++){
        scanf("%d", &a[i]);
    }
    insertionSort(a, n);
    return 0;
}
