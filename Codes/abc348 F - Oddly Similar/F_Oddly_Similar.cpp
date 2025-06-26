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

void solve()
{
    int n, m;
    cin >> n >> m;
    vector<vector<int>> a(n, vector<int>(m));
    for(int i = 0; i < n; ++i)
    {
        for(int j = 0; j < m; ++j)
            cin >> a[i][j];
    }

    vector<bitset<2000>> bt(n);

    for(int pos = 0; pos < m; ++pos)
    {
        vector<bitset<2000>> bs(1000);
        
        for(int seq = 0; seq < n; ++seq)
        {
            int val = a[seq][pos];
            bs[val].set(seq);
        }
        for(int seq = 0; seq < n; ++seq)
        {
            int val = a[seq][pos];
            bt[seq] ^= bs[val];
        }
    }

    ll ans = 0;
    for(int i = 0; i < n; ++i)
        ans += bt[i].count();
    
    if(m % 2)   ans -= n;
    cout << ans / 2 << endl;
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