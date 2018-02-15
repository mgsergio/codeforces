#include <functional>
#include <iostream>
#include <iterator>
#include <list>
#include <set>
#include <string>
#include <tuple>

using namespace std;

using Item = tuple<size_t /* count */, int /* id */, int /* value */>;
using ItemList = list<Item>;

struct ItemIterCmp
{
  bool operator()(ItemList::const_iterator a, ItemList::const_iterator b)
  {
    return *a > *b;
  }
};

using ItemQueue = set<ItemList::const_iterator, ItemIterCmp>;

ItemList ReadItems()
{
  // Skip number of records.
  {
    string s;
    getline(cin, s);
  }

  ItemList lst;

  auto it = istream_iterator<int>(cin);

  int lastVal = *it++;
  size_t count = 1;
  int id = 0;

  for (; it != istream_iterator<int>(); ++it)
  {
    auto const val = *it;
    if (val == lastVal)
    {
      ++count;
    }
    else
    {
      lst.emplace_back(count, id--, lastVal);
      lastVal = val;
      count = 1;
    }
  }
  lst.emplace_back(count, id--, lastVal);

  return lst;
}

int CountMoves(ItemList & lst)
{
  ItemQueue q;
  for (auto it = begin(lst); it != end(lst); ++it)
    q.insert(it);

  int count = 0;

  while (!q.empty())
  {
    auto const longestIt = begin(q);
    auto const itemIt = *longestIt;
    q.erase(longestIt);

    if (itemIt != begin(lst) && next(itemIt) != end(lst))
    {
      auto const pIt = prev(itemIt);
      auto const nIt = next(itemIt);

      if (get<2>(*pIt) == get<2>(*nIt))
      {
        auto const newIt = lst.emplace(pIt, get<0>(*pIt) + get<0>(*nIt), get<1>(*pIt), get<2>(*pIt));
        q.erase(pIt);
        q.erase(nIt);
        q.insert(newIt);

        lst.erase(pIt);
        lst.erase(nIt);
      }
    }

    lst.erase(itemIt);

    ++count;
  }

  return count;
}

int main()
{
  auto lst = ReadItems();
  cout << CountMoves(lst) << endl;
  return 0;
};
