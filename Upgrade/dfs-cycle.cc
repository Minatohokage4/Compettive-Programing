#include <bits/stdc++.h>

using namespace std;

#define debug(x) cout << #x " = " << (x) << endl

const long long inf = 1000000000;
struct edge
{
    int to;
    long long w;
    edge(int a, long long b) : to(a), w(b) {}
    bool operator<(const edge &o) const
    {
        return w > o.w;
    }
};

typedef vector<vector<edge>> graph;
graph adj;
vector<bool> visited;
bool dfs(int v, int p)
{
    if (!visited[v])
    {
        visited[v] = true;
        for (auto u : adj[v])
        {
            if (u.to == p)
                continue;
            if (dfs(u.to, v))
                return true;
        }
    }
    return false;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    freopen("input.txt", "r", stdin);
    int n, m;
    cin >> n >> m;
    adj.resize(n);
    visited.assign(n, false);
    for (int i = 0; i < m; i++)
    {
        int u, v, w;
        cin >> u >> v >> w;
        adj[u].push_back({v, w});
    }
    bool found_cycle = false;
    for (int u = 1; u <= n; ++u)
    {
        if (!visited[u])
        {
            if (dfs(u))
            {
                found_cycle = true;
                break;
            }
        }
    }
    return 0;
}

void printGraph(int n)
{
    for (size_t v = 0; v < n; v++)
    {
        for (auto &u : adj[v])
        {
            printf("start=%d dest=%d, w=%d\n", v, u.to, u.w);
        }
    }
}