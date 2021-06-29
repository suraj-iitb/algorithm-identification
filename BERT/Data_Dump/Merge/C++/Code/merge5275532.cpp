#include<iostream>
using namespace std;
int count = 0;
void swap(int &a, int &b) 
	{   
   	int temp;
   	temp = a;
   	a = b;
   	b = temp;
	}
void show(int *array, int size) 
	{
   	for(int i = 0; i<size-1; i++)
      		cout << array[i] << " ";
	cout<<array[size-1];
   	cout << endl;
	cout << count; 
	cout <<endl;
	}
void merge(int *array, int l, int m, int r) 
	{
   	int i, j, k, nl, nr;
	nl = m-l+1; nr = r-m;
   	int larr[nl], rarr[nr];
   	for(i = 0; i<nl; i++)
      		larr[i] = array[l+i];
   	for(j = 0; j<nr; j++)
      		rarr[j] = array[m+1+j];
   	i = 0; j = 0; k = l;
   	while(i < nl && j<nr) 
		{
      		if(larr[i] <= rarr[j])
			{
         		array[k] = larr[i];
         		i++;
			}
		else
			{
		         array[k] = rarr[j];
         		j++;
			}
      		k++;
      		count++;
   		}
  	while(i<nl) 
		{       
      		array[k] = larr[i];
      		i++; k++;
      		count++;
   		}
   	while(j<nr) 
		{    
      		array[k] = rarr[j];
      		j++; k++;
      		count++;
   		}
	}

void merge_sort(int *array, int l, int r) 
	{
   	int m;
   	if(l < r) 
		{
      		int m = l+(r-l)/2;
	        merge_sort(array, l, m);
		merge_sort(array, m+1, r);
      		merge(array, l, m, r);
   		}
	}

int main() 
	{
   	int n;
   	cin >> n;
   	int arr[n];     
   	for(int i = 0; i<n; i++) 
		{
      		cin >> arr[i];
   		}
   	merge_sort(arr, 0, n-1);     
   	show(arr, n);
	}
