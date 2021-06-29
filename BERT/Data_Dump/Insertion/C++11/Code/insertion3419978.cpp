#include <iostream>
using namespace std;

void printA(int A[],int c)
{
    for (int i=0;i<c;i++){
        cout << A[i];
        if(i<(c-1)) cout << " ";
    }
    cout << endl;
}

int main()
{
    int c,key,j;
    cin >> c;

    int A[1000];
    for (int i=0; i<c; i++) {
        cin >> A[i];
    }
    printA(A,c);
    for (int i=1;i<c;i++)
    {
        key = A[i];
        j = i - 1;

        A[j+1]=key;
        
        while (j>=0 && A[j]>key)
        {
            A[j+1]=A[j];
            j--;
        }
        A[j+1]=key;
        printA(A,c);
    }    
    return 0;
}
