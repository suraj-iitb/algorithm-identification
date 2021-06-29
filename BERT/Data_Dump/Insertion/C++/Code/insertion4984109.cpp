#include <iostream>
#include <vector>
#include <string>

using namespace std;

const int MAXN = 105;
int arr[MAXN];
int main()
{
    int n;
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    for(int k = 0;k<n-1;k++){
        cout<<arr[k]<<" ";
    }
    cout<<arr[n-1]<<endl;
    for(int i = 1; i< n;i++){
        int key = arr[i];
        int j = i - 1;
        while(j>=0&&arr[j]>key){
            arr[j+1] = arr[j];
            j--;
        }
        arr[j+1] = key;
        for(int k = 0;k<n-1;k++){
            cout<<arr[k]<<" ";
        }
        cout<<arr[n-1]<<endl;
    }
}

