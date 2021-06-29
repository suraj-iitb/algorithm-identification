#include <iostream>
using namespace std;

int main()
{
  int n, flag, count = 0;
  cin >> n;
  int a[100];
  for(int i = 0; i < n; i++)
  {
    cin >> a[i];
  }
  
  flag = 1;  
    
  while (flag)
  {
    flag = 0;
      
    for (int j = n - 1; j > 0; j--)
    {
      if(a[j] < a[j-1])
      {
        int c = a[j];
        a[j] = a[j-1];
        a[j-1] = c;

        flag = 1;
        count++;
      }
    }
  }

  //out
  for(int i = 0; i < n - 1; i++)
  {
    cout << a[i] << " ";
  }
  cout << a[n-1] << endl;
    
  cout << count << endl;

  return 0;
}
