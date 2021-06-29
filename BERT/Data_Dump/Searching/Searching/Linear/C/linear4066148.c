#include<stdio.h>

int linearSearch(int A[],int n,int key){
  int i;
  for(i=0; i<n; i++){
    if(A[i]==key) return i;
  }
  return -1;
     }



   int main(){

     int i,j,n,count=0,N,A[10000],key;


     scanf("%d",&n);
     for(i=0; i<n; i++){
       scanf("%d",&A[i]);
     }



     scanf("%d",&N);
     for(j=0; j<N; j++){
       scanf("%d",&key);
       if(linearSearch(A,n,key)!=-1){
         count++;
       }
     }


     /*  for(i=0; i<n; i++){                                                    
       for(j=0; j<N; j++){                                                      
                                                                                
         if(A[i]==B[j]){                                                        
           count++;                                                             
           break;                                                               
       }                                                                        
       }                                                                        
     }                                                                          
     */




     printf("%d\n",count);

     return 0;
   }

