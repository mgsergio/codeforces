#include <iostream>
#include <vector>
#include <cstdint>

using namespace std;

vector<vector<bool>> ReadClassroom(int n, int m)
{
  vector<vector<bool>> cr;
  cr.resize(n);
  for (int i = 0; i < n; ++i)
  {
    for (int j = 0; j < m; ++j)
    {
      char c;
      cin >> c;
      cr[i].push_back(c == '.');
    }
  }
  return cr;
}

int CountWays(vector<vector<bool>> const & cr, int k)
{
  if (cr.size() == 1 && cr[0].size() == 1)
    return cr[0][0] ? 1 : 0;

  int count = 0;
  for (size_t i = 0; i < cr.size(); ++i)
  {
    int emptyCount = 0;
    for (size_t j = 0; j < cr[0].size(); ++j)
    {
      if (cr[i][j])
      {
        ++emptyCount;
        if (emptyCount >= k)
          ++count;
      }
      else
      {
        emptyCount = 0;
      }
    }
  }

  for (size_t j = 0; j < cr[0].size(); ++j)
  {
    int emptyCount = 0;
    for (size_t i = 0; i < cr.size(); ++i)
    {
      if (cr[i][j])
      {
        ++emptyCount;
        if (emptyCount >= k)
          ++count;
      }
      else
      {
        emptyCount = 0;
      }
    }
  }
  return count;
}

int main()
{
  int n, m, k;
  cin >> n >> m >> k;

  auto const cr = ReadClassroom(n, m);
  cout << CountWays(cr, k) << endl;

  return 0;
}
