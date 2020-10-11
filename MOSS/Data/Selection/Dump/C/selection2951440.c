#include <stdio.h>

int selectionSort(int A[100],int N);

void show(int A[100],int N);

int selectionSort(int A[100],int N){

  int i=0,j=0,k,c=0,temp;
    for (i = 0; i < N - 1; i++) {
                    /* i 番目の要素を暫定的に最小値とし */
        k = i;                        /* 添字を保存 */
        for (j = i + 1; j < N; j++) {
            if (A[j] < A[k]) {       /* より小さい値が現れたら */
                        /* 最小値の入れ替え */
                k = j;                /* 添字を保存 */
                
            }
        }  /* このループを抜けるとk に最小値の添字が入っている */
    if(i!=k){
        c++;
        temp = A[i];                /* i 番目の要素と最小値の交換 */
        A[i] = A[k];
        A[k] = temp;
    }
        
    }
    return c;
}

void show(int A[100],int N){

 int i;

 for(i=0;i<N;i++){
     printf("%d",A[i]);
     if(i+1!=N){
         printf(" ");
     }
 }
 printf("\n");

}

int main(){

    int n,i;
    int a[100];

    scanf("%d",&n);
    for(i=0;i<n;i++){
        scanf("%d",&a[i]);
    }

   int x;
   x = selectionSort(a,n);

    show(a,n);

    printf("%d\n",x);
   
return 0;

}
