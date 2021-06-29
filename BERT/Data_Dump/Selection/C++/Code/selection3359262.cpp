#include <iostream>
using namespace std;
const int Max = 200;

int a[Max], Count = 0;
void SelectSort(int a[], int N)
{
      for(int i=0; i<N-1; i++)
      {
          int minj = i;
          for(int j=i+1; j<N; j++)
          {
              if(a[j] < a[minj])
                minj = j;
          }
          if(i!=minj)
          {
              int temp = a[i];
              a[i] = a[minj];
              a[minj] = temp;
              Count++;
          }
      }
}

int main()
{
    int N;
    cin >> N;
    for(int i=0; i<N; i++)
    {
        cin >> a[i];
    }
    SelectSort(a, N);
    for(int i=0; i<N-1; i++)
        cout << a[i] << " ";
     cout << a[N-1] << endl;
     cout << Count << endl;
    return 0;
}

