#include <iostream>                                             
#include <vector>                                               
using namespace std;                                            
                                                                
int main (void) {                                               
  int N;                                                        
  cin >> N;                                                     
  int x;                                                        
  vector<int> A;                                                
  for (int i=0; i<N; i++) {                                     
    cin >> x;                                                   
    A.push_back(x);                                             
  }                                                             
  int flag=1, tmp;                                              
  int ans=0;                                                    
  while (flag) {                                                
    flag=0;                                                     
    for (int j=A.size()-1; j>=1; j--) {                         
      if (A[j] < A[j-1]) {                                      
        tmp = A[j-1];                                           
        A[j-1] = A[j];                                          
        A[j] = tmp;                                             
        ans++;                                                  
        flag=1;                                                 
      }                                                         
    }                                                           
  }                                                             
  for (int i=0; i<A.size(); i++) {                              
    cout << (i==0?"":" ") << A[i] << flush;                     
  }                                                             
  cout << endl << ans << endl;                                  
}                                                               
                                                                
                                        
