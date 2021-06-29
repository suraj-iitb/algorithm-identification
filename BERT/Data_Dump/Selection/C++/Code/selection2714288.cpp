#include <stdio.h>
#include <iostream>
#include <algorithm>
using namespace std;

int selectionSort(int *num, int n) {
    int minj = 0;
    int count = 0;
    int i, j;
    for(i=0; i<n; i++) {
        minj = i;
        for(j=i; j<n; j++) {
            if(num[j]<num[minj]) {
                minj = j;
            }
        }
        swap(num[i], num[minj]);
        if(minj!=i) {
            count++;
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
    
    count = selectionSort(num, n);
    for(int i=0; i<n; i++) {
        printf("%d", num[i]);
        if(i!=n-1) {
            printf(" ");
        }
    }
    printf("\n");
    printf("%d\n", count);
    
   return 0;
}
