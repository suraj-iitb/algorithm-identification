#include <iostream>

using namespace std;

int a[101];
int l;

void printList()
{
  for(int i = 0; i < l-1; ++i) cout << a[i] << " ";
  cout << a[l-1] << endl;
}

void isort()
{
  printList();
  for(int j = 1; j < l; ++j){
    int key = a[j], i = j-1;
    while(i >= 0 && a[i] > key){
      a[i+1] = a[i];
      --i;
    }
    a[i+1] = key;
    printList();
  }
}

int main()
{
  while(cin>>l && l){
    for(int i  = 0; i < l; ++i) cin >> a[i];
    isort();
  }

  return 0;
}
