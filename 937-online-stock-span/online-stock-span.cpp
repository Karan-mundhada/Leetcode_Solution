class StockSpanner {
public:
    stack<pair<int, int>> arr;
    StockSpanner() {
        ios_base::sync_with_stdio(false);
        cin.tie(nullptr);
        cout.tie(nullptr);
    }
    
    int next(int price) {
        int cnt = 1;
        while(!arr.empty() && arr.top().first <= price)
        {
            cnt += arr.top().second;
            arr.pop();
        }

        arr.push({price, cnt});
        return cnt;
    }
};

/**
 * Your StockSpanner object will be instantiated and called as such:
 * StockSpanner* obj = new StockSpanner();
 * int param_1 = obj->next(price);
 */