#include <stdio.h>
#include <stdlib.h>

#define MAX 100

void show_array(int *a, int n)
{
     int i;
     
     for (i = 0; i < n; i++) {
         if (i > 0) printf(" ");
         printf("%d", a[i]);    
     }
     printf("\n");
}

void bubble_sort(int *a, int n)
{
    int cnt = 0, i, j, t;
    
    for (i = 0; i < n; i++) {
        for (j = 0; j < n - i - 1; j++) {
            if (a[j] > a[j + 1]) {
               t = a[j];
               a[j] = a[j+1];
               a[j+1] = t;
               cnt++; 
            }    
        }
    }
    show_array(a, n);
    printf("%d\n", cnt);
}

int main(int argc, char *argv[])
{
	int i, n, a[MAX];

	scanf("%d", &n);
  
	for (i = 0; i < n; i++) scanf("%d", &a[i]);

	bubble_sort(a, n);
  	
	return 0;
}
