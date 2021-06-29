# include <stdio.h>
void selectionSort(int *, int);

int main(){
    int i,j,quantity,data[100];
    scanf("%d", &quantity);
    for(i = 0; i < quantity; i++){
        scanf("%d", &data[i]); 
    }
    selectionSort(data,quantity);
    return 0;

}
void selectionSort(int *p, int q){
    int i,j,k,min,time = 0;
    for(i = 0; i < q; i++){
        min = i;
        for(j = i; j < q; j++){
            if(p[j] < p[min]) min = j;
        }
        if(min != i){
            k = p[i];
            p[i]= p[min];
            p[min] = k;
            time++;
        }
    }
    for(i = 0; i< q-1; i++) printf("%d ", p[i]);
    printf("%d\n", p[i]);
    printf("%d\n", time);

}
