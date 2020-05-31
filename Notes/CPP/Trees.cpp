struct LCA
{
    const ll N;
    vi euler, first, height;
    vvi &adj;
    SegTree &tree;

    LCA(vvi &adj)
    {
        N = adj.size();
        first.resize(N);
        height.resize(N);
        dfs(0, 0, 0);
        tree = SegTree(euler, euler.size());
    }

    ll query(ll u, ll v)
    {
        ll l = first[u];
        ll r = first[v];
        if (l > r)
            swap(l, r);
        return tree.query(l, r) + 1;
    }

    ll func(ll a, ll b)
    {
        ll h1 = height[a];
        ll h2 = height[b];
        return (h1 < h2) ? a : b;
    }

    void dfs(ll node, ll prev, ll depth)
    {
        height[node] = depth;
        euler.push_back(node);
        first[node] = euler.size();
        for (auto x : adj[node])
        {
            if (x != prev)
            {
                dfs(x, node, depth + 1);
                euler.push_back(node);
            }
        }
    }
}