#include<stdio.h>

int A[100000];
int N;

int binarySearch(int key){
    int left = 0;
    int right = N;
    int mid;
    
    while(left<right){
        mid = (left + right)/2;
        
        if(A[mid] == key){
            return 1;
        }else if(A[mid] > key){
            right = mid;
        }else{
            left = mid +1;
        }
    }
    return 0;
}

int main(){
    int i,M,key;
    int n = 0;
    int k = 0;
    
    scanf("%d",&N);
    
    for(i=0;i<N;i++){
        scanf("%d",&A[i]);
    }
    
    scanf("%d",&M);
    
    for(i=0;i<M;i++){
        scanf("%d",&key);
        if(binarySearch(key)){
            n++;
        }
    }
    printf("%d\n", n);
    return 0;
}
