#include <stdio.h>

//function to sort and print array using selection
int SelectionSort (int arr[], int n)
{
    int i, j, mini, count=0, temp;
    for (i=0; i<n-1; i++){
    	mini = i;
        for (j = i; j<n; j++){
        	if (arr[j]<arr[mini]){
				mini = j;
        	}
    	}
    	//swap
    	if (mini!=i){
    		temp = arr[i];
        	arr[i] = arr[mini];
        	arr[mini] = temp;
        	count++;
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
    
    swap = SelectionSort(a,n);
    
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



