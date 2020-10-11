#include<stdio.h>

int main()
{
   int n, i, j, v;
   int minj;
   int c = 0;
   int flag = 1;
   int a[1000];

   scanf("%d", &n);
   
   for(i = 0; i < n; i++){
      scanf("%d", &a[i]);
   }
 
   for(i = 0; i <= n-1; i++){
	minj = i;
	for(j = i; j <= n-1; j++){
		if(a[j] < a[minj]){
			minj = j;
		}
	}
	
	if(a[i] > a[minj]){	
	   v = a[i];
	   a[i] = a[minj];
	   a[minj] = v;
	   c = c + 1;
	}
}

      for(i = 0; i < n; i++){
         printf("%d", a[i]);

         if(i != n-1){
            printf(" ");
         } else if(i == n-1){
            printf("\n");
         }
      }
      
      printf("%d\n", c);

return 0;

}
 



