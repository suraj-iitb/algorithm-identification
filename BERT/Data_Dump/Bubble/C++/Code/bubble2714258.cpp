#include <stdio.h>
#include <iostream>
#include <algorithm>
using namespace std;

int bubbleSort(int *num, int n) {
    int flag = 1;
    int count = 0;
    
    while(flag) {
        flag = 0;
        for(int j=n-1; 0<j; j--) {
            if(num[j]<num[j-1]) {
                swap(num[j], num[j-1]);
                flag = 1;
                count++;
            }
        }
    }
    return count;
}

int main() {
    int n;
    int count = 0;
    cin >> n;
    
    int num[n];
    for(int i=0; i<n; i++) {
        cin >> num[i];
    }
    count = bubbleSort(num, n);
    
    for(int i=0; i<n; i++) {
        printf("%d", num[i]);
        if(i!=n-1) {
            printf(" ");
        }
    }
    printf("\n");
    printf("%d\n", count);
}
