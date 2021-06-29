#include <iostream>
using namespace std;

int main ()
{
    int N, v, j;
    cin >> N;
    int A[N];
    
    for(int i = 0; i < N; i++)
    {
      cin >> A[i];
    }
    
   for (int i = 1; i < N; i++)
   {
     for(int k = 0; k < N-1; k++)
     {
       cout << A[k] << " ";
     }
     cout << A[N-1] << endl;
       
     v = A[i];
     j = i - 1;
     while (j >= 0 && A[j] > v)
     {
       A[j+1] = A[j];
       j--;
     }
     A[j+1] = v;
   }
    
     for(int k = 0; k < N-1; k++)
     {
       cout << A[k] << " ";
     }
     cout << A[N-1] << endl;
         
  return 0;
}
