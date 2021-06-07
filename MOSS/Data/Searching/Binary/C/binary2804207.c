#include "stdio.h"
#include "stdlib.h"

int N;
int M;
int A[100010];
int temp;
int res;


int binarySearch(int x){
    int left = 0;
    int right = N;
    int mid;
    while(left < right){
        mid = (left + right) / 2;
        if(A[mid] == x){
            return 1;
        } 
        else if(A[mid] > x){
            right = mid;
        }
        else{
            left = mid + 1;
        }
    }
    return 0;
}

int main(){
    //freopen("binarySearch.txt", "r", stdin);
    scanf("%d", &N);
    for(int i=0; i<N; i++){
        scanf("%d", &A[i]);
    }
    scanf("%d", &M);
    for(int i=0; i<M; i++){
        scanf("%d", &temp);
        if(binarySearch(temp)) res++;
    }
    printf("%d\n", res);
    return 0;
}
