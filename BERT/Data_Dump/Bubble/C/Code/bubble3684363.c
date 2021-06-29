#include<stdio.h>
int main()
{
	int i,j,k,len,ty;
	int count = 0;
	
	
	scanf("%d",&len);
	int A[len];
	
	for(i=0;i<len;i++)
 	scanf("%d",&A[i]);
 		
 
 	  
 	//printf("\n");
	
	for(i=0;i<=len-1;i++){
	for(j=len-1;j>=i+1;j--){
	if (A[j]<A[j-1]){
		   ty = A[j];
                A[j] = A[j-1];
                A[j-1] = ty;
                count++;
	
}
	}
}
	for(i=0; i<=len-1; i++){
        printf("%d", A[i]);
        if(i!=len-1) printf(" ");
		  }
         
    printf("\n");
    printf("%d",count);
    printf("\n");
    return 0;
}
