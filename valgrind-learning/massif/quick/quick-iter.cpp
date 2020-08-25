#include <bits/stdc++.h>
using namespace std;

int partition(int arr[], int start, int end)
{
	int pivot = arr[end]; //rightmost element is the pivot
	int pIndex = start;  //Is to push elements less than pivot to left and greater than to right of pivot
	for (int i = start; i < end; ++i)
	{
		if (arr[i] < pivot)
		{
			swap(arr[i],arr[pIndex]);
			pIndex++;
		}
	}
	swap(arr[pIndex], arr[end]);
	return pIndex;
}
void iterativeQuicksort(int arr[], int start, int end)
{

	int stack[end - start + 1];//Initializing stack size
	int top = -1; //To keep track of top element in the stack
	//pushing intial start and end
	stack[++top] = start;
	stack[++top] = end; 	

	//pop till the stack is empty
	while(top >= 0) 
	{
		//poping the top two elements 
		//ie,poping parent subarray indexes to replace child subbary indexes 
		end = stack[top--];
		start = stack[top--]; 	
		int pivot_index = partition(arr, start, end);

		//Pushing the left subarray indexes that are less than pivot
	    if (pivot_index - 1 > start )
	    {
	    	stack[++top] = start;
	    	stack[++top] = pivot_index -1;
	    }
	    //pushing the right subarray indexes that are greater than pivot
	    if (pivot_index + 1 < end)
	    {
	    	stack[++top] = pivot_index + 1;
	    	stack[++top] = end;
	    }
	}
	

}
void printArray(int arr[], int n)
{
	//Printing the sorted array
	cout<<"Sorted array is [ ";
	for (int i = 0; i < n; ++i)
	{
		cout<<arr[i]<<" ";
	}
	cout<<"]"<<endl;
}

int main()
{
    int n;
	scanf("%d", &n);

	int arr[n];
    for(int i=0;i<n;i++)
        scanf("%d", &arr[i]);
	// int arr[]= {4, 1, 10, 23, 5};  //creating an array
    // int n = sizeof(arr)/sizeof(arr[0]); //size of the array
    iterativeQuicksort(arr,0,n-1);
    printArray(arr, n);
    return 0;
}