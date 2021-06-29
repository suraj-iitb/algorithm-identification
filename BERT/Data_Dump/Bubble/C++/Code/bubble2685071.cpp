#include<iostream>
using namespace std;
int bubbleSort(int arr[],int n)
{
   int times = 0;
   for(int i = 0;i<n;i++)
    for(int j = n-1;j>i;j--)
        if(arr[j]<arr[j-1])
        {
            int temp = arr[j];
            arr[j] = arr[j-1];
            arr[j-1] = temp;
            times++;
        }
    return times;
}
void show(int arr[],int n)
{
    for(int i = 0;i< n;i++)
    {
        cout<<arr[i];
        if(i<n-1)
            cout<<" ";
    }
    cout<<endl;
}
int main()
{
    int n;
    cin>>n;
    int *arr = new int[n+1];
    for(int i = 0;i<n;i++)
        cin>>arr[i];
    int times = bubbleSort(arr,n);
    show(arr,n);
    cout<<times<<endl;
    return 0;
}

