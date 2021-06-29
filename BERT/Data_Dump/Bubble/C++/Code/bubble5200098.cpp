#include <iostream>
using namespace std;

int main()
{
    int i,j,N,temp,arr[100],swapCount=0;
    cin>>N;
    for (i=0; i<N; i++)
        cin>>arr[i];
    for (i=0; i<N; i++){
        for (j=N-1; j>i; j--){
            if (arr[j]<arr[j-1]){
                temp=arr[j];
                arr[j]=arr[j-1];
                arr[j-1]=temp;
                swapCount++;
            }
        }
    }
    for(i=0;i<N-1;i++)
        cout<<arr[i]<<" ";
    cout<<arr[N-1]<<endl<<swapCount<<endl;
    return 0;
}

