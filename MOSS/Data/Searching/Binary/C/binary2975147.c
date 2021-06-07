#include<stdio.h>
#define N 100000
#define M 50000

//int binarySearch(int [],int,int);
int main(){
    int A[N],A2[M],i,n,q,x,count=0;
    
    scanf("%d",&n);
   
    for(i=0;i<n;i++){
        scanf("%d",&A[i]);
    }
     scanf("%d",&q);
    for(i=0;i<q;i++){
        scanf("%d",&A2[i]);
    }
   
    for(i=0;i<q;i++){
        int key=A2[i];
        int right=n;
        int left=0;
      
                while(left<right){
                    int mid=(left+right)/2;
       
            if(A[mid]==key) {
                count++;
                break;}
            if(key<A[mid]) right=mid;
            else left = mid+1;;
        }
    }
    printf("%d\n",count);
    
    return 0;
}
