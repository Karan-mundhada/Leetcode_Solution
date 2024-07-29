class StockSpanner {
public:
    vector<int> arr;
    int top;
    StockSpanner() {
        top = -1;
    }
    
    int next(int price) {
        int i = top, cnt = 1;
        while(i >= 0 && arr[i] <= price)
        {
            cnt++;
            i--;
        }

        arr.push_back(price);
        top++;
        return cnt;
    }
};

/**
 * Your StockSpanner object will be instantiated and called as such:
 * StockSpanner* obj = new StockSpanner();
 * int param_1 = obj->next(price);
 */