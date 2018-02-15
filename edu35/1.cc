#include <iostream>
#include <vector>
#include <iterator>
#include <limits>
#include <cstdint>
#include <algorithm>

using namespace std;

int main()
{
  int n;
  cin >> n;

  vector<int64_t> v{istream_iterator<int64_t>(cin), istream_iterator<int64_t>()};

  int64_t min = numeric_limits<int64_t>::max();
  for (auto m : v)
  {
    if (m < min)
      min = m;
  }

  vector<int64_t> minsInds;
  for (int64_t i = 0; i < v.size(); ++i)
  {
    if (v[i] == min)
      minsInds.push_back(i);
  }

  min = numeric_limits<int64_t>::max();
  for (size_t i = 1; i < minsInds.size(); ++i)
  {
    auto const d = minsInds[i] - minsInds[i - 1];
    if (d < min)
      min = d;
  }

  cout << min << endl;
}
