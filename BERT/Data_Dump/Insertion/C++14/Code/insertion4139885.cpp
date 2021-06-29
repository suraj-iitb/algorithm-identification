#include <bits/stdc++.h>
#include <chrono>
using namespace std;

using _i64 = int64_t;
using _u64 = uint64_t;
using _f64 = double;

#define _for(i, start, end) for(_i64 i = (_i64)start; i < (_i64)end; ++i)
#define _rep(i, number) _for(i, 0, number)
#define _foreach(e, data) for(auto& e : data)
#define _all(data) data.begin(), data.end()

template<typename type>
_i64 _size(const type& data) { return static_cast<_i64>(data.size()); }
template<typename type, size_t size>
_i64 _size(const type (&)[size]) { return static_cast<_i64>(size); }

enum _flag : bool { able = true, disable = false };

struct _time {
    _time(_flag flag) { check = flag; if(!check) { return; } gettime(start); }
    ~_time() {
        if(!check) { return; }; gettime(end);
        _i64 elapse = chrono::duration_cast<chrono::milliseconds>(end - start).count();
        cout << endl << "Time: " << elapse << " ms" << endl;
    }
    private:
    using _timer = chrono::time_point<chrono::system_clock>;
    _timer start, end; bool check;
    void gettime(_timer& time) { time = chrono::system_clock::now(); }
};

struct _ini { _ini() { ios::sync_with_stdio(false); cin.tie(nullptr); } } _ini;

int main() {
    {
        _time time(disable);
        vector<_i64> A; _i64 N, v, j; cin >> N; A.resize(N);
        _foreach(e, A) { cin >> e; }
        _rep(i, N) {
            v = A[i]; j = i - 1;
            while(j >= 0 && A[j] > v) { A[j + 1] = A[j]; --j; }
            A[j + 1] = v;
            _rep(k, N) { cout << (k != 0 ? " " : "") << A[k]; } cout << endl;
        }

    }
    return 0;
}
