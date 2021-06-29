#include <iostream>

int main(int argc, char const *argv[])
{
  using namespace std;
  int n;
  cin >> n;
  int * a = new int[n];
  for (int i = 0; i < n; i++)
  {
    cin >> a[i];
  }
  int count = 0;
  for (int i = 0; i < n; i++)
  {
    int minj = i;
    for (int j = i; j < n; j++)
    {
      if (a[j] < a[minj])
        minj = j;
    }
    if (a[i] > a[minj])
    {
      swap(a[i], a[minj]);
      count++;
    }
  }
  for (int i = 0; i < n - 1; i++)
  {
    cout << a[i] << ' ';
  }
  cout << a[n - 1] << endl;
  cout << count << endl;
  return 0;
}

