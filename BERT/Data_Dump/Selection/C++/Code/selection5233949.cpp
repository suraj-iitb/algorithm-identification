#include <iostream>
using namespace std;
const int MAXSIZE = 100;

int SelectSort(int A[], int N)
{
   int minj, j, t, sw=0;
   for(int i = 0; i< N-1 ; ++i)
   {
       minj = i;
       for (j=i; j<N;++j)
       {
           if(A[j] < A[minj]) minj = j;
       }
       //swap(A[i], A[minj]);
        t = A[i];
        A[i] = A[minj];
        A[minj] = t;
       if(i != minj) sw++;
   }
   return sw;
}

int main()
{
    int A[MAXSIZE], N, sw;
    cin >> N;
    for(int i=0; i<N; ++i)  cin >> A[i];
    
    sw = SelectSort(A,N);
    for(int i=0; i<N; ++i)
    {
        if(i) cout << " ";
        cout << A[i];
    }
    cout << endl;
    cout << sw << endl;
    return 0;
}
