#include <stdio.h>

void print_list(int a[], int n)
{
    int i;
    for (i = 0; i < n; i++){
        printf("%d", a[i]);
        if (i < n-1)
            printf(" ");
    }
    printf("\n");
}


void bubble_sort(int a[], int n)
{
	int i, j, cnt, tmp;
	cnt = 0;
	for (i = 1; i < n; i++){
		for (j = 0; j < n-i; j++){
			if (a[j] > a[j+1]){
				tmp = a[j];  a[j] = a[j+1];  a[j+1] = tmp;
				cnt++;
			}
		}
	}
	print_list(a, n);
	printf("%d\n", cnt);
}

int main()
{
    int a[1000];
    int i, n;
    
    scanf("%d", &n);
    for (i = 0; i < n; i++)
        scanf("%d", &a[i]);
    
    bubble_sort(a, n);
    
    return 0;
}
