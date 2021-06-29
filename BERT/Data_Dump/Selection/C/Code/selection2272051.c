#include  <stdio.h>

int main(){
  int A[100],n,i,j,k,min,temp,count=0;

  scanf("%d",&n);
  
  for(i=0;i<n;i++){
    scanf("%d",&A[i]);
  }

   for (i = 0; i < n - 1; i++) {
        min = A[i];                 
        k = i;                        
        for (j = i + 1; j < n; j++) {
            if (A[j] < min) {       
                min = A[j];        
                k = j;
            }
        }                           
        temp = A[i];                
        A[i] = A[k];
        A[k] = temp;
	if(i != k)count++;
    }

 for(i=0;i<n;i++){
   printf("%d",A[i]);
       if(i != n-1){
	printf(" ");
      }
    }
 
 printf("\n");
 
 printf("%d\n",count);
 
 return 0;
}
