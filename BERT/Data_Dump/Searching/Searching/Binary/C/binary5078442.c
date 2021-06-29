#include<stdio.h>
int binarySearch(int ,int *);
int n,m,q,i,j,count=0;
int main(){
    scanf("%d",&n);
    int S[n];
    for(i=0;i<n;i++){
        scanf("%d",&S[i]);
    }
    scanf("%d",&q);
    int T[n];
    for(i=0;i<q;i++){
        scanf("%d",&T[i]);
    }
    for(i=0;i<q;i++){
        count+=binarySearch(T[i],S);
    }
    
    printf("%d\n",count);
    return 0;
}
int binarySearch(int key,int A[]){
    int left = 0,right = n,mid,flag=0;
    
        while(left < right){
            mid = (left + right) / 2;
            if(A[mid] == key){
                flag++;
                break;
            }
            else if(key < A[mid]) right = mid;
            else left = mid + 1;
        }
        return flag;
}
