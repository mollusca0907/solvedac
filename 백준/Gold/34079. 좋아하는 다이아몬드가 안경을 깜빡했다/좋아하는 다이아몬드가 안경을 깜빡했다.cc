#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;
using ll = long long;

const ll MOD1 = 1'000'000'007;
const ll MOD2 = 1'000'000'009;

ll n, m;
vector<ll> graph[200'007];
vector<ll> cnt[2][2];
vector<ll> dist[2];

void bfs(ll start) {
    ll idx = (start == n) ? 1 : 0;

    dist[idx].assign(n + 1, -1);
    cnt[idx][0].assign(n + 1, 0);
    cnt[idx][1].assign(n + 1, 0);

    queue<ll> q;
    dist[idx][start] = 0;
    cnt[idx][0][start] = 1;
    cnt[idx][1][start] = 1;
    q.push(start);

    while (!q.empty()) {
        ll cur = q.front(); q.pop();
        for (ll next : graph[cur]) {
            if (dist[idx][next] == -1) {
                dist[idx][next] = dist[idx][cur] + 1;
                cnt[idx][0][next] = cnt[idx][0][cur];
                cnt[idx][1][next] = cnt[idx][1][cur];
                q.push(next);
            }
            else if (dist[idx][next] == dist[idx][cur] + 1) {
                cnt[idx][0][next] = (cnt[idx][0][next] + cnt[idx][0][cur]) % MOD1;
                cnt[idx][1][next] = (cnt[idx][1][next] + cnt[idx][1][cur]) % MOD2;
            }
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n >> m;

    for (ll i = 0; i < m; i++) {
        ll u, v;
        cin >> u >> v;
        graph[u].push_back(v);
        graph[v].push_back(u);
    }

    bfs(1);
    bfs(n);

    ll ans = 1;
    for (ll i = 2; i < n; i++) {
        if (dist[0][i] + dist[1][i] == dist[0][n]) {
            bool check1 = (cnt[0][0][i] * cnt[1][0][i]) % MOD1 == cnt[0][0][n];
            bool check2 = (cnt[0][1][i] * cnt[1][1][i]) % MOD2 == cnt[0][1][n];

            if (check1 && check2) {
                ans = i;
                break;
            }
        }
    }

    cout << ans;

    return 0;
}