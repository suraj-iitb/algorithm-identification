#include <iostream>
using namespace std;

int N;
int main()
{
    int A[100];
    cin>>N;
    if (N<1 or N>100){
        cout<<"Program Ends, Invalid Input";
        return 0;
    }
    for (int i=0; i<N; i++)
    {
        cin>>A[i];
    }
    for(int i=0; i<N; i++){
        cout<<A[i];
        if(i!=N-1){
            cout<<" ";
        }
    }
    cout<<"\n";
    
    for (int i=1; i<= N-1; i++){
        int key=A[i];
        int j = i - 1;
        while(j>=0 and A[j]>key){
            A[j+1] = A[j];
            j--;
        }
        A[j+1]=key;
        int k;
        for (k=0; k<N; k++){
            cout<<A[k];
            if (k+1<N){
                cout<<" ";
            }
        }
        cout<<endl;
    }
    return 0;
}

