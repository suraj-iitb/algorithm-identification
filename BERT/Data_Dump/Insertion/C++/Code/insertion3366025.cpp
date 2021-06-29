#include <iostream>
using namespace std;

void printData(int seq[], int n)
{
    int i;

    //数列の中身を表示
    for (i = 0; i < n; i++)
    {
        cout << seq[i];
        if (i != n - 1)
            cout << ' ';
    }
    cout << endl;
}

/**********************************************/

void insertSort(int seq[], int n)
{
    int i;
    int j;
    int v;

    //挿入ソート
    for(i = 1; i <= (n - 1); i++){
        v = seq[i];
        j = i - 1;
        
        while(j >= 0 && seq[j] > v){
            seq[j + 1] = seq[j];
            j--;
        }
        seq[j + 1] = v;
        printData(seq, n);
    }
    
    return;
}
/**********************************************/

int main()
{
    //データ定義
    int sequenceLength; //数列の長さ
    int sequence[100]; //数列
    int i;

    //数列の長さを取得
    cin >> sequenceLength;

    //数列の要素を取得
    for(i = 0; i < sequenceLength; i++){
        cin >> sequence[i];
    }

    //数列を表示
    printData(sequence, sequenceLength);

    //挿入ソート
    insertSort(sequence, sequenceLength);

    return 0;
}
