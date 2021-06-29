//
//  main.cpp
//  selection_sort
//
//  Created by ???????????? on 2017/10/02.
//  Copyright ?? 2017 ????????????. All rights reserved.
//

#include <iostream>
#include<stdio.h>

using namespace std;

int N = 1000;

void swap(int* a, int* b){
    int temp = *a;
    *a = *b;
    *b = temp;
}

int main(int argc, const char * argv[]) {
    
    int n, i, j, minj, sw;
    int A[N];
    
    //get n and A
    scanf("%d", &n);
    for ( i = 0; i < n; i++ ) scanf("%d", &A[i]);
    
    sw = 0;
    for(i = 0; i < n-1; i++){
        minj = i;
        for(j = i+1; j < n; j++){
            if(A[minj] > A[j]){
                minj = j;
            }
        }
        if(i!=minj){
            sw++;
            swap(&A[i], &A[minj]);
        }
    }
    
    for(i = 0; i < n; i++){
        if(i){cout<<" ";}
        cout << A[i];
    }
    cout << endl;
    cout << sw << endl;
    return 0;
}
