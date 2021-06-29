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


void selection_sort(int a[], int n)
{
	int i, j, min, tmp;
	int cnt = 0;
	
	for(i = 0; i < n-1; i++){
		min = i;
		for (j = i+1; j < n; j++){
			if (a[j] < a[min]){
				min = j;
			}
		}
		if(min != i){
			tmp = a[i]; a[i] = a[min]; a[min] = tmp;
			cnt++;
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
    
    selection_sort(a, n);
    
    return 0;
}
