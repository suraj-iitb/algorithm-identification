#include <iostream>
#include <vector>

using namespace std;

void print_attr(vector<int> v) {
 for(int i = 0;i < v.size();i++) {
  cout << v.at(i);
 
  if(i < v.size() - 1)
   cout << " ";
 }
 
 cout << endl;
}

void insertion_sort(vector<int> va) {
 int i, j;
 int tmp;
 
 for(int i = 0;i < va.size();i++) {
  tmp = va.at(i);
  j = i - 1;

  while(0 <= j && va[j]>tmp) {
      va[j + 1] = va[j];
      j--;
  }
   
  va[j + 1] = tmp;
  print_attr(va);
 }
}

int main() {
 int n;
 vector<int> a;

 cin >> n;

 a.resize(n);

 for(int i = 0;i < n;i++) {
  cin >> a[i];
 }
 
 insertion_sort(a);
 
 return 0;
}

 
