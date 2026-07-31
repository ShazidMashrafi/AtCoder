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
    ll n;
    cin >> n;
    vector<ll> a(n + 1), in(n + 1, 0);
    for(ll i = 1; i <= n; ++i) {
        cin >> a[i];
        in[a[i]]++;
    }

    queue<ll> q;
    for(ll i = 1; i <= n; ++i) {
        if(in[i] == 0)  q.push(i);
    }
    while(!q.empty()) {
        ll u = q.front();
        q.pop();
        in[a[u]]--;
        if(in[a[u]] == 0)   q.push(a[u]);
    }

    vector<ll> dp(n + 1, -1);
    vector<bool> vis(n + 1, false);
    for(ll i = 1; i <= n; ++i) {
        if(in[i] && !vis[i]) {
            vector<ll> nodes;
            ll curr = i;
            while(!vis[curr]) {
                vis[curr] = true;
                nodes.pb(curr);
                curr = a[curr];
            }
            for(ll u : nodes){
                dp[u] = sz(nodes);
            }
        }
    }

    function<ll(ll)> dfs = [&](ll u) {
        if(dp[u] != -1) return dp[u];
        return dp[u] = 1 + dfs(a[u]);
    };

    ll ans = 0;
    for(ll i = 1;  i <= n; ++i) {
        ans += dfs(i);
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