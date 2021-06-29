#include<stdio.h>
#define MAX 100
int number[MAX] = {0};
void insertionSort(int *, int);

int main(){
    int n, i;

    scanf("%d\n", &n);

    for(i = 0; i < n; i++) {
        scanf("%d ", number+i);  
    }
    for(i = 0; i < n - 1; i++) {
        printf("%d ", number[i]);
    }
    printf("%d\n", number[n-1]);

    insertionSort(number, n);
}

void insertionSort(int *c, int n){

    int i, j, k;
    int v;

    for(i = 1; i < n; i++) {
        v = *(c+i);
        j = i - 1;
        while((j >= 0) && (*(c+j) > v)) {
            *(c + j + 1) = *(c + j);
            j--;
        }
        *(c + j + 1) = v;
        for(k = 0; k < n - 1; k++) {
            printf("%d ", *(c + k));
        }
        printf("%d\n", *(c + n - 1));
    }

}
