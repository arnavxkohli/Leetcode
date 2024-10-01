#include <vector>

using namespace std;

class StockSpanner {
private:
  vector<pair<int, int>> stocks;

public:
  StockSpanner() {}

  int next(int price) {
    int res = 1;
    while(stocks.size() && stocks.back().first <= price) {
      res += stocks.back().second; stocks.pop_back();
    }
    stocks.push_back({price, res});
    return res;
  }
};
