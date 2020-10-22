const ll maxn = 2e5;
ll n, m;
vll G[maxn+3],  Gr[maxn+3];
vi order, component;

vb vis(maxn+3,0);

void dfs1(int v){
    vis[v]=1;
    for(int u:G[v])
        if(!vis[u])
            dfs1(u);
    order.pb(v);
}

void dfs2(int v){
    vis[v]=1;
    component.pb(v);
    for(int u:Gr[v])
        if(!vis[u])
            dfs2(u);
}

void solve()
{
    cin>>n>>m;
    fo(i,1,m){ ll u, v; cin>>u>>v; G[u].pb(v); Gr[v].pb(u); }
    
    fo(i,1,n)
        if(!vis[i]) dfs1(i);

    // order is currently in ascending order of exit time
    reverse(all(order));

    // fill_n(vis.begin()+1, n, 0);
    fill(all(vis),0);
    
    for(int s:order){
        if(!vis[s]){
            dfs2(s);
            //process component eg: show(component,component.size());
            show(component,component.size());
            component.clear();
        }
    }
}
