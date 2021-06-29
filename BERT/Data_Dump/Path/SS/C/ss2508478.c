#include<bits/stdc++.h>
#define rep(i,a,b) for(int i=a;i<b;i++)
#define rrep(i,a,b) for(int i=a;i>=b;i--)
#define fore(i,a) for(auto &i:a)
#pragma GCC optimize ("-O3")
using namespace std; void _main(); int main() { cin.tie(0); ios::sync_with_stdio(false); _main(); }
//---------------------------------------------------------------------------------------------------
#ifdef _MSC_VER
#pragma push_macro("long")
#undef long
#ifdef _WIN32
inline unsigned int __builtin_ctz(unsigned int x) { unsigned long r; _BitScanForward(&r, x); return r; }
inline unsigned int __builtin_clz(unsigned int x) { unsigned long r; _BitScanReverse(&r, x); return 31 - r; }
inline unsigned int __builtin_ffs(unsigned int x) { unsigned long r; return _BitScanForward(&r, x) ? r + 1 : 0; }
inline unsigned int __builtin_popcount(unsigned int x) { return __popcnt(x); }
#ifdef _WIN64
inline unsigned long long __builtin_ctzll(unsigned long long x) { unsigned long r; _BitScanForward64(&r, x); return r; }
inline unsigned long long __builtin_clzll(unsigned long long x) { unsigned long r; _BitScanReverse64(&r, x); return 63 - r; }
inline unsigned long long __builtin_ffsll(unsigned long long x) { unsigned long r; return _BitScanForward64(&r, x) ? r + 1 : 0; }
inline unsigned long long __builtin_popcountll(unsigned long long x) { return __popcnt64(x); }
#else
inline unsigned int hidword(unsigned long long x) { return static_cast<unsigned int>(x >> 32); }
inline unsigned int lodword(unsigned long long x) { return static_cast<unsigned int>(x & 0xFFFFFFFF); }
inline unsigned long long __builtin_ctzll(unsigned long long x) { return lodword(x) ? __builtin_ctz(lodword(x)) : __builtin_ctz(hidword(x)) + 32; }
inline unsigned long long __builtin_clzll(unsigned long long x) { return hidword(x) ? __builtin_clz(hidword(x)) : __builtin_clz(lodword(x)) + 32; }
inline unsigned long long __builtin_ffsll(unsigned long long x) { return lodword(x) ? __builtin_ffs(lodword(x)) : hidword(x) ? __builtin_ffs(hidword(x)) + 32 : 0; }
inline unsigned long long __builtin_popcountll(unsigned long long x) { return __builtin_popcount(lodword(x)) + __builtin_popcount(hidword(x)); }
#endif // _WIN64
#endif // _WIN32
#pragma pop_macro("long")
#endif // _MSC_VER
namespace radix_heap {
    namespace internal {
        template<bool Is64bit> class find_bucket_impl;

        template<>
        class find_bucket_impl<false> {
        public:
            static inline constexpr size_t find_bucket(uint32_t x, uint32_t last) {
                return x == last ? 0 : 32 - __builtin_clz(x ^ last);
            }
        };

        template<>
        class find_bucket_impl<true> {
        public:
            static inline constexpr size_t find_bucket(uint64_t x, uint64_t last) {
                return x == last ? 0 : 64 - __builtin_clzll(x ^ last);
            }
        };

        template<typename T>
        inline constexpr size_t find_bucket(T x, T last) {
            return find_bucket_impl<sizeof(T) == 8>::find_bucket(x, last);
        }

        template<typename KeyType, bool IsSigned> class encoder_impl_integer;

        template<typename KeyType>
        class encoder_impl_integer<KeyType, false> {
        public:
            typedef KeyType key_type;
            typedef KeyType unsigned_key_type;

            inline static constexpr unsigned_key_type encode(key_type x) {
                return x;
            }

            inline static constexpr key_type decode(unsigned_key_type x) {
                return x;
            }
        };

        template<typename KeyType>
        class encoder_impl_integer<KeyType, true> {
        public:
            typedef KeyType key_type;
            typedef typename std::make_unsigned<KeyType>::type unsigned_key_type;

            inline static constexpr unsigned_key_type encode(key_type x) {
                return static_cast<unsigned_key_type>(x) ^
                    (unsigned_key_type(1) << unsigned_key_type(std::numeric_limits<unsigned_key_type>::digits - 1));
            }

            inline static constexpr key_type decode(unsigned_key_type x) {
                return static_cast<key_type>
                    (x ^ (unsigned_key_type(1) << (std::numeric_limits<unsigned_key_type>::digits - 1)));
            }
        };

        template<typename KeyType, typename UnsignedKeyType>
        class encoder_impl_decimal {
        public:
            typedef KeyType key_type;
            typedef UnsignedKeyType unsigned_key_type;

            inline static constexpr unsigned_key_type encode(key_type x) {
                return raw_cast<key_type, unsigned_key_type>(x) ^
                    ((-(raw_cast<key_type, unsigned_key_type>(x) >> (std::numeric_limits<unsigned_key_type>::digits - 1))) |
                    (unsigned_key_type(1) << (std::numeric_limits<unsigned_key_type>::digits - 1)));
            }

            inline static constexpr key_type decode(unsigned_key_type x) {
                return raw_cast<unsigned_key_type, key_type>
                    (x ^ (((x >> (std::numeric_limits<unsigned_key_type>::digits - 1)) - 1) |
                    (unsigned_key_type(1) << (std::numeric_limits<unsigned_key_type>::digits - 1))));
            }

        private:
            template<typename T, typename U>
            union raw_cast {
            public:
                constexpr raw_cast(T t) : t_(t) {}
                operator U() const { return u_; }

            private:
                T t_;
                U u_;
            };
        };

        template<typename KeyType>
        class encoder : public encoder_impl_integer<KeyType, std::is_signed<KeyType>::value> {};
        template<>
        class encoder<float> : public encoder_impl_decimal<float, uint32_t> {};
        template<>
        class encoder<double> : public encoder_impl_decimal<double, uint64_t> {};
    }  // namespace internal

    template<typename KeyType, typename EncoderType = internal::encoder<KeyType>>
    class radix_heap {
    public:
        typedef KeyType key_type;
        typedef EncoderType encoder_type;
        typedef typename encoder_type::unsigned_key_type unsigned_key_type;

        radix_heap() : size_(0), last_(), buckets_() {
            buckets_min_.fill(std::numeric_limits<unsigned_key_type>::max());
        }

        void push(key_type key) {
            const unsigned_key_type x = encoder_type::encode(key);
            assert(last_ <= x);
            ++size_;
            const size_t k = internal::find_bucket(x, last_);
            buckets_[k].emplace_back(x);
            buckets_min_[k] = std::min(buckets_min_[k], x);
        }

        key_type top() {
            pull();
            return encoder_type::decode(last_);
        }

        void pop() {
            pull();
            buckets_[0].pop_back();
            --size_;
        }

        size_t size() const {
            return size_;
        }

        bool empty() const {
            return size_ == 0;
        }

        void clear() {
            size_ = 0;
            last_ = key_type();
            for (auto &b : buckets_) b.clear();
            buckets_min_.fill(std::numeric_limits<unsigned_key_type>::max());
        }

        void swap(radix_heap<KeyType, EncoderType> &a) {
            std::swap(size_, a.size_);
            std::swap(last_, a.last_);
            buckets_.swap(a.buckets_);
            buckets_min_.swap(a.buckets_min_);
        }

    private:
        size_t size_;
        unsigned_key_type last_;
        std::array<std::vector<unsigned_key_type>,
            std::numeric_limits<unsigned_key_type>::digits + 1> buckets_;
        std::array<unsigned_key_type,
            std::numeric_limits<unsigned_key_type>::digits + 1> buckets_min_;

        void pull() {
            assert(size_ > 0);
            if (!buckets_[0].empty()) return;

            size_t i;
            for (i = 1; buckets_[i].empty(); ++i);
            last_ = buckets_min_[i];

            for (unsigned_key_type x : buckets_[i]) {
                const size_t k = internal::find_bucket(x, last_);
                buckets_[k].emplace_back(x);
                buckets_min_[k] = std::min(buckets_min_[k], x);
            }
            buckets_[i].clear();
            buckets_min_[i] = std::numeric_limits<unsigned_key_type>::max();
        }
    };

    template<typename KeyType, typename ValueType, typename EncoderType = internal::encoder<KeyType>>
    class pair_radix_heap {
    public:
        typedef KeyType key_type;
        typedef ValueType value_type;
        typedef EncoderType encoder_type;
        typedef typename encoder_type::unsigned_key_type unsigned_key_type;

        pair_radix_heap() : size_(0), last_(), buckets_() {
            buckets_min_.fill(std::numeric_limits<unsigned_key_type>::max());
        }

        void push(key_type key, const value_type &value) {
            const unsigned_key_type x = encoder_type::encode(key);
            assert(last_ <= x);
            ++size_;
            const size_t k = internal::find_bucket(x, last_);
            buckets_[k].emplace_back(x, value);
            buckets_min_[k] = std::min(buckets_min_[k], x);
        }

        void push(key_type key, value_type &&value) {
            const unsigned_key_type x = encoder_type::encode(key);
            assert(last_ <= x);
            ++size_;
            const size_t k = internal::find_bucket(x, last_);
            buckets_[k].emplace_back(x, std::move(value));
            buckets_min_[k] = std::min(buckets_min_[k], x);
        }

        template <class... Args>
        void emplace(key_type key, Args&&... args) {
            const unsigned_key_type x = encoder_type::encode(key);
            assert(last_ <= x);
            ++size_;
            const size_t k = internal::find_bucket(x, last_);
            buckets_[k].emplace_back(std::piecewise_construct,
                std::forward_as_tuple(x), std::forward_as_tuple(args...));
            buckets_min_[k] = std::min(buckets_min_[k], x);
        }

        key_type top_key() {
            pull();
            return encoder_type::decode(last_);
        }

        value_type &top_value() {
            pull();
            return buckets_[0].back().second;
        }

        void pop() {
            pull();
            buckets_[0].pop_back();
            --size_;
        }

        size_t size() const {
            return size_;
        }

        bool empty() const {
            return size_ == 0;
        }

        void clear() {
            size_ = 0;
            last_ = key_type();
            for (auto &b : buckets_) b.clear();
            buckets_min_.fill(std::numeric_limits<unsigned_key_type>::max());
        }

        void swap(pair_radix_heap<KeyType, ValueType, EncoderType> &a) {
            std::swap(size_, a.size_);
            std::swap(last_, a.last_);
            buckets_.swap(a.buckets_);
            buckets_min_.swap(a.buckets_min_);
        }

    private:
        size_t size_;
        unsigned_key_type last_;
        std::array<std::vector<std::pair<unsigned_key_type, value_type>>,
            std::numeric_limits<unsigned_key_type>::digits + 1> buckets_;
        std::array<unsigned_key_type,
            std::numeric_limits<unsigned_key_type>::digits + 1> buckets_min_;

        void pull() {
            assert(size_ > 0);
            if (!buckets_[0].empty()) return;

            size_t i;
            for (i = 1; buckets_[i].empty(); ++i);
            last_ = buckets_min_[i];

            for (size_t j = 0; j < buckets_[i].size(); ++j) {
                const unsigned_key_type x = buckets_[i][j].first;
                const size_t k = internal::find_bucket(x, last_);
                buckets_[k].emplace_back(std::move(buckets_[i][j]));
                buckets_min_[k] = std::min(buckets_min_[k], x);
            }
            buckets_[i].clear();
            buckets_min_[i] = std::numeric_limits<unsigned_key_type>::max();
        }
    };
}  // namespace radix_heap
/*---------------------------------------------------------------------------------------------------
????????????????????????????????? ??§?????§  
??????????????? ??§?????§ ???????´<_??? ?????? Welcome to My Coding Space!
???????????? ??? ?´_???`??????/??? ???i     
?????????????????????????????? ???  |???|     
????????? /?????? /??£??£??£??£/??????|  
??? ???_(__??????/???    ???/ .| .|????????????  
??? ????????????/????????????/??????u??????  
---------------------------------------------------------------------------------------------------*/



const int MAXN = 200020;
int NODOS = 0;
typedef int Costo;
const Costo INF = 1 << 30;

typedef pair<Costo, int> CostoNodo;
vector<CostoNodo> grafoCosto[MAXN];
const bool bi = false;
// Grafos con ponderacion.
// Nodos indexados de 0 a n - 1.
// bi = true -> Bidireccional.
// bi = false -> Dirigido.

struct Ponderada {
    int x, y;
    Costo c;
    Ponderada() {}
    Ponderada(int x_, int y_, int c_) : x(x_), y(y_), c(c_) {}
    bool operator<(const Ponderada& q) const {
        return c < q.c ? true : false;
    }
};

void AgregarArista(int u, int v, Costo c) {
    if (bi) grafoCosto[v].push_back(CostoNodo(c, u));
    grafoCosto[u].push_back(CostoNodo(c, v));
}

void limpia() {
    for (int i = 0; i < NODOS; i++)
        grafoCosto[i].clear();
}

// Algoritmo de dijkstra desde el nodo s.
// Devuelve el vector de distancias a todos
// los nodos desde s. Un valor INF indica que
// no es posible ir de s al respectivo nodo.
using rh = radix_heap::pair_radix_heap<Costo, int>;
Costo dist[MAXN];
void Dijkstra(int s) {
    for (int i = 0; i < NODOS; i++) dist[i] = INF;
    rh pq;
    pq.push(0, s), dist[s] = 0;
    while (!pq.empty()) {
        Costo p = pq.top_key();
        int u = pq.top_value(); pq.pop();
        if (dist[u] < p) continue;
        for (CostoNodo arista : grafoCosto[u]) {
            int v = arista.second;
            p = dist[u] + arista.first;
            if (p < dist[v]) dist[v] = p,
                pq.push(p, v);
        }
    }
}

void _main() {
    int casos, N, M, S, T, x, y, c;

    cin >> N >> M >> S;
    NODOS = N;

    limpia();
    for (int i = 0; i < M; i++) {
        cin >> x >> y >> c;
        AgregarArista(x, y, c);
    }
    Dijkstra(S);

    for (int i = 0; i < NODOS; i++) {
        if (dist[i] == INF) {
            cout << "INF\n";
        }
        else
            cout << dist[i] << '\n';
    }
}
