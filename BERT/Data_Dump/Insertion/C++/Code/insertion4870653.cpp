#include <iostream>
using namespace std;
void print(int *ivec, int n)
{
    for(int i = 0; i < n - 1; i++)
        cout << ivec[i] << ' ';
    cout << ivec[n - 1];
    cout << endl;
}
void insertionSort(int *arr, int n)
{
    for(int i = 0; i < n; i++){
        int key = arr[i];
        int j = i - 1;
		while(j >= 0 && arr[j] > key)
       	 	arr[j + 1] = arr[j--];
       	arr[j + 1] = key;
        print(arr, n);
	}
}
int main()
{
    int n;
    cin >> n;
    int arr[n];
    for(int i = 0; i < n; i++)
        cin >> arr[i];
    insertionSort(arr, n);
    return 0;
}

