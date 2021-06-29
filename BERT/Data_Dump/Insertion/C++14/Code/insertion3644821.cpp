#include <iostream>
#include <vector>
#include <algorithm>

void put( std::vector<int> &b ){
  for( int i=0; i<b.size(); ++i ){
    if (i){ std::cout << " "; }
    std::cout << b[i];
  }
  std::cout << std::endl;
}

int main(){
  int n; std::cin >> n;
  std::vector<int> b(n);
  for( int &v : b ){ std::cin >> v; }
  put(b);
  for( int i=1; i<n; ++i ){
    for( int j=0; j<i; ++j ){
      if ( b[j] >= b[i] ){
        b.insert( b.begin() + j, b[i] );
        b.erase( b.begin() + i + 1 );
        break;
      }
    }
    put(b);
  }
}
