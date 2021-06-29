//
//  main.cpp
//  merge_sort
//
//  Created by ???????????? on 2017/10/08.
//  Copyright ?? 2017 ????????????. All rights reserved.
//

#include <iostream>
#include <stdio.h>
#include <cmath>
#include <climits>

using namespace std;

int ct = 0;

void merge(int S[], int left, int mid, int right){
    int i, j, k, n1, n2;
    n1 = mid - left;
    n2 = right - mid;
    int L[n1+1], R[n2+1];
    for (i = 0; i < n1; i++){
        L[i] = S[left+i];
    }
    for (i = 0; i < n2; i++){
        R[i] = S[mid+i];
    }
    L[n1] = INT_MAX;
    R[n2] = INT_MAX;

    
    i = 0;
    j = 0;
    
    for( k = left; k < right; k++ ){
        ct++;
        if(L[i] <= R[j]){
            S[k] = L[i];
            i++;
        }
        else{
            S[k] = R[j];
            j++;
        }
    }
    
    
}


void merge_sort(int S[], int left, int right){
    if (left+1 < right){
        int mid = (left + right)/2;
        merge_sort(S, left, mid);
        merge_sort(S, mid, right);
        merge(S, left, mid, right);
    }
}


int main(int argc, const char * argv[]) {
    int n, i;
    scanf("%d", &n);
    int S[n];
    for (i = 0; i < n; i++){
        scanf("%d", &S[i]);
    }
    merge_sort(S, 0, n);
    for (i = 0; i < n; i++){
        if(i)cout << " ";
        cout<<S[i];
    }
    cout << endl;
    cout << ct << endl;
    

    return 0;
}
