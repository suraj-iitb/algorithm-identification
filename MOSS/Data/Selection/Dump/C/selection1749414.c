#include<stdio.h>
int A[100];

//Output function
void printSequence(int length, int num){
    int i;
    for(i=0; i<length; i++){
        if(i!=0)printf(" ");
        printf("%d",A[i]);
    }

    printf("\n");
    printf("%d\n",num);

}

int main(){
    int key=0, num=0, length, i, j, minj;

    scanf("%d", &length);
    for(i=0; i<length; i++){
        scanf("%d",&A[i]);
    }


    //Bubble Sort Algo
    for(i=0; i<=length-2; i++){
        minj = i;
        for(j=i; j<=length-1; j++){
            if(A[j] < A[minj]){
                minj = j;
            }
        }

        if(minj != i){
            key = A[i];
            A[i] = A[minj];
            A[minj] = key;
            num++;
        }
    }

    printSequence(length, num);

    return 0;
}
