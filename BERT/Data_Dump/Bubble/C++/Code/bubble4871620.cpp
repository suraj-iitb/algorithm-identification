#include<iostream>
#include<cstdio>
using namespace std;
int bubleSort(int a[], int n){
    int j, i, count=0;
    for(i=1; i<n; i++){
        for(j=0; j<n-i; j++){
            if(a[j] > a[j+1]){
                int t = a[j+1];
                a[j+1] = a[j];
                a[j] = t;
                count++;
            }
        }
    }
    return count;
}

int main(int argc, char *argv[]){
    int a[100], n, count, i;
    scanf("%d", &n);
    for(i=0; i<n; i++)
        scanf("%d", &a[i]);
    count = bubleSort(a, n);
    for(i=0; i<n-1; i++)
        printf("%d ", a[i]);
    printf("%d\n%d\n", a[i], count);

    return 0;
}
