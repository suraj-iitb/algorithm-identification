#include <iostream>
#include <vector>
#include <sstream>

void CountingSort(std::vector<int>& A, std::vector<int>& B, int k)
{
    std::vector<int> C(k+1);
    int n = A.size();
    
    for(int i = 0; i < k+1; i++){
	C[i] = 0;
    }

    /* C[i] に i の出現数を記録する */
    for(int j = 0; j < n; j++){
	C[A[j]]++;
    }

    /* C[i] に i 以下の数の出現数を記録する*/
    for(int i = 1; i < k+1; i++){
	C[i] = C[i] + C[i-1];
    }

    for(int j = n-1; j >= 0; j--){
        B[C[A[j]]-1] = A[j];
        C[A[j]]--;
    }
}

int main(int argc, char **argv){
    int n;
    std::cin >> n;

    std::vector<int> A(n), B(n);
    int max = 0;
    
    for(int i = 0; i < n; i++){
	std::cin >> A[i];
	max = A[i] > max ? A[i] : max;
    }

    CountingSort(A, B, max);
    
    std::stringstream ss;
    std::string sep = "";
    for(int i = 0; i < n; i++){
	ss << sep << B[i];
	sep = " ";
    }
    std::cout << ss.str() << std::endl;
    
}

