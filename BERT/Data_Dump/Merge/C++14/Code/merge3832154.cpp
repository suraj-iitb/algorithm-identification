/** BiSmIlLaHiR rAhMaNiR rAhIm **\
 
*$*$*$*$*$*$*$*$*$*$*$*$*$*$*$*$*$*$*$*$*$*$*$*$*$*
*$*                                             *$*
*$*    ||||||||  ||||||||  ||||||||  ||||||||   *$*
*$*    ||    ||  ||           ||     ||         *$*
*$*    ||||||||  ||||||||     ||     ||||||     *$*
*$*    ||    ||        ||     ||     ||         *$*
*$*    ||    ||  ||||||||  ||||||||  ||         *$*
*$*                                             *$*
*$*$*$*$*$*$*$*$*$*$*$*$*$*$*$*$*$*$*$*$*$*$*$*$*$*
 
            \**  DIIT(17th batch) **/
 
#include<bits/stdc++.h>
#define ll long long int
#define ul unsigned long long int
#define pf printf
#define sf scanf
#define endl "\n"
#define pb push_back
#define eb emplace_back
#define makep make_pair
#define MOD 1000000007
#define PI 2*acos(0.0)
#define PII pair<ll, ll>
#define pii pair<int, int>
#define what_is(x) cerr<<#x<<" is "<<x<<endl;
#define fio() ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)
using namespace std;

ll count1=0;

void Merge(ll *A,ll *L,ll leftCount,ll *R,ll rightCount) {
    ll i,j,k;
    i = 0; j = 0; k =0;

    while(i<leftCount && j< rightCount) {
        if(L[i]  < R[j]){
            A[k++] = L[i++];
            count1++;
        }
        else{
            A[k++] = R[j++];
            count1++;
        }
    }
    while(i < leftCount){
        A[k++] = L[i++];
        count1++;
    }
    while(j < rightCount){
        A[k++] = R[j++];
        count1++;
    }
}
void asif(ll *A,ll n) {
    ll mid,i;
    if(n < 2) return;

    mid = n/2;
    ll L[mid];
    ll R[n-mid];

    for(i = 0;i<mid;i++) L[i] = A[i];
    for(i = mid;i<n;i++) R[i-mid] = A[i];

    asif(L,mid);
    asif(R,n-mid);
    Merge(A,L,mid,R,n-mid);
}

int main()
{
    fio();
    ll i,n;
    cin>>n;
    ll a[n];
    for(i=0;i<n;i++)
        cin>>a[i];
    asif(a,n);
    //sort(a,a+n);
    for(i=0;i<n-1;i++)
        cout<<a[i]<<" ";
    cout<<a[n-1]<<endl<<count1<<endl;
}
