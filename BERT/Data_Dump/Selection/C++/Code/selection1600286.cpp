#include<iostream>
using namespace std;

#define MAX 100

int main(void) {
  int n;
  int input[MAX];

  cin >> n;

  for(int i = 0; i < n; i++) {
    cin >> input[i];
  }

  int count = 0;
  
  for(int i = 0; i < n; i++) {
    int minJ = i;
    for(int j = i; j < n; j++) {
      if(input[j] < input[minJ]) {
        minJ = j;
      }
    }
    if(minJ != i) {
      count++;
    }
    swap(input[i], input[minJ]);
  }

  for(int i = 0; i < n; i++) {
    if(i == 0) {
      cout << input[i];
    }
    else {
      cout << " " << input[i];
    }
  }
  cout << endl;
  cout << count << endl;
  return 0;
}
