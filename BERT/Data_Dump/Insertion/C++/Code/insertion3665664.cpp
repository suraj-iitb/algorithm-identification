#include <iostream>
using namespace std;
int main(void){
    // Your code here!
    int n,card[101],c,j;   //nはカードの数, boxは比較するときの避難場
    cin >> n;
    
    for(int i = 0;i < n; i++){   //カードに値を入力
        cin >> c;
        card[i] = c;
        
        //cout << "card[" << i << "]" << card[i] << endl;
    }

    
    
    for(int i = 0; i < n;i++){    //左から比較していく
        int v = card[i];
        j = i - 1;
        
        while(j >= 0 && card[j] > v){
            card[j+1] = card[j];
            j--;
        }
        card[j+1] = v;
        
        for(int m = 0; m < n; m++){
            cout << card[m] << ((m == n-1)?'\n' : ' ');
        }
            
        
    }
        
    
}

