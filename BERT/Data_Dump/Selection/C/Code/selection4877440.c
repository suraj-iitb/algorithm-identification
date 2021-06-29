#include<stdio.h>
#define ARR_LEN 255

int sum;

void select_sort(int arr[],int n)
{
    int i,j;
    for(i=0; i<n-1; i++)
    {
        int min_index = i;
        for(j=i+1; j<n; j++)
        {
            if(arr[j] < arr[min_index])
            {
                min_index = j;
            }
        }
        if( i != min_index)
        {
        	sum++;
            int temp = arr[i];
            arr[i] = arr[min_index];
            arr[min_index] = temp;
        }
    }
}


int  main()
{
	int len,arr[ARR_LEN],i;
	scanf("%d",&len);

    for(i=0; i<len; i++){
    	scanf("%d", &arr[i]);
	}

    select_sort(arr, len);

    for (i=0; i<len; i++){
        printf ("%d", arr[i]);
        if (i != len - 1) {
            printf(" ");
        } else {
            printf("\n");
        }
    }
    printf("%d\n", sum);

    return 0;

}
