#include <iostream>
#include <vector>

using namespace std;

int main(){
  cin.tie(0);
  ios::sync_with_stdio(false);

  int N;
  cin >> N;
  vector<int> A(N);
  for(int i=0; i<N; i++)
	cin >> A[i];

  for(int i=1; i<N; i++){
	int key = A[i];
	int j=i-1;
	for(int i=0; i<N-1; i++)
	  cout << A[i] << " ";
	cout << A[N-1] << endl;
		
	while(j >= 0 && A[j] > key){
	  A[j+1] = A[j];
	  j--;
	}
	A[j+1] = key;
  }
  for(int i=0; i<N-1; i++)
	cout << A[i] << " ";
  cout << A[N-1] << endl;
  
  return 0;
}
