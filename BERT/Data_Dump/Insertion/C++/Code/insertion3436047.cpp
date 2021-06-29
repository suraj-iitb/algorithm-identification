//
//  InsertionSort.cpp
//  test
//
//  Created by Sajor on 2019/3/20.
//  Copyright © 2019年 Sajor. All rights reserved.
//

#include <cstdio>
#include <iostream>
using namespace std;

void print(int a[], int n){
    for(int i=0; i<n; i++){
        if (i>0) cout << " ";
        cout << a[i];
    }
    cout << endl;
}

void insertion_sort(int a[], int n){
    int v, j;
    for(int i=1; i<n; i++){
        v = a[i];
        j = i - 1;
        while(j>=0 && a[j]>v) {
            a[j+1] = a[j];
            j--;
        }
        a[j+1] = v;
        print(a, n);
    }
}

int main()
{
    int N, a[105];
    cin >> N;
    for(int i=0; i<N; i++){
        cin >> a[i];
    }
    print(a, N);
    insertion_sort(a, N);
    return 0;
}

