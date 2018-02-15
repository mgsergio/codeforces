#include <iostream>
#include <map>
#include <set>
#include <stack>
#include <utility>
#include <vector>

using namespace std;

using Graph = vector<vector<int>>;

Graph ReadGraph(int n, int m)
{
  Graph g(n);
  while (m--)
  {
    int u, v;
    cin >> u >> v;
    g[u - 1].push_back(v - 1);
  }
  return g;
};

vector<pair<int, int>> GetAnyCycle(Graph const & g, pair<int, int> const * const skip = nullptr)
{
  set<int> GV;
  for (int s = 0; s < g.size(); ++s)
  {
    if (GV.count(s))
      continue;

    set<int> V;
    vector<pair<int, int>> c;
    stack<pair<int, int>> st;
    st.push({s, s});

    while (!st.empty())
    {
      auto const uv = st.top();
      st.pop();

      auto const u = uv.first;
      auto const v = uv.second;

      c.emplace_back(v, u);

      if (V.count(u))
        return c;

      V.insert(u);

      for (auto const v : g[u])
      {
        if (skip && u == skip->first && v == skip->second)
          continue;
        st.push({v, u});
      }

      GV.insert(begin(V), end(V));
    }
  }

  return {};
}

bool AlmostAcyclic(Graph & g)
{
  auto const cycle = GetAnyCycle(g);

  cout << "Cycle:" << endl;
  for (auto const & e : cycle)
    cout << e.first + 1 << " -> " << e.second + 1 << endl;
  cout << "----------" << endl;
  for (auto const & e : cycle)
  {
    auto const c = GetAnyCycle(g, &e);
    cout << "Cycle:" << endl;
    for (auto const & e : c)
      cout << e.first + 1 << " -> " << e.second + 1 << endl;
    cout << "----------" << endl;
    if (c.empty())
      return true;
  }
  return cycle.empty();
}

int main()
{
  int n, m;
  cin >> n >> m;
  auto g = ReadGraph(n, m);
  if (AlmostAcyclic(g))
    cout << "YES" << endl;
  else
    cout << "NO" << endl;
  return 0;
}

/**
   #include<bits/stdc++.h>
   using namespace std;
   int n,m,u1,u2,k;
   vector<int> v[501];
   int d[501];
   void dfs(int u)
   {
     d[u]=2;
     for(int i=0;i<v[u].size();++i)
     {
       if(d[v[u][i]]==2)
         k++;
       else if(!d[v[u][i]])
         dfs(v[u][i]);
     }
     d[u]=1;
   }

   int main()
   {
     cin>>n>>m;
     for(int i=1;i<=m;++i)
     {
       cin>>u1>>u2;
       v[u1].push_back(u2);
     }

     for(int i=1;i<=n;++i)
     {
       memset(d,0,sizeof d);
       k=0;
       dfs(i);
       for(int j=0;j<=n&&k<=1;++j)
         if(!d[j])
           dfs(j);
         if(k<=1)
         {
           cout<<"YES";
           return 0;
         }
      }
      cout<<"NO";
  }
*/
