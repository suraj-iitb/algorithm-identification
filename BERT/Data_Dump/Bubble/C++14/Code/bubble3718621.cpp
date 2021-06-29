#include <iostream>
#include <vector>
using namespace std;
int a[100];

int bubbleSort(int a[], int n) {
  bool flag = true;
  int tmp, count=0;
  while (flag) {
    flag = false;
    for (int i = n-1; i > 0; --i) {
      if (a[i] < a[i-1]) {
        tmp = a[i];
        a[i] = a[i-1];
        a[i-1]=tmp;
        flag=true;
        count++;
      }
    }
  }
  return count;
}

int main(int argc, char *argv[])
{
  int n, num=0;
  cin >> n;
  for (int i = 0; i < n; ++i) {
    cin >> a[i];
  }
  num=bubbleSort(a, n);
  for (int i = 0; i < n; ++i) {
    cout << a[i];
    if(i!=n-1)cout<<" ";
    else cout<<"\n";
  }
  cout<<num<<endl;
  return 0;
}

