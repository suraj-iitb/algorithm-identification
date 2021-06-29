#include<iostream>
#include<cstdio>

using namespace std;
int selectionSort(int a[], int n){
    int i, j, minj, count=0;
    for(i=0; i<n; i++){
        minj = i;
        for(j=i; j<n; j++){
            if(a[j] < a[minj])
                minj = j;
        }
        swap(a[i], a[minj]);
        if(i!=minj)
            count++;
    }
    return count;
}

int main(int argc, char *argv[]){
    int a[100], n, count, i;
    scanf("%d", &n);
    for(i=0; i<n; i++)
        scanf("%d", &a[i]);
    count = selectionSort(a, n);
    for(i=0; i<n-1; i++)
        printf("%d ", a[i]);
    printf("%d\n%d\n", a[i], count);

    return 0;
}
