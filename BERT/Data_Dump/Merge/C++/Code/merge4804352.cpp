#include <iostream>
#include <cmath>
#include <algorithm>
#include <climits>
#include <string>
#include <vector>
using namespace std;

#define MAX 500000 
#define SENTINEL 20000000  // 番兵のための値

int L[MAX/2+2], R[MAX/2+2]; // マージソートで分割した配列
int cmp_count;


void merge(int A[],int left,int mid, int right){
    
    //cout << "left = " << left << " right = " << right << endl;
    int n1 = mid - left;
    int n2 = right - mid;
    int L[n1+1],R[n2+1];
    
    for(int i = 0; i < n1; i++) L[i] = A[left + i];
    for(int i = 0; i < n2; i++) R[i] = A[mid + i];
    
    L[n1] = R[n2] =  INT_MAX;

    int i = 0, j = 0;
    for(int k = left;k < right; k++){
        //cout << L[i] << " " << R[j] << " ";
        if(L[i] <= R[j]){
            A[k] = L[i++];
            cmp_count++;
        }else{
            A[k] = R[j++];
            cmp_count++;
        }
        //cout << A[k] << " k = " << k << endl;
    }
}

void merge_Sort(int A[], int left, int right){
    
    if( left + 1 < right){
        int mid = (left + right) / 2;
        merge_Sort(A, left, mid);
        merge_Sort(A, mid, right);
        merge(A, left, mid, right);
    }
}



int main(void){
    
    int A[MAX], n;
    cmp_count = 0;
    
    cin >> n;
    for(int i = 0; i < n; i++) cin >> A[i];
    
    merge_Sort(A, 0, n);
    
    for(int i = 0; i < n; i++){
        if( i ) cout << " ";
        cout << A[i];
    }
    cout << endl;
    
    cout << cmp_count << endl;
    
}


