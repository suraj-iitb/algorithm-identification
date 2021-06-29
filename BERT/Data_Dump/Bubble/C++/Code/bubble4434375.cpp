#include<iostream>
#include<vector>

int main()
{
    int N ;
    std::cin >> N ;
    std::vector<int> A(N) ;
    for(int i = 0 ; i<N ; ++i)
    {
        std::cin >> A.at(i) ;
    }

    bool flag = 1 ;
    int count = 0 ;
    while(flag)
    {
        flag = 0 ;
        for( int i = A.size()-1 ; i > 0 ; --i)
        {
            if(A.at(i) < A.at(i-1) )
            {
                std::swap(A.at(i),A.at(i-1)) ;
                flag = 1 ;
                ++count ;
            }
        }
    }
    

    for(std::size_t i = 0 ; i != A.size() ; ++i)
    {
        if(i == A.size() - 1)
        {
            std::cout << A.at(i) << std::endl ;
        }
        else
        {
            std::cout << A.at(i) << " " ;
        }
        
    }
    std::cout << count << std::endl ;


}
