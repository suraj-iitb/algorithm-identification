#include<iostream>
using namespace std;
int main()
{
    void InsertSort(int arr[],int n);
    void show(int arr[],int n);
    int n;
    cin>>n;
    int *arr = new int[n+1];
    for(int i = 0;i<n;i++)
        cin>>arr[i];
    show(arr,n);
    InsertSort(arr,n);
    return 0;
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
void InsertSort(int arr[],int n)
{
    int temp,j;
    for(int i = 1;i<n;i++)//下标是从0开始！
    {
        temp = arr[i];
        j = i - 1;
        while(j>=0&&arr[j]>temp)
        {
            arr[j+1] = arr[j];
            j--;
        }
        arr[j+1] = temp;
        show(arr,n);
    }
}

