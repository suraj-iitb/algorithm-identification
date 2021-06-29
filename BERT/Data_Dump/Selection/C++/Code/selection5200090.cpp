#include <iostream>
using namespace std;

int main()
{
    int i,j,N,mini,temp,arr[100],swapCount=0;
    cin>>N;
    for (i=0; i<N; i++)
        cin>>arr[i];
        
    for (i=0; i<N-1; i++){
        mini = i;
        for (j=i;j<N;j++)
            if (arr[j]<arr[mini])
                mini = j;
        temp=arr[i];
        arr[i]=arr[mini];
        arr[mini]=temp;
        if (i!=mini)
            swapCount++;
    }
        
            
    for(i=0;i<N-1;i++)
        cout<<arr[i]<<" ";
    cout<<arr[N-1]<<endl<<swapCount<<endl;

    return 0;
}

