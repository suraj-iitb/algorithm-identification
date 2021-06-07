#include<stdio.h>

int binarySearch(int);

int A[100000],a;

int main(){
    int i,j,x,b;
    int result = 0;
    
    scanf("%d",&a);
    for(i = 0;i < a;i++){
        scanf("%d",&A[i]);
    }
    
    scanf("%d",&b);
    
    for(i = 0;i < b;i++){
        scanf("%d",&x);
        if(binarySearch(x))result++;
    }
    
    printf("%d\n",result);
    
    return 0;
    
}


int binarySearch(int key){
    int right = a;
    int left = 0;
    int mid;
    
    while(left < right){
        
        mid = (left + right)/2;
        
        if(A[mid] == key) return 1;
        
        else if(key > A[mid])left = mid + 1;
        
        else if(key < A[mid])right = mid;
    }
    return 0;
}
