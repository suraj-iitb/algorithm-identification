//
//  BubbleSort.cpp
//  Algorithm
//
//  Created by hongb Xu on 2020/9/1.
//  Copyright © 2020 hongb Xu. All rights reserved.
//

#include <iostream>
using namespace std;

//使用flag的冒泡排序法
int bubbleSort(int A[], int N) {
    int sw = 0;
    bool flag = 1;
    for(int i=0; flag; i++){
        flag = 0;
        for(int j=N-1; j>=i+1; j--){
            if(A[j] < A[j-1]){
                //交换相邻元素
                swap(A[j], A[j-1]);
                flag = 1;
                sw++;
            }
        }
    }
    return sw;
}

int main(){
    int A[100], N, sw;
    cin >> N;
    for(int i=0; i<N; i++) cin >> A[i];
    sw = bubbleSort(A, N);
    for(int i=0; i<N; i++){
        if(i) cout << " ";
        cout << A[i];
    }
    cout << endl;
    cout << sw << endl;
    return 0;
}




