#include <stdio.h>
#include <iostream>
using namespace std;

void insertionsort(int *num, int n) {
    for(int i=0; i<n; i++) {
        int v = num[i];
        int j = i - 1;

        while(j>=0 && num[j]>v) {
            num[j+1] = num[j];
            j--;
        }
        num[j+1] = v;
        for(int m=0; m<n; m++) {
            printf("%d", num[m]);
            if(m!=n-1) {
                printf(" ");
            }
        }
        printf("\n");
    }
}

int main() {
    int n;
    cin >> n;

    int num[n];
    for(int i=0; i<n; i++) {
        cin >> num[i];
    }
    insertionsort(num, n);
}
