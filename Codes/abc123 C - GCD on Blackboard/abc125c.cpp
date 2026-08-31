#include <bits/stdc++.h>
using namespace std;
#if defined(LOCAL) && !defined(ONLINE_JUDGE)
#include <debug.h>
#else
#define dbg(...)
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
    ll n;
    cin >> n;
    vector<ll>a(n), pre(n), suff(n);
    for(auto &i : a) cin >> i;

    pre[0] = a[0];
    for(ll i = 1; i < n; ++i) {
        pre[i] = gcd(pre[i - 1], a[i]);
    }
    suff[n - 1] = a[n - 1];
    for(ll i = n - 2; i >= 0; --i) {
        suff[i] = gcd(suff[i + 1], a[i]);
    }
    dbg(a);
    dbg(pre);
    dbg(suff); 

    ll ans = 0;
    for (ll i = 0; i < n; ++i)
    {
        ll g;
        if (i == 0)     g = suff[1];
        else if (i == n - 1)    g = pre[n - 2];
        else    g = gcd(pre[i - 1], suff[i + 1]);

        ans = max(ans, g);
    }
    cout << ans << endl;
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