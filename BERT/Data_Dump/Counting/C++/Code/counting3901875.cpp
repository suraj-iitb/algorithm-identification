#include <iostream>
#include <cmath>
#define maxint 2147483647;
typedef long long ll;
void dump(int a[],int n)
{
  for (int codeTest = 0; codeTest < n; ++codeTest) {
    if (codeTest!=0)std::cout << " ";
    std::cout << a[codeTest];
  }
  std::cout << '\n';
}

int main() {
  int n,tmp;
  int a[10001];
  for (int i = 0; i <= 10000; ++i){a[i]=0;}
  std::cin >> n;
  for (int i = 0; i < n; ++i) {
    std::cin >> tmp;
    ++a[tmp];
  }
  bool b=false;
  for (int c1 = 0; c1 <= 10000; ++c1) {
    for (int c2=0; c2<a[c1];++c2){
      if (b)std::cout << " ";
      std::cout <<c1;
      b=true;
    }
  }
  std::cout << '\n';
  return 0;
}

