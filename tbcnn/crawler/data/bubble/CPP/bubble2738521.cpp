#include <iostream>

int main(int argc, char const *argv[])
{
  using namespace std;
  bool flag = true;
  int n;
  int count = 0;
  cin >> n;
  int * a = new int[n];
  for (int i = 0; i < n; i++)
  {
    cin >> a[i];
  }
  for (int i = 0; flag; i++)
  {
    flag = false;
    for (int j = n - 1; j > i; j--)
    {
      if (a[j] < a[j - 1])
      {
        int temp = a[j];
        a[j] = a[j - 1];
        a[j - 1] = temp;
        count++;
        flag = true;
      }
    }
  }
  for (int i = 0; i < n - 1; i++)
  {
    cout << a[i] << ' ';
  }
  cout << a[n - 1] << endl;
  cout << count << endl;
  delete[] a;
  return 0;
}

