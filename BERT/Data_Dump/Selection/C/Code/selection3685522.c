#include<stdio.h>
int main()
{
	int i,j,len,ty,mini;
	int count = 0;
	
	
	scanf("%d",&len);
	int A[len];
	
	for(i=0;i<len;i++)
 	scanf("%d",&A[i]);
 		
 
 	  
 	//printf("\n");
	
	for(i=0;i<=len-1;i++){
		mini=i;
		//count++;
	for(j=i;j<=len-1;j++){
	if (A[j]<A[mini]){
		   mini=j;
		   } 
	
   
}
	if(mini != i){ 
	
		   ty = A[mini];
                A[mini] = A[i];
                A[i] = ty;
                count++;
}
}
	for(i=0; i<len; i++){
        printf("%d", A[i]);
        if(i!=len-1) printf(" ");
		  }
     
    printf("\n");
    printf("%d",count);
    printf("\n");
    return 0;
}
