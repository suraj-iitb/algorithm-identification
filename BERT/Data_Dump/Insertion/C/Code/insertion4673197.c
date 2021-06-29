#include <stdio.h>
#include <stdlib.h>


void intersectionSort(int A[], int n) 
{ 
    //move postion 
	int i, key, j; 
	for (i = 1; i < n; i++) { 
		key = A[i]; 
		j = i - 1; 

    
		while (j >= 0 && A[j] > key) { 
			A[j + 1] = A[j]; 
			j = j - 1; 
            
		A[j + 1] = key;  
        
	}
     for (j = 0; j < n; j++)
     {
          if (j==n-1)
     {
         printf("%d\n", A[j]);
        
     }

      else {printf("%d ", A[j]);}
     }
    
    
       
} 
}
    int main()
    {
        //size
        int n=0;
        //printf("enter the number of elements in the sequence: \n");
        scanf("%d", &n);
       
        if (n>100 || n<1)
        {
            //printf("range should be between 1 to 100");
            return 1;
        }
        //printf("enter the elemetns of sequence by space: \n");
       
      
//scan array 
 int A[100];
 
 for (int i = 0; i < n; i++) {
  scanf("%d", &A[i]);
 }
        
	 for (int j = 0; j < n; j++) {
  if (j == n- 1)printf("%d\n", A[j]);
  else printf("%d ", A[j]);
 }
     
     
        intersectionSort(A,n);
        
     
        return 0;
    }
    


