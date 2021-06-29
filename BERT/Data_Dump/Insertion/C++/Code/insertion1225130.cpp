
#include <sstream>
#include <string>
#include <iostream>
#include <vector>

void insertionSort( std::vector< int >& vec )
{
  for( int i = 1; i < vec.size(); ++i )
  {
    int v = vec[i];
    int j = i - 1;
    while( ( j >= 0 ) && ( vec[j] > v ) )
    {
      vec[j + 1] = vec[j];
      --j;
    }
    vec[j + 1] = v;
    
    for( std::vector < int >::iterator it = vec.begin(); it != vec.end() - 1; ++it )
    {
      std::cout << *it << " ";
    }
    std::cout << vec.back() << std::endl;
  }
}

int main()
{
  std::ios::sync_with_stdio( false );
  int length = 0;
  std::string buffer;
  std::cin >> length; std::cin.ignore();
  std::getline( std::cin, buffer );
  std::istringstream iss( buffer );

  std::cout << buffer << std::endl;

  int n;
  std::vector < int > vec;
  vec.reserve( length );
  while( iss >> n ) { vec.push_back( n ); }

  insertionSort( vec );
}
