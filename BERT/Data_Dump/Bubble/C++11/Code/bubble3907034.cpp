//==================================================================================================
// Name        : Noragami.cpp
// Author      : lotus.eater086
// Copyright   : If you're reading this then this warning is for you. Every word you read of this 
//               useless fine print is another second of your life. Don't you've other things to do?
//               Is your life so empty that you honestly can't think of a better way to spend these
//               moments ? Or are you so impressed with authority that you give respect and 
//               credence to all who claim it ? Do you read everything you're supposed to read ? Do
//               you think everything you're supposed to think ? Buy what you're told you should 
//               want ? Get out of your apartment . Meet a member of the opposite sex. Stop the 
//               excessive shopping and self-improvement . Quit your boring job.
//               Start a fight. Prove you're alive. If you don't claim your humanity you'll become a
//               statistic. You've been warned !

// Description : 
// Date        : 2019-10-03
// Time        : 12:07:03
// Directory   : C:\Users\Lenovo\cpPractise\deliberatePractise\code_folder\.vscode
// FilePath    : C:\Users\Lenovo\cpPractise\deliberatePractise\code_folder\.vscode\Noragami.cpp
//==================================================================================================
    

#include <bits/stdc++.h>
#define LL long long
#define endl "\n"

using namespace std ;
    
//
template < typename T >

inline T read( T &x )
{

    x = 0 ;

    int f = 0 ;

    char ch = getchar() ;

    while( ch < '0' || ch > '9' )  {

        f |= ( ch == '-' ) , ch = getchar() ;

    }

    while( ch >= '0' && ch <= '9' )  {

        x = ( x << 1 ) + ( x << 3 ) + ch - '0' , ch = getchar() ;

    }

    return x = f ? -x:x ;

}
//

int cnt = 0 ; 

void bubble_sort( vector<int> &v , int n )
{

    for( int i = 0 ; i < n ; i++ )  {

        for( int j = n-1 ; j >= i+1 ; j-- )  {

            if( v[j] < v[j-1] )  {

                cnt++ ;

                swap(v[j],v[j-1]) ;  

            }

        }

    }

}

void print_vector( vector<int> v )
{

    for( int i = 0 ; i < v.size() ; i++ )  {

        if( i == 0 )  cout << v[i] ;

        else  cout << " " << v[i] ;

    }

    cout << endl ; 

}

void solve( void )
{

    int n ;

    cin >> n ;

    vector<int> v( n ) ;

    for( int i = 0 ; i < n ; i++ )  cin >> v[i] ;

    bubble_sort(v,n) ;

    print_vector(v) ;

    cout << cnt << endl ;  

}

int main( void )

{

    //ios_base::sync_with_stdio( false ) ;  cin.tie( NULL ) ;  cout.tie( NULL ) ;

  

    if( 0 )  {

        int t = 100 ;

        for( int i = 1 ; i <= t ; i++ )  solve() ;

    }

    else  {

        solve() ;

    }

    

    return 0 ;

}

