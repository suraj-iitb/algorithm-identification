#include <cstdio>
#include <iostream>
#include <climits>
#include <cmath>
#include <utility>
#include <vector>

#define MAX 10010

using namespace std;

template <typename T>
class Sort
{
public:
  Sort();
  Sort(vector<T> &arr){A = arr;}
  vector<T> A;
  void dispArr()
  {
    for(int i = 0; i < A.size()-1 ; i++) cout << A[i] << " ";
    cout << A[A.size()-1] << endl;
  }
  void merge(int l, int m, int r)
  {
    int n1 = m - l;
    int n2 = r - m;
    vector<T> L, R;
    L.resize(n1+1);
    R.resize(n2+1);
    for(int i = 0; i < n1; i++) L[i] = A[l + i];
    for(int i = 0; i < n2; i++) R[i] = A[m + i];
    L[n1] = INT_MAX;
    R[n2] = INT_MAX;
    int a = 0;
    int b = 0;
    for(int i = l; i < r; i++)
    {
      if(L[a] <= R[b])
      {
        A[i] = L[a];
        a++;
      }
      else
      {
        A[i] = R[b];
        b++;
      }
    }
  }

  void mergeSort(int l, int r)
  {
    if(l + 1 < r){
      int m = (l + r) / 2;
      mergeSort(l, m);
      mergeSort(m, r);
      merge(l, m ,r);
    }
  }

  int partition(int p, int r)
  {
    T x = A[r];
    int i = p-1;
    T tmp;
    for(int j = p; j < r; j++)
    {
      if(A[j] <= x)
      {
        i++;
        tmp = A[i];
        A[i] = A[j];
        A[j] = tmp;
      }
    }
    tmp = A[i+1];
    A[i+1] = A[r];
    A[r] = tmp;
    return i+1;
  }

  void quicksort(int p, int r)
  {
    if(p < r)
    {
      int q = partition(p,r);
      quicksort(p, q-1);
      quicksort(q+1, r);
    }
  }
};

class Card
{
public:
  char suit;
  int num;

  bool operator < (const Card& another) const
  {
    return num < another.num;
  }
  bool operator <= (const Card& another) const
  {
    return num <= another.num;
  }
  bool operator > (const Card& another) const
  {
    return num > another.num;
  }
  bool operator >= (const Card& another) const
  {
    return num >= another.num;
  }
  bool operator == (const Card& another) const
  {
    return (suit == another.suit) && (num == another.num);
  }
  void operator = (const int another)
  {
    num = another;
  }
};

int main()
{
  int n;
  cin >> n;
  vector<Card> arr;
  for(int i = 0; i < n; i++)
  {
      Card tmp;
      //cin >> tmp;
      cin >> tmp.suit >> tmp.num;
      arr.push_back(tmp);
  }
  Sort <Card> merge(arr), quick(arr);
  merge.mergeSort(0,n);
//  merge.dispArr();
  quick.quicksort(0,n-1);
//  quick.dispArr();
  bool flag = true;
  for(int i = 0; i < n; i++)
    flag = (flag && merge.A[i] == quick.A[i]);
  cout << (flag ? "Stable" : "Not stable") << endl;
  for(int i = 0; i < n; i++)
    cout << quick.A[i].suit << " " << quick.A[i].num << endl;
  return 0;
}
