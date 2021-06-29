#include <bits/stdc++.h>
using namespace std;
void display(int a[], int n) {
    for(int i = 0; i < n; i++) {
        if(i > 0) printf(" "); 
        printf("%d", a[i]);
    }
    printf("\n");
}
void insertion_sort(int a[], int n) {
    int j;
    int v;
    for(int i = 1; i < n; i++) {
        v = a[i];
        j = i - 1;
        while(j >= 0 && a[j] > v) {
            a[j+1] = a[j];
            j--;
        }
        a[j+1] = v;
        display(a, n);
    }
}
int main(){
    int n;
    scanf("%d", &n);
    int a[100];
    for(int i = 0; i < n; i++) scanf("%d", &a[i]);
    display(a, n);
    insertion_sort(a, n);
    return 0;
}
