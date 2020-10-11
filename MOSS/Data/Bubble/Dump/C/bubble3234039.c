#include<stdio.h>

int main()
{
   int n, i, j, v;
   int c = 0;
   int flag = 1;
   int a[1000];

   scanf("%d", &n);
   
   for(i = 0; i < n; i++){
      scanf("%d", &a[i]);
   }
 
   while(flag == 1){
	flag = 0;
	
	for(j = n-1; j >= 1; j--){
		if(a[j] < a[j-1]){
			v = a[j];
			a[j] = a[j-1];
			a[j-1] = v;
			c = c+1;
			flag = 1;
		}
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
 



