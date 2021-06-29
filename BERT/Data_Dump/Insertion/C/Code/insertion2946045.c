  #include <stdio.h>
  #define N 100
  int main(void){
   int i=1,j,count,count2,tmp,n,m=0,A[N];
   scanf("%d",&n);
       while(1){
     scanf("%d",&A[m]);
     m++;
     if(m>=n) break;
   }
   while(i<n){
     for(count=0;count<n-1;count++){
       printf("%d ",A[count]);
     }
     printf("%d\n",A[n-1]);
     tmp=A[i];
     j=i;
     i++;
     while(j>0&&A[j-1]>tmp){
       A[j]=A[j-1];
       j--;
     }
     A[j]=tmp;
   }
    count2=0;
    while(count2<n-1){
      printf("%d ",A[count2]);
      count2++;
    }
    printf("%d\n",A[n-1]);
    return 0;
  }

