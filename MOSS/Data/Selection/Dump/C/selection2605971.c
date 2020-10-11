#include <stdio.h>
 
int main(void) {
     
    int i, j, n, s, minj, count = 0;
    int a[100];
     
    scanf("%d", &n);
    for( i = 0; i < n; i++){
        scanf("%d", &a[i]);
    }
     
   
            for( i = 0; i < n-1; i++){
                minj = i;
                for( j = i; j < n; j++){
                	if( a[j] < a[minj]){
                		minj = j;
                	}
                }
                if(i!= minj){
                		s = a[i];
                		a[i] = a[minj];
                		a[minj] = s;
                    count = count + 1;
                }
}
       
     
    for(i = 0; i < n-1; i++){
        printf("%d ", a[i]);
    }
        printf("%d\n",a[n-1]);
        printf("%d\n", count);
         
    return 0;
     
}
