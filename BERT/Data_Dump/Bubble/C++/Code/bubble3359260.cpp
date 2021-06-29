#include <iostream>
using namespace std;
const int Max = 200;

int a[Max], Count = 0;
void BubbleSort(int a[], int N)
{
     int flag = 1, i = 0;
     while(flag)
     {
         flag = 0;
         for(int j=N-1; j>i; j--)
         {
             if(a[j]<a[j-1])
             {
                 int temp = a[j];
                 a[j] = a[j-1];
                 a[j-1] = temp;
                 flag = 1;
                 Count++;
             }
         }
         i++;
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
    BubbleSort(a, N);
    for(int i=0; i<N-1; i++)
        cout << a[i] << " ";
     cout << a[N-1] << endl;
     cout << Count << endl;
    return 0;
}

