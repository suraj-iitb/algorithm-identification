#include <iostream>                                             
using namespace std;                                            
                                                                
int main(void) {                                                
  int N;                                                        
  cin >> N;                                                     
  int A[N];                                                     
  for (int i=0; i<N; i++) {                                     
    cin >> A[i];                                                
  }                                                             
  int v, j;                                                     
  for (int i=0; i<N; i++) {                                     
    v = A[i];                                                   
    j = i-1;                                                    
    while (j>=0 && A[j]>v) {                                    
      A[j+1] = A[j];                                            
      j--;                                                      
      A[j+1] = v;                                               
    }                                                           
    for (int k=0; k<N; k++) {                                   
      cout << (k==0?"":" ") << A[k] << flush;                   
    }                                                           
    cout << endl;                                               
  }                                                             
  return 0;                                                     
}                                                               
                   
