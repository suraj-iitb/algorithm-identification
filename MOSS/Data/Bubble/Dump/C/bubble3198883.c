#include<stdio.h>

 int bubble(int A[],int n){
            int i,j,tmp,count=0;
            for(i=0;i<n;i++){
                     for(j=n-1;j>i;j--){
                               if(A[j]<A[j-1]){tmp=A[j-1];A[j-1]=A[j];A[j]=tmp;count++;}
                               }
                     }
            return count;
            }

 int main(){
        int i,j,n,x;
        int A[100];
        scanf("%d",&n);
        for(i=0;i<n;i++){scanf("%d",&A[i]);}

        x=bubble(A,n);
        for(i=0;i<n;i++){printf("%d%c",A[i],(i==n-1)?'\n':' ');}
        printf("%d\n",x);
        return 0;
        }

        
