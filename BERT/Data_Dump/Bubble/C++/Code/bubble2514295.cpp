#include <iostream>                                             
using namespace std;                                            
                                                                
int main(void) {                                                
  int N;                                                        
  cin >> N;                                                     
  int A[N];                                                     
  for (int i=0; i<N; i++) {                                     
    cin >> A[i];                                                
  }                                                             
  int flag = 1;                                                 
  int ans = 0;                                                  
  while (flag) {                                                
    flag = 0;                                                   
    for (int j=N-1; j>=1; j--) {                                
      if (A[j]<A[j-1]) {                                        
        int t = A[j-1];                                         
        A[j-1] = A[j];                                          
        A[j] = t;                                               
        ans++;                                                  
        flag = 1;                                               
      }                                                         
    }                                                           
  }                                                             
  for (int i=0; i<N; i++) {                                     
    cout << (i==0?"":" ") << A[i] << flush;                     
  }                                                             
  cout << endl << ans << endl;                                  
  return 0;                                                     
}                                                               
                                                                
                                                                
                                    
