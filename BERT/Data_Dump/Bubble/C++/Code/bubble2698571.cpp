#include<iostream>

void printData(int data[], int dataNum ) {
    for( int i = 0; i < dataNum; i++ ){
        if( i != 0 ) {
            std::cout << " ";
        }
        std::cout << data[i];
    }
    std::cout << std::endl;
}

void printExchangeCnt( int cnt){
    std::cout << cnt;
    std::cout << std::endl;
}

int main() {
    int lineCnt;
    std::cin >> lineCnt;

    int data[lineCnt];
    for( int i = 0; i < lineCnt; i++ ){
        std::cin >> data[i];
    }

    int swCnt = 0;
    for( int i = 0; i < lineCnt; i++ ) {
        bool exchanged = false;
        for( int k = lineCnt - 1; k-1 >= i; k-- ) {
            if( data[k] < data[k-1]) {
                std::swap(data[k],data[k-1]);
                exchanged = true;
                swCnt++;
            }
        }
        if( !exchanged ) {
            break;
        }
    }

    printData(data,lineCnt);
    printExchangeCnt(swCnt);
}
