#include <stdio.h>

void insertionSort(int *, int);

int main(){
    int n, i,j, key;
    scanf("%d", &n);
    int a[100];

    for(i = 0; i < n; i++)
        scanf("%d", &a[i]);

    for(j = 0; j < n; j++){
        printf("%d", a[j]);
        if(j + 1 < n)
            printf(" ");
        else 
            printf("\n");
    }

    insertionSort(a, n);

    return 0;
}

void insertionSort(int a[100], int n)
{
    //printf("%d", n);
    int i, j ,s, v;
    for (i = 1; i < n ; i++){
        v = a[i];
        j = i - 1;

        //printf("%d\n", i);
        while(j >= 0 && a[j] > v) {
            a[j + 1] = a[j];
            j--;
            a[j  + 1] = v;
        }
        for (s = 0; s < n; s++){
            printf("%d", a[s]);
            if (s + 1 < n){
                printf(" ");
            } else{
                printf("\n");
            }
        }
    }
}

