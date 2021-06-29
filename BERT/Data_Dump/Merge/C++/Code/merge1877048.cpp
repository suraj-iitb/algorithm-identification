 #include <iostream>
#include <stdlib.h>
#include <stdio.h>      /* printf */
#include <math.h>       /* pow */
#include <vector>
#include <stack>
#include <algorithm>
#include <string>
#include <climits>

typedef std::vector<int> liste;
typedef liste::const_iterator iter;

void print_array(liste list) {
    for(int i = 0; i < list.size(); ++i){
        if(i>0) std::cout << " ";
        std::cout << list[i];
    }
    std::cout << std::endl;
}

void merge(liste& A,int left,int mid,int right,int& comp) {
    int n1 = mid - left;
    int n2 = right - mid;
    iter firstL = A.begin() + left;
    iter lastL = A.begin() + left + n1;
    liste L(firstL, lastL);
    iter firstR = A.begin() + mid;
    iter lastR = A.begin() + mid + n2;
    liste R(firstR, lastR);
    
    int INFTY = INT_MAX;
    L.push_back(INFTY);
    R.push_back(INFTY);
    int i = 0;
    int j = 0;
    for(int k=left; k<right;k++) {
        comp++;
        if (L[i] <= R[j]) {
            A[k] = L[i];
            i++;
        } else {
            A[k] = R[j];
            j++;
        }
    }
}

void mergeSort(liste& A,int left,int right,int& comp) {
    if (left+1 < right) {
        int mid = floor((left + right)/2);
        mergeSort(A, left, mid, comp);
        mergeSort(A, mid, right, comp);
        merge(A, left, mid, right, comp);
    }
}    
    
int main(void){
        
    std::cin.tie(0);
    std::ios::sync_with_stdio(false);
    int value;
    liste list;
    int n;
    std::cin >> n;
    for(int i=0; i<n; i++) {
        std::cin >> value;
        list.push_back(value);
    } 
    
    int comp=0;
    mergeSort(list,0,list.size(),comp);
    print_array(list);
    std::cout << comp << std::endl;
    return 0;
}
