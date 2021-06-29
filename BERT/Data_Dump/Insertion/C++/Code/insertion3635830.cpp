#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

int main()
{
    int N;
    std::vector<int> A;
    std::cin >> N;
    A.resize(N);

    for(int i=0; i<N; ++i)
        std::cin >> A[i];

    for(int i=0; i<N-1; ++i)
        std::cout << A[i] << ' ';
    std::cout << A[N-1];
    std::cout << std::endl;

    for(int i=1; i<N; ++i)
    {
        int v = A[i];
        int j = i-1;
        while(j>=0 && A[j]>v)
        {
            A[j+1] = A[j];
            j--;
        }
        A[j+1] = v;

        for(int a=0; a<N-1; ++a)
            std::cout << A[a] << ' ';
        std::cout << A[N-1];

        std::cout << std::endl;
    }

    return 0;
}

