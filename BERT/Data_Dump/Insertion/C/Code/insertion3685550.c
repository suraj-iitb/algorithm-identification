#include <stdio.h>
#define N 100
int n;

//function to sort and print array using insertion
void insertionSort (int arr[], int n)
{
    int i, key, j, print;
        for (i=1; i<n; i++){
            key = arr[i];
            j = i-1;
            while (j>=0 && arr[j]>key){
                arr[j+1] = arr[j];
                j--;
            }
            arr[j+1] = key;
            
            for (print=0; print<n;print++){
                printf("%d",arr[print]);
                if(print<n-1)
                	printf(" ");
                else
            		printf("\n");
            }
        }
}

//test sort
int main()
{
    int i;
    
    scanf("%d", &n);
   
    int a[N];
    for(i=0; i<n; i++)
        scanf("%d", &a[i]);
        
    for(i=0; i<n; i++){
    	printf("%d", a[i]);
    	if(i<n-1)
    		printf(" ");
    	else 
    		printf("\n");
    }
    
    insertionSort(a,n);
    
    return 0;
}
