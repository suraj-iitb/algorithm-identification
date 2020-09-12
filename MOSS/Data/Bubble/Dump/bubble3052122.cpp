#include<iostream>
using namespace std;

int BubbleSort( int* a, int b )
{
    bool flag = true;
    int count = 0;

    while( flag )
    {
        flag = false;
        for( int j = b - 1; j >= 1; j-- )
        {
            if( a[j] < a[j-1] )
            {
                int temp = a[j];
                a[j] = a[j-1];
                a[j-1] = temp;
                count++;
                flag = true;                    //バブルソートが実行される際は、flagがtrueになって次のwhile文内の処理を行う。
            }                                   //ソートが実行されない場合、flagはfalseのままになり、while文を抜ける。
        }
    }
    return count;
}

int main()
{
    int n, c;

    cin >> n;

    int r[n];

    for( int i = 0; i < n; i++ )
        cin >> r[i];

    c = BubbleSort( r, n );

    for( int i = 0; i < n - 1; i++ )
        cout << r[i] << " ";
    cout << r[n-1] << endl;

    cout << c << endl;   

    return 0;
}
