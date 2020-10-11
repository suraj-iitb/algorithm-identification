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
    int key=0, num=0, length, i, j;

    scanf("%d", &length);
    for(i=0; i<length; i++){
        scanf("%d",&A[i]);
    }


    //Bubble Sort Algo
    for(i=0; i<=length-1; i++){
        for(j=length-1; j>=i+1; j--){
            if(A[j] < A[j-1]){
                key = A[j];
                A[j] = A[j-1];
                A[j-1] = key;
                num++;
            }
        }
    }

    printSequence(length, num);

    return 0;
}
