
#include <stdio.h>
#include <string.h>

void process(int *x, int z){
    for(int k = 0; k < z; k++){
        printf("%d", x[k]);
        if(k < z - 1){
            printf(" ");
        }else{
            printf("\n");
        }
    }
}

void insertionSort(int *x, int y){
    int i, v, j;
    for(i = 1; i < y; i++){
        v = x[i];
        j = i -1;
        while(j >= 0 && x[j] > v){
            x[j + 1] = x[j];
            j--;
        }
        x[j + 1] = v;
        process(x, y);
    }
}

int main(void){
    int n;
    int hand[101];
    char *number;
    char order[1000000];
    
    fgets(order, 300, stdin);
    sscanf(order, "%d", &n);
    fgets(order, 1000000, stdin);
    number = strtok(order, " \n");      //要素が一個だけだったら数字の次は改行コードが入るので改行コードも入れる。
    sscanf(number, "%d", &hand[0]);
    for(int j = 1; j < n; j++){
        number = strtok(NULL, " \n");
        sscanf(number, "%d", &hand[j]);
    }
    process(hand, n);
    insertionSort(hand, n);
    return 0;
}
