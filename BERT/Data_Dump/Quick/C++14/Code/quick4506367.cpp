#include<iostream>
#include<algorithm>
#include<vector>
#include<utility>

template< typename iterator >
iterator partition( iterator first, iterator last)
{
    auto x = *(last-1) ;
    int i = -1;
    for( iterator iter = first ; iter != last-1 ; ++iter )
    {
        if( *iter <= x )
        {
            ++i ;
            std::swap( *iter, *(first+i) ) ;
        }
    }
    std::swap( *(last-1), *(first+i+1) ) ;

    return first+i+1 ;
}

template< typename iterator >
void quick_sort( iterator first, iterator last )
{
    if( first < last )
    {
        iterator mid = partition( first, last ) ;
        quick_sort( first, mid ) ;
        quick_sort( mid+1, last ) ;
    }
}

struct Card
{
    char mark ;
    int num ;
    bool operator <=( Card & l )
    {
        if( num <= l.num )
        {
            return true ;
        }
        else
        {
            return false ;
        }
    }

    bool operator <( const Card & l ) const
    {
        if( num < l.num )
        {
            return true ;
        }
        else
        {
            return false ;
        }
    }
} ;

int main()
{
    int n ;
    std::cin >> n ;

    std::vector<Card> A(n) ;
    for( int i = 0 ; i < n ; ++i )
    {
        std::cin >> A.at(i).mark >> A.at(i).num ;
    }
    std::vector<Card> B(n) ;
    for( int i = 0 ; i < n ; ++i )
    {
        B.at(i).mark = A.at(i).mark ;
        B.at(i).num = A.at(i).num ;
    }

    quick_sort( A.begin(), A.end() ) ;
    std::stable_sort( B.begin(), B.end() ) ;
    
    bool flag = 0 ; 
    for( int i = 0 ; i < n ; ++i )
    {
        if( A.at(i).mark != B.at(i).mark )
        {
            flag = 1 ;
        }
    }
    
    if(flag)
    {
        std::cout << "Not stable" << std::endl ;
    }
    else
    {
        std::cout << "Stable" << std::endl ;
    }

    for( int i = 0 ; i < n ; ++i )
    {
        std::cout << A.at(i).mark << " " << A.at(i).num << std::endl ;
    }
}

