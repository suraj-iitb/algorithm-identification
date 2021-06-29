#include<iostream>
using namespace std;
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
int selectionSort(int arr[],int n)
{
    int times = 0;
    for(int i = 0;i<n;i++)
    {
        int key = i;
        bool flag = 0;
        for(int j = i+1;j<n;j++)
            if(arr[j]<arr[key])
            {
                key = j;
                flag = 1;
            }
        if(flag)
        {
            swap(arr[key],arr[i]);
            times++;
        }
    }
    return times;
}

int main()
{
    int n;
    cin>>n;
    int *arr = new int[n+1];
    for(int i = 0;i<n;i++)
        cin>>arr[i];
    int times = selectionSort(arr,n);
    show(arr,n);
    cout<<times<<endl;
    return 0;
}

