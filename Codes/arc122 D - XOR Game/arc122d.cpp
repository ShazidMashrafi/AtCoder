#include <bits/stdc++.h>
using namespace std;
#ifdef ONLINE_JUDGE
#define dbg(...)
#else
#include <debug.h>
#endif
#define  ll  long long
#define  endl  '\n'
#define  ff  first
#define  ss  second
#define  pb  push_back
#define  sz(x)  (int)(x).size()
#define  all(x)  x.begin(), x.end()
#define  Dpos(n) fixed << setprecision(n)
#define  yn(f)  f? cout<<"YES\n":cout<<"NO\n"
#define  FAST  (ios_base::sync_with_stdio(false), cin.tie(nullptr));
ll power(ll x,ll y,ll m=LLONG_MAX) {ll ans=1;x%=m;while(y){if(y&1)ans=(ans*x)%m;x=(x*x)%m;y>>=1;}return ans;}

class Trie {
public:
    struct TrieNode {
        TrieNode* children[2];

        TrieNode() {
            for (int i = 0; i < 2; i++)
                children[i] = nullptr;
        }
    };
    
    TrieNode* root;
    const int MAXBIT = 29;
    
    Trie() {
        root = new TrieNode();
    }
    
    void insert(ll n) {
        TrieNode* node = root;
        for(int i = MAXBIT; i >= 0; --i) {
            bool bit = (n >> i) & 1;
            if(!node->children[bit])
                node->children[bit] = new TrieNode();
            node = node->children[bit];
        }
    }

    ll find(ll n) {
        TrieNode* node = root;
        ll res = 0;

        for(int i = MAXBIT; i >= 0; --i) {
            bool bit = (n >> i) & 1;
            if(node->children[bit]) {
                if(bit) res |= (1ll << i);
                node = node->children[bit];
            } else {
                if(!bit) res |= (1ll << i);
                node = node ->children[!bit];
            }
        }
        return res;
    }
};

ll fun(vector<ll>&a, ll bit) 
{
    if(bit < 0 || a.empty())    return 0;

    vector<ll>zero, one;
    for(ll x : a) {
        if((x >> bit) & 1) {
            one.push_back(x);
        } else {
            zero.push_back(x);
        }
    }

    if(sz(zero) % 2 == 0 && sz(one) % 2 == 0) {
        ll ans1 = fun(zero, bit - 1);
        ll ans2 = fun(one, bit - 1);
        return max(ans1, ans2);
    }

    Trie trie;
    for(ll x : one) {
        trie.insert(x);
    }

    ll mn = LLONG_MAX;
    for(ll x : zero) {
        ll y = trie.find(x);
        mn = min(mn,  x ^ y);
    }

    return mn;
}

void solve()
{
    ll n;
    cin >> n;
    vector<ll>a(2 * n);
    for(ll i = 0; i < 2 * n; ++i) {
        cin >> a[i];
    }

    cout << fun(a, 29) << endl;
}

signed main()
{
    FAST;
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);

    int TCS = 1;
    // cin >> TCS;
    for (int TC = 1; TC <= TCS; ++TC)
    {
        // cout<<"Case "<<TC<<": ";
        solve();
    }
}