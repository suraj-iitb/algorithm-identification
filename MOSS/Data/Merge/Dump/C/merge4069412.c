#include <stdio.h>
#include <stdlib.h>

#define INF 1000000000

int n, num;

void mergeSort(int *, int, int);
void merge(int *, int, int, int);

int main(){
        int *S;
        int i, left, right;

        scanf("%d", &n);
        S = malloc(sizeof(int) * n);
        for(i = 0 ; i < n ; i++){
                scanf("%d", &S[i]);
        }

        left = 0;
        right = n;

        mergeSort(S, left, right);

        for(i = 0; i < n ; i++){
          printf("%d", S[i]);
          if(i + 1 != n)printf(" ");
        }
        printf("\n");

        printf("%d\n", num);

        return 0;
}

void mergeSort(int *S, int left, int right){
        int mid,i;
        if(left+1 < right){
                mid = (left + right) / 2;
                mergeSort(S, left, mid);
                mergeSort(S, mid, right);
                merge(S, left, mid, right);
        }
}

void merge(int *S, int left, int mid, int right){
        int n1, n2, i, j, k;
        n1 = mid - left;
        n2 = right - mid;

        int *L, *R;
        L = malloc(sizeof(int) * (n1 + 1));
        R = malloc(sizeof(int) * (n2 + 1));

        for(i = 0 ; i < n1;i++){
                L[i] = S[left + i];
        }
        for(i = 0 ; i < n2;i++){
                R[i] = S[mid + i];
        }
        L[n1] = INF; R[n2] = INF;

        i = 0; j = 0;
        for(k = left ; k < right ; k++){
          if(L[i] <= R[j]){
            S[k] = L[i];
            i++; num++;
          }else{
            S[k] = R[j];
            j++; num++;
          }
        }
}

