#include<stdio.h>

int selectionSort(int a[], int n){
    int i, j, t, sw = 0, mini;
    for(i = 0; i < n-1; i++){
        mini = i;
        for( j=i; j < n; j++){
            if( a[j] < a[mini])mini = j;
        }
        t = a[i];
        a[i] = a[mini];
        a[mini]=t;
        if(i != mini)sw++;
    }
    return sw;
}

int main(){
    int a[100], n, i, sw;

    scanf("%d", &n);
    for( i=0; i < n; i++)scanf("%d", &a[i]);

    sw = selectionSort(a, n);

    for(i = 0; i < n; i++){
        if( i > 0)printf(" ");
        printf("%d", a[i]);
    }
    printf("\n");
    printf("%d\n", sw);

    return 0;
}
