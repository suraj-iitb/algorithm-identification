#include <bits/stdc++.h>

using namespace std;

void trace(int arr[], int num)
{
    cout << arr[0];
    for(int l=1; l<num; l++)
    {
        cout << " " << arr[l];
    }
    cout << endl;
}

void inSort(int arr[], int num)
{
    for(int i=1; i < num; i++)
    {
        int tmp = arr[i];
        int j = i - 1;
        while (j>=0 && tmp < arr[j])
        {
            arr[j+1] = arr[j]; 
            j--;
        }
        arr[j+1] = tmp;
        trace(arr, num);
    }
    return;    
}

int main()
{ 
    int num, arr[100];
    cin >> num;
    for(int i=0; i < num; i++)
    {
        cin >> arr[i];
    }

    trace(arr, num);
    inSort(arr, num);    

    return 0;
}

