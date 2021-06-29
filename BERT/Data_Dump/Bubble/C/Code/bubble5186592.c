#include<stdio.h>
#include <stdbool.h>

void swap(int *,int *);

void swap(int *a,int *b)
{
    int temp;
    temp = *a;
    *a = *b;
    *b = temp;
    return;
}


int bubbleSort(int DATA[], int N){
int count = 0;
bool flag =1;/*判定のために使用*/
int i,j;

for(i=0; flag; i++){
    flag =0;
    for(j=N-1;j>=1;j--){
        if(DATA[j]<DATA[j-1]){
            swap(&DATA[j],&DATA[j-1]);
            flag = 1;
            count++;
            } 
            }
}
return count;
}

int main(){
    int deta[100],N,count;
    int i;
    scanf("%d",&N);/*入力の最初の行に、数列の長さを表す整数 N が与えられます*/
    for(i=0;i<N;i++){
    scanf("%d",&deta[i]);/*２行目に、N 個の整数が空白区切りで与えられます*/
    }
    count= bubbleSort(deta,N);
    
    for(i=0;i<N;i++){
    if(i) {
        printf(" ");
    }
    printf("%d",deta[i]);
    }
    printf("\n%d\n",count);
    return 0;
    }


