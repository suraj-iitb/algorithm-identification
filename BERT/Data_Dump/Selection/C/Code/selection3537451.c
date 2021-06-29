#include<stdio.h>
#define MAX 100
int number[MAX] = {0};
void selectionSort(int *, int);

int main(){
    int n, i;

    scanf("%d\n", &n);

    scanf("%d", number);
    for(i = 1; i < n ; i++) {
        scanf(" %d", number + i);  
    }
    selectionSort(number, n);

}

void selectionSort(int *a, int n){
    int i, j;
    int minj;
    int t;
    int temp = 0;
    int flag;
    for(i = 0; i < n; i++){
        flag = 0;
        minj = i;
        for(j = i + 1; j < n; j++){
            if(a[j] < a[minj]){
                minj = j;
                flag = 1;
            }
        }
        if(flag == 1){
            t = a[i];
            a[i] = a[minj];
            a[minj] = t;
            temp++;
        }
    }

                
    for(i = 0; i < n - 1; i++){
        printf("%d ", *(a + i));
    }
    printf("%d\n", *(a + n - 1));
    printf("%d\n", temp);
}
