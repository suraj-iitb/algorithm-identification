#include <iostream>

using namespace std;
int counts = 0;
void bubbleSort(int A[],int N){
    int flag = 1;
    while(flag){
        flag = 0;
        for(int j=0;j<N-1;j++){
            if(A[j]>A[j+1]){
                int temp = A[j];
                A[j] = A[j+1];
                A[j+1] = temp;
                counts++;
                flag = 1;
            }
        }
    }
}
int main()
{
    int n;
    cin>>n;
    int A[n];
    for(int i=0;i<n;i++){
        cin>>A[i];
    }
    bubbleSort(A,n);
    for(int i=0;i<n;i++){
        if(i>0) cout<<" ";
        cout<<A[i];
    }
    cout<<endl;
    cout<<counts<<endl;
    return 0;
}

