#include <stdio.h>

//function to sort and print array using insertion
int BubbleSort (int arr[], int n)
{
    int i, j, count=0, temp;
    for (i=0; i<n-1; i++){
        for (j = n-1; j>=i+1; j--){
        	if (arr[j]<arr[j-1]){
				temp = arr[j];
            	arr[j] = arr[j-1];
            	arr[j-1] = temp;
                count++;
        	}
    	}
    }
    return count;
}

//test sort
int main()
{
    int i, n, swap;
    
    scanf("%d", &n);
    
    int a[n];
    
    for(i=0; i<n; i++)
        scanf("%d", &a[i]);
    
    swap = BubbleSort(a,n);
    
    for(i=0; i<n; i++){
    	printf("%d", a[i]);
    	if(i<n-1)
    		printf(" ");
    	else 
    		printf("\n");
    }
    
    printf("%d\n",swap);
    
    return 0;
}



