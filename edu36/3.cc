#include <algorithm>
#include <cassert>
#include <iostream>
#include <limits>
#include <set>

using namespace std;


template <typename C>
typename C::iterator non_strict_lower_bound(C const & c, typename C::key_type const & k)
{
  if (c.empty())
    return end(c);

  auto const it = c.lower_bound(k);
  if (it != end(c) && *it == k)
    return it;

  if (it == end(c))
    return prev(end(c));

  if (it == begin(c))
    return end(c);

  return prev(it);
}

template <typename C>
typename C::iterator strict_lower_bound(C const & c, typename C::key_type const & k)
{
  if (c.empty())
    return end(c);

  auto const it = c.lower_bound(k);
  if (it == end(c))
    return prev(end(c));

  if (it == begin(c))
    return end(c);

  return prev(it);
}

int main()
{
  string a;
  string b;

  cin >> a >> b;

  sort(begin(a), end(a), [](auto a, auto b) { return a > b; });

  if (a.size() < b.size())
  {
    cout << a << endl;
    return 0;
  }

  multiset<char> ds{begin(a), end(a)};

  auto aIt = begin(a);
  auto bIt = begin(b);
  while (aIt != end(a))
  {
    auto chIt = non_strict_lower_bound(ds, *bIt);
    if (chIt == end(ds))
      break;

    *aIt = *chIt;
    ds.erase(chIt);

    if (*aIt < *bIt)
    {
      copy(rbegin(ds), rend(ds), ++aIt);
      cout << a << endl;
      return 0;
    }

    ++aIt;
    ++bIt;
  }

  // Fix gready solution.
  if (aIt != end(a))
  {
    auto raIt = make_reverse_iterator(aIt);
    while (raIt != rend(a))
    {
      --bIt;
      ds.insert(*raIt);
      auto chIt = strict_lower_bound(ds, *bIt);
      if (chIt != end(ds))
      {
        assert(*chIt < *bIt);

        *raIt = *chIt;
        ds.erase(chIt);
        aIt = raIt.base();

        copy(begin(ds), end(ds), aIt);
        sort(aIt, end(a), [](auto a, auto b) { return a > b; });
        break;
      }

      ++raIt;
    }
  }

  cout << a << endl;

  return 0;
}
