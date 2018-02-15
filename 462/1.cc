#include <algorithm>
#include <iostream>
#include <vector>
#include <limits>
#include <iterator>
#include <cstdint>

using namespace std;

int main()
{
  int m, n;
  cin >> n >> m;

  vector<int64_t> ts(n);
  vector<int64_t> bs(m);

  for (int i = 0; i < n; ++i)
    cin >> ts[i];

  for (int i = 0; i < m; ++i)
    cin >> bs[i];

  auto min = numeric_limits<int64_t>::max();
  for (int i = 0; i < n; ++i)
  {
    auto max = numeric_limits<int64_t>::min();
    for (int j = 0; j < n; ++j)
    {
      if (j == i)
        continue;
      for (int k = 0; k < m; ++k)
      {
        if (max < bs[k] * ts[j])
          max = bs[k] * ts[j];
      }
    }
    if (min > max)
      min = max;
  }

  cout << min << endl;
}
