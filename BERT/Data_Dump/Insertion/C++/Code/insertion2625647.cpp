#include <iostream>
using namespace std;

void output(int A[], int N)
{
    for( int loop = 0;loop < N;loop++ )
    {
        if(loop != 0)
        {
            cout << " ";
        }
        cout << A[loop];
    }
    cout << endl;
    return;
}

void insertionSort(int A[], int N)
{
    output(A,N);
    int v;
    int j;
    for( int i = 1; i <= N-1; i++ )
    {
        v = A[i];
        j = i - 1;
        while( (j >= 0) && (A[j]>v) )
        {
            A[j+1] = A[j];
            j--;
            A[j+1] = v;
        }
        output(A,N);
    }
    return;
}

int main(void){
    string maxNumSentence="";
    int input[1000];
    int rows;
    
    cin >> rows;
    int inputNum = 0;
    while( cin >> input[inputNum] )
    {
        inputNum++;
    }
    
    insertionSort(input,rows);
    return 0;
}
