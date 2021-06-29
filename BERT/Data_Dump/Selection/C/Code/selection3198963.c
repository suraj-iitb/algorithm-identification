#include<stdio.h>

 int selection(int A[],int n){
            int i,j,count=0,minj,t;
            for(i=0;i<n;i++){
                     minj=i;
                     for(j=i;j<n;j++){
                             if(A[minj]>A[j])minj=j;
                             }
                     if(i != minj){t=A[minj];A[minj]=A[i];A[i]=t;count++;}
                     }
            return count;
            }

 int main(){
       int i,j,A[100],n,x;
       scanf("%d",&n);
       for(i=0;i<n;i++){scanf("%d",&A[i]);}

       x=selection(A,n);
       for(i=0;i<n;i++){printf("%d%c",A[i],(i==n-1)?'\n':' ');}
       printf("%d\n",x);
       return 0;
       }
