//
//  ALDS1_2_A_BubbleSort.cpp
//  test
//
//  Created by Sajor on 2019/3/21.
//  Copyright © 2019年 Sajor. All rights reserved.
//

#include <iostream>
using namespace std;
# define MAX_N 105

void print(int a[], int n){
    for(int i=0; i<n; i++){
        if (i>0) cout << " ";
        cout << a[i];
    }
    cout << endl;
}

int bubbleSort(int *a, int n){
    int count=0;
    for (int i=1; i<n; i++){
        for (int j=0; j<n-i; j++){
            if(a[j]>a[j+1]){
                a[j] ^= a[j+1];
                a[j+1] ^= a[j];
                a[j] ^= a[j+1];
                count++;
            }
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
    int c = bubbleSort(a, N);
    print(a, N);
    cout << c << endl;
    return 0;
}

