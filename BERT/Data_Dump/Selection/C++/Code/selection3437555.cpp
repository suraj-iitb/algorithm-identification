//
//  ALDS1_2_B_SelectionSort.cpp
//  test
//
//  Created by Sajor on 2019/3/21.
//  Copyright © 2019年 Sajor. All rights reserved.
//

#include <iostream>
using namespace std;
#define MAX_N 105

void print(int a[], int n){
    for(int i=0; i<n; i++){
        if (i>0) cout << " ";
        cout << a[i];
    }
    cout << endl;
}

int selectionSort(int *a, int n){
    int count = 0, mini_n;
    
    for(int i=0; i<n; i++){
        mini_n = i;
        for(int j=i; j<n; j++){
            if(a[j] < a[mini_n])
                mini_n = j;
        }
        if (mini_n != i){
            a[mini_n] ^= a[i];
            a[i] ^= a[mini_n];
            a[mini_n] ^= a[i];
            count++;
        }
    }
    
    return count;
}

int main()
{
    int N, a[MAX_N];
    cin >> N;
    for (int i=0; i<N; i++){
        cin >> a[i];
    }
    int c = selectionSort(a, N);
    print(a, N);
    cout << c << endl;
    return 0;
}

