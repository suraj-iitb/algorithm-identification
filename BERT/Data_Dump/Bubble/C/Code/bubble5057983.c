#include <stdio.h>
void bubbleSort(int*, int);
int main(){
    int i,j,quantity,data[100];
    scanf("%d", &quantity);
    for(i = 0; i < quantity; i++){
        scanf("%d", &data[i]);
    }
    bubbleSort(data, quantity);

}
void bubbleSort(int *a, int q){
    int i,j,k,time = 0;
    for(i = 0; i < q; i++){
        for(j=q-1; j > i; j--){
            if(a[j] < a[j-1]){
                k = a[j];
                a[j]= a[j-1];
                a[j-1] = k;
                time++;
            }
        }
    }
    for(i = 0; i< q-1; i++) printf("%d ", a[i]);
    printf("%d\n", a[i]);
    printf("%d\n", time);

}
