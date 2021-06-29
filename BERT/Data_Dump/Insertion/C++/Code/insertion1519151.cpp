#include <iostream>
using namespace std;

int n;
int * a;

void output()
{
  for (int i = 0; i < n; i++)
  {
    if (i) cout << ' ';
    cout << a[i];
  }
  cout << endl;
}

int main()
{
  cin >> n;
  a = new int[n];
  for (int i = 0; i < n; i++)
  {
     cin >> a[i];
  }
  output();

  for (int i = 1; i < n; i++)
  {
    int key = a[i];
    int j = i - 1;
    while (j >= 0 && key < a[j])
    {
      a[j+1] = a[j];
      j--;
    }
    a[j+1] = key;
    output();
  }
  return 0;
}
