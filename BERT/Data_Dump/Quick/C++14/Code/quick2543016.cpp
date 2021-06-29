#include <iostream>
#include <algorithm> // next_permutation
#include <iomanip>
#include <cmath>
#include <vector>
#include <sstream>
#include <string>
#include <cstdio>
#include <stack>
#include <queue>
#include <list>
#include <numeric> //accumulate
//#include <unordered_map> //???????????\??¢??°
#include <fstream> //ifstream, ofstream

#define NDEBUG //NDEBUG???#include <cassert>???????????????????????????????????´???assert?????????????????????????????????NDEBUG????????????????????¨
#include <cassert> //assert


using namespace std;

//???????????°??????TEST????????????????????¬???????????????????????????????????¢????????????
#define TEST //*******************************************************************************************************************************************
//?????????????????¨??§?????\????????????????????????????????°?????????????¨???????????????????dout???????????????????????§???????????¬??????????????????????????????????????????
//??????????????????????????????????????????????????????????§?CPU???????£??????????????????§???TLE?????????????????????????????????????????§????????¨???                           ????????????????????????cerr????????£????????????????????????????????????
#ifdef TEST
#define dout cout
#else
stringstream dummy; //???????????°??????dout?????????????????????????????????
#define dout dummy.str(""); dummy.clear(stringstream::goodbit); dummy //dummy?????????????????????????????????????????¨?????¢?????¢???????????????
//???????????¨??????????????????goodbit?????????????????????????????¨???????????´????????????????????????????????¨?????°?????????????????§???????????????????????????????????? http://d.hatena.ne.jp/linden/20060427/p1
#endif

//?¨??????????????????????????????????????????????????????´??????OUTPUT2TEXTFILE????????????????????¬???????????????????????????????????¢????????????
//#define OUTPUT2TEXTFILE //*******************************************************************************************************************************************
#ifdef OUTPUT2TEXTFILE
#define dout outputfile //??¨????????????TLE????????§?????????dout?????¨??¨??????????????¢????????????????????????????????????????????§????¨????????????´??????????????£??????????????????????¨?????????????????????????????????????????????§?????????????????????
//TEST??????????????????????????¨???outputfile??????????????????????????????
#define OUTPUTFILENAME "output.txt"
ofstream outputfile(OUTPUTFILENAME);
#define OutputFilePath "/Users/Nag/Documents/Prgm/Test/DerivedData/Test/Build/Products/Debug/output.txt"
#endif

#define disp(A) dout << #A << " = " << (A) << endl
#define disP(A) dout << setw(3) << (A) << " " // << setw(3) ??????????????\????????????
#define rep(i,a,n) for(int (i)=(a); (i)<(n); (i)++)

#define dispAll(A,n) dout << #A << " = "; rep(j, 0, (n)) {disP(A[j]);} dout << endl

typedef pair<int,int> pii;
typedef vector<int> vi;
typedef unsigned long long ll;

const int INF = 1e9-1;






int partition(pair<char,int> A[], int p, int r) { //A[p] ... A[r] ??¨????????°?????????????°??????????A[r]?????????????????¨?????????pivot??\??????pivot????????§????????????2????????°??????????????????????????????????????????pivot???index?????????
    int pivot = A[r].second;
    
    int i = p-1; //i?????§???pivot??\???????????????????¬????pivot??\?????????????????????????????£?????´??????i+1?????´????????????????????°??????
    
    rep(j,p,r) {
        if( A[j].second <= pivot ) {
            i++;
            
            //swap A[i] and A[j]
            auto tmp = A[i];
            A[i] = A[j];
            A[j] = tmp;
        }
    }
    
    //swap A[i+1] and pivot=A[r]
    auto tmp = A[i+1];
    A[i+1] = A[r];
    A[r] = tmp;

    return i+1; //i?????§???pivoit??\??????????????????i+1???pivot
}



void quickSort(pair<char,int> A[], int p, int r) {
    if(p<r) {
        int q = partition(A, p, r);
        
        quickSort(A, p, q-1);
        quickSort(A, q+1, r);
    }
}



int main(){
    
    int N; cin >> N;
    
    vector < pair<char,int> > card, cardCopy;
    char suit;
    int number;
    rep(i,0,N) {
        cin >> suit >> number;
        
        card.push_back( make_pair(suit, number) );
    }

    cardCopy = card;

    
    //??????????????§??????????????? (second????´????number???????????????????????????????????¢??°???????????§??????????????????)
    stable_sort(cardCopy.begin(), cardCopy.end(),
         [](const pair<char,int> &x, const pair<char,int> &y) {return x.second < y.second;}   );
    
//    //test display
//    rep(i,0,N) {
//        disP(cardCopy[i].first);
//        disP(cardCopy[i].second);
//        dout << endl;
//    }
//    dout << "------------\n";

    
    //??????????????§?????????????????????
    quickSort(&card[0], 0, N-1);
    
    
    //stable or unstable?
    bool isStable = true;
    rep(i,0,N) {
        if( card[i].first != cardCopy[i].first ) {
            isStable = false;
            break;
        }
    }
    
    cout << (isStable ? "Stable" : "Not stable" ) << endl;

    
    //display
    rep(i,0,N) {
        cout << card[i].first << " " << card[i].second << endl;
    }
    
    
    
    
    
#ifdef OUTPUT2TEXTFILE
    outputfile.close();
    cout << "\"" << OutputFilePath << "\"" << endl;
#endif
    
    return 0;
}
