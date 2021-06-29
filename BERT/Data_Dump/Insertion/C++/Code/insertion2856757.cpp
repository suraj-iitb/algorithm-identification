    #include <bits/stdc++.h>
    using namespace std;
     
    int main () 
    {
        int N;
        std::cin >> N;
        
        int A[N];
        for (int i = 0; i < N; i++) 
        {
            std::cin >> A[i]; 
        }
        for (int k = 0; k < N; k++) 
        {
            if (k != N-1) std::cout << A[k] << " ";
            else          std::cout << A[k] << std::endl;
        }
        
        for (int i = 1; i < N; i++) 
        {
            int point = A[i];
            
            int j = i-1;
            for(; j >= 0 and A[j] > point; )
            {
                A[j+1] = A[j];
                j--;
            }
            A[j+1] = point;
            
            for (int k = 0; k < N; k++) 
            {
                if (k != N-1) std::cout << A[k] << " ";
                else          std::cout << A[k] << std::endl;
            }
        }
        
        return 0;
    }
