#include<stdio.h>
#define MAX 100
int number[MAX] = {0};
void bubbleSort(int *, int);

int main(){
    int n, i;

    scanf("%d\n", &n);

    scanf("%d", number);
    for(i = 1; i < n ; i++) {
        scanf(" %d", number + i);  
    }
    bubbleSort(number, n);

}

void bubbleSort(int *a, int n){
    int flag = 1;
    int t;    
    int i, j;
    int temp = 0;
    i = 0;
    while(flag){
        flag = 0;
        for(j = n - 1; j > i; j--) {
            if(*(a + j - 1) > *(a + j)){
                t = *(a + j);
                *(a + j) = *(a + j - 1);
                *(a + j - 1) = t;
                flag = 1;
                temp++;
            }
        }
        i++;
    }
    for(i = 0; i < n - 1; i++){
        printf("%d ", *(a + i));
    }
    printf("%d\n", *(a + n - 1));
    printf("%d\n", temp);
}
