#include <functional>
#include <iostream>
#include <map>
#include <stack>

using namespace std;


map<int, int> InitialSeq(uint64_t n)
{
  map<int, int> m;
  for (int i = 0; i < 64; ++i)
  {
    if (n & (static_cast<uint64_t>(1) << i))
      m.emplace(i, 1);
  }
  return m;
}

uint64_t Expand(map<int, int> & m, uint64_t k)
{
  uint64_t space = k - m.size();
  while (true)
  {
    auto maxIt = prev(end(m));
    if (maxIt->second > space)
      break;

    space -= maxIt->second;
    m[maxIt->first - 1] += 2 * maxIt->second;
    m.erase(maxIt);
  }
  return space;
}

void Fixup(map<int, int> & m, uint64_t space)
{
  while (space--)
  {
    auto it = begin(m);
    --it->second;
    m.emplace(it->first - 1, 2);
  }
}

int main()
{
  uint64_t n, k;
  cin >> n >> k;
  auto m = InitialSeq(n);

  if (m.size() > k)
  {
    cout << "No" << endl;
    return 0;
  }

  auto const space = Expand(m, k);
  Fixup(m, space);

  cout << "Yes" << endl;
  for (auto it = rbegin(m); it != rend(m); ++it)
  {
    for (int i = 0; i < it->second; ++i)
      cout << it->first << ' ';
  }
  cout << endl;

  return 0;
}
