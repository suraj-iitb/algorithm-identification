#include <iostream>

using namespace std;

int main(void)
{
   int N;
   cin >> N;
   
   int A[N];
   for(int i = 0; i < N; i++)
   {
       cin >> A[i];
   }
   
   int C = 0;
   
   for(int i = 0; i < N; i++)
   {
       int minj = A[i];
       int J = i;
       
        for(int j = i + 1; j < N; j++)
       {
           if(A[j] < minj)
           {
               minj = A[j];
               J = j;
           }
       }
       
       if(minj < A[i])
       {
            int T = A[i];
            A[i] = minj;
            A[J] = T;
            C++;    
       }
   }
   
    for(int i = 0; i < N - 1; i++)
   {
       cout << A[i] << " ";
   }
   cout << A[N - 1] << endl;
   
   cout << C << endl;
    
}
