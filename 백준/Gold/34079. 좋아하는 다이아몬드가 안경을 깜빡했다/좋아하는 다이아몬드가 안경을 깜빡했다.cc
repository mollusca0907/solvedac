#include <iostream>
#include <vector>
#include <queue>
using namespace std;

const int MAX = 200005;
int n, m;
vector<int> graph[MAX];
int dist1[MAX], dist2[MAX];
bool good[MAX];
vector<int> depth[MAX];

void bfs(int start, int* dist) {
    fill(dist, dist + n + 1, -1);
    queue<int> q;
    dist[start] = 0;
    q.push(start);
    while (!q.empty()) {
        int cur = q.front(); q.pop();
        for (int next : graph[cur]) {
            if (dist[next] == -1) {
                dist[next] = dist[cur] + 1;
                q.push(next);
            }
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n >> m;
    while (m--) {
        int u, v;
        cin >> u >> v;
        graph[u].push_back(v);
        graph[v].push_back(u);
    }

    bfs(1, dist1);
    bfs(n, dist2);
    int total = dist1[n];

    for (int i = 2; i < n; ++i) {
        if (dist1[i] + dist2[i] == total) {
            good[i] = true;
            depth[dist1[i]].push_back(i);
        }
    }

    for (int d = 1; d < total; ++d) {
        if (depth[d].size() == 1) {
            cout << depth[d][0];
            return 0;
        }
    }

    cout << 1;
    return 0;
}
