#include<stdio.h>
int main()
{
    int i, n, min, j, temp,c=0;
    int a[100];
    scanf("%d", &n);
    for (i = 0; i < n; i++) {
        scanf("%d", &a[i]);
    }

     for( i = 0; i < n ; i++ ){
 
    min = i;
 
    for(j = i ; j < n; j++ ){
 
      if(a[j] < a[min]){
        min = j;
      }
    }
     temp = a[i];
     a[i] = a[min];
     a[min] = temp;
     if(i != min) c++;
  }


    for (i = 0; i < n; i++) {
        if (i == n - 1) {
            printf("%d\n", a[i]);
            break;
        }
        printf("%d ", a[i]);
    }
    printf("%d\n", c);
}
