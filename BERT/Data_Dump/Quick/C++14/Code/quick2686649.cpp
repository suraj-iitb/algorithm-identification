#include <cstdio>
#include <cstring>
#define rep(i,n) for(int i=0; i<(n); ++i)
#define err(...) fprintf(stderr, __VA_ARGS__)
constexpr int INF = 0x3f3f3f3f;

struct PP {
   int n;
   char c;
   PP() {}
   bool operator > (const PP& rhs) const { return (n > rhs.n); }
   bool operator < (const PP& rhs) const { return (n < rhs.n); }
   bool operator >=(const PP& rhs) const { return (n >= rhs.n);}
   bool operator <=(const PP& rhs) const { return (n <= rhs.n);}
   bool operator ==(const PP& rhs) const { return (n == rhs.n && c == rhs.c); }
   bool operator !=(const PP& rhs) const { return (n != rhs.n || c != rhs.c); }
   inline PP& operator = (int rhs){ n = rhs; return (*this); }
};

template <class T>
void swap(T& a, T& b){ T tmp = a; a = b, b = tmp; }

void merge(PP*, PP*, PP*);
void merge_sort(PP*, PP*);
PP* partition(PP*, PP*);
void quick_sort(PP*, PP*);
bool same(const PP*, const PP*, const int );

int main()
{
   static PP a[100005], b[100005];
   int N;
   scanf("%d", &N);
   rep(i, N)scanf(" %c %d", &a[i].c, &a[i].n );
   memcpy( b, a, sizeof(PP) * N );

   quick_sort(a, a+N);
   merge_sort(b, b+N);

   puts( same(a, b, N)? "Stable" : "Not stable" );
   rep(i, N) printf( "%c %d\n", a[i].c, a[i].n );

}
//=============================================================
void quick_sort(PP* begin, PP* end) {
   if( begin < end ) {
      PP* p = partition(begin, end);
      quick_sort(begin, p);
      quick_sort(p+1, end);
   }
}

PP* partition(PP* left, PP* right) {
   const PP x = *(--right);
   PP* lt = left - 1;

   for(PP* i = left; i != right; ++i) {
      if( *i <= x ) ++lt, swap( *lt, *i );
   }
   ++lt, swap( *lt, *right );

   return (lt);
}
//-------------------------------------------------------------
bool same(const PP* a, const PP* b, const int size){
   rep(i, size)
      if(a[i] != b[i])return (false);
   return (true);
}

void merge_sort(PP* begin, PP* end) {
   if( begin + 1 < end ) {
      PP* mid = begin + (end - begin) / 2;
      merge_sort(begin, mid);
      merge_sort(mid, end);
      merge(begin, mid, end);
   }
}

void merge(PP* left, PP* mid, PP* right) {
   const int hl = mid - left;
   const int hr = right - mid;
   PP L[hl+1], R[hr+1];

   L[hl] = R[hr] = INF;

   memcpy( L, left, sizeof(PP) * hl );
   memcpy( R, mid, sizeof(PP) * hr );

   int i(0), j(0);
   for(PP* k = left; k != right; ++k){
      (*k) = ( L[i] <= R[j] ) ? L[i++] : R[j++];
   }
   return ;
}


