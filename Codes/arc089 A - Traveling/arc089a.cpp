#include <bits/stdc++.h>
using namespace std;
#if defined(LOCAL) && !defined(ONLINE_JUDGE)
#include "debug.h"
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
    int n;
    cin >> n;
    int px = 0, py = 0, pt = 0;
    bool f = 1;
    while(n--) {
        int t, x, y;
        cin >> t >> x >> y;
        int ds = abs(px - x) + abs(py - y);
        int dt = t - pt;
        // dbg(ds, dt);
        if(ds > dt || ds % 2 != dt % 2) {
            // dbg("GI");
            f = 0;
        }
        px = x;
        py = y;
        pt = t;
    }
    if(f == 1) {
        cout << "Yes" << endl;
    } else {
        cout << "No" << endl;
    }
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