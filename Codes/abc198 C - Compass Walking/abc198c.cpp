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

const int N = 1e4 + 10;
vector<int> g[N];
int dist[N], parent[N];

void bfs(int src, int n) {
    fill(dist, dist + n + 1, -1);
    queue<int> q;
    dist[src] = 0;
    parent[src] = -1;
    q.push(src);

    while (!q.empty()) {
        int u = q.front();
        q.pop();
        for (int v : g[u]) {
            if (dist[v] == -1) {
                dist[v] = dist[u] + 1;
                parent[v] = u;
                q.push(v);
            }
        }
    }
}

void solve()
{
    int n, m;
    cin >> n >> m;
    for (int i = 1; i <= n; ++i) g[i].clear();
    for(int i = 0; i < m; ++i) {
        int v, u;
        cin >> v >> u;
        g[v].pb(u);
        g[u].pb(v);
    }

    int s;
    cin >> s;
    bfs(s, n);
    for(int i = 1; i <= n; ++i) {
        if(i == s) continue;
        if(dist[i] == -1) {
            cout << dist[i] << " ";
        } else {
            cout << dist[i] * 6 << " ";
        }
    }
    cout << endl;
}

signed main()
{
    FAST;
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);

    int TCS = 1;
    cin >> TCS;
    for (int TC = 1; TC <= TCS; ++TC)
    {
        // cout<<"Case "<<TC<<": ";
        solve();
    }
}