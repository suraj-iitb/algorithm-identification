#include<stdio.h>
#include<cstdlib>

#define INFTY 10*10*10*10*10*10*10*10*10+1

void mergeSort(int *, int, int);
void merge(int *, int, int, int);

int n, *A, compN = 0;


int main(){
    int i;
    
    scanf("%d",&n);
    A = (int *)malloc(sizeof(int) * n);
    for(i = 0; i < n; i++){
        scanf("%d",&A[i]);
    }
    
    
    mergeSort(A, 0, n);
    for(i = 0; i < n; i++){
        printf("%d",A[i]);
        if(i == n-1){
            printf("\n");
            break;
        }
        printf(" ");
    }
    
    printf("%d\n",compN);
    
    free(A);
    return 0;
}

void mergeSort(int *A, int left, int right){
    int mid;
    //static int n=-1;
    //n++;
    if(left+1 < right){ // when there are more than 3 elements
        mid = (left + right) / 2;
        mergeSort(A, left, mid);
        //printf("%d  left:%d, mid:%d\n",n,left,mid);
        mergeSort(A, mid, right);
        //printf("%d  mid:%d, right:%d\n",n,mid,right);
        merge(A, left, mid, right);
    }
}



void merge(int *a, int left, int mid, int right){
    int i, j, k;
    int n1, n2;
    int *a1, *a2;
    n1 = mid - left;
    n2 = right - mid;
    a1 = (int *)malloc(sizeof(int) * n1 + 1);
    a2 = (int *)malloc(sizeof(int) * n2 + 1);
    
    for(i = 0; i < n1; i++){
        a1[i] = a[left + i];
    }
    for(i = 0; i < n2; i++){
        a2[i] = a[mid + i];
    }
    // put sentinel into last element
    a1[n1] = INFTY;
    a2[n2] = INFTY;
    
    i = j = 0;
    for(k = left; k < right; k++){
        if(a1[i] < a2[j]){
            a[k] = a1[i];
            i++;
            //printf("%d < %d\n",a1[i],a2[j]);
        }else{
            a[k] = a2[j];
            j++;
            //printf("%d >= %d\n",a1[i],a2[j]);
        }
        compN++;
    }
    
    free(a1);
    free(a2);
}

            
            



