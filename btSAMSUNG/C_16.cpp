#include <bits/stdc++.h>
#define fi first
#define se second
using namespace std;
typedef pair<int,int> ii;
typedef pair<int,ii> iii;
const int maxn = 15005;
int n, m, p[maxn], res = 0;
vector<ii> vec[maxn];
iii e[maxn];

int get(int u)
{
    if(p[u] == 0)
    {
        return u;
    }
    p[u] = get(p[u]);
    return p[u];
}
void unio(int u,int v)
{
    int x = get(u);
    int y = get(v);
    if(x != y)
    {
        p[x] = y;
    }
}
int main()
{
    cin >> n >> m;
    for(int i = 1;i <=m;i++) {
        int u,v,w;
        cin >> u >> v >> w;
        vec[u].push_back(ii(v,w));
        e[i] = iii(w,ii(u,v));

    }
    sort(e + 1, e + 1 + m);
    int c = 0;
    for(int i = 1;i<=m;i++)
    {
        if(c < n-1)
        {
            if(get(e[i].second.second) != get(e[i].second.first))
            {
                unio(e[i].second.second,e[i].second.first);
                res += e[i].first;
                c++;

            }
        }
        else
            {
                break;
            }
    }
    cout << res << "\n";

}
