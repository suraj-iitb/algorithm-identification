#include <iostream>                                             
#include <vector>                                               
                                                                
using namespace std;                                            
                                                                
int main(void) {                                                
  int N, x;                                                     
  cin >> N;                                                     
  vector<int> A;                                                
  for (int i=0; i<N; i++) {                                     
    cin >> x;                                                   
    A.push_back(x);                                             
  }                                                             
   int v, i, j;                                                 
   for (i=0; i<A.size(); i++) {                                 
    v = A[i];                                                   
    j = i-1;                                                    
    while (j>=0 && A[j]>v) {                                    
      A[j+1] = A[j];                                            
      j--;                                                      
      A[j+1] = v;                                               
    }                                                           
    for (int k=0; k<A.size(); k++) {                            
      cout << (k==0?"":" ") << A[k] << flush;                   
    }                                                           
    cout << endl;                                               
    }                                                           
}                                                               
                                
