#include <stdio.h>//%cと%sはchar型,sortは並び換え
 int main(){
   int a,b,i,v,j,A[1000],N,k; 
   scanf("%d",&N);
   for(i=0;i<N;i++)
	 scanf("%d",&A[i]);

   for(k=0;k<N;k++){
	 
	 if(k != N-1){
	   printf("%d ",A[k]);
	 }else{
	   printf("%d\n",A[k]);
	 }
   }
   for(i=1;i<=N-1;i++){//iは0からn-1まで
	 v = A[i];//同じ数字がでるから別のところに格納しておく。
	 j = i - 1;//iから一個手前にjがいるから
	 while(j >= 0 && A[j] > v){
	   A[j + 1] = A[j];
	   j--;//次で一個手前に格納するから
	 }  
	 A[j + 1] = v;
	 for(k=0;k<N;k++){
	   if(k != N-1){
		 printf("%d ",A[k]);
	   }else{
		 printf("%d\n",A[k]);
	   }
	 }
   }
   return 0;
 }
  

