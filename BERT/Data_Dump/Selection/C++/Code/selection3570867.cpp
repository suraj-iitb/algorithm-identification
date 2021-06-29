#include <iostream>

using namespace std;

int selectionSort(int A[],int n){
    int counts = 0;
    for(int i=0;i<n;i++){
        int minn = i;
        for(int j=i;j<n;j++){
            if(A[j]<A[minn]){
                minn = j;
            }
        }
        if(minn!=i){
            int temp = A[i];
            A[i] = A[minn];
            A[minn] = temp;
            counts++;
        }
    }
    return counts;
}
int main()
{
    int n;
    cin>>n;
    int A[n];
    for(int i=0;i<n;i++){
        cin>>A[i];
    }
    int counts = selectionSort(A,n);
    for(int i=0;i<n;i++){
        if(i>0) cout<<" ";
        cout<<A[i];
    }
    cout<<endl;
    cout<<counts<<endl;
    return 0;
}


