const int mod = 1e9+7;

class Fancy {
    vector <int> sequence;
    long long increment, multiplier;
    
private:
    int binaryExponentation(long long x, long long y)
    {
        long long ans = 1;

        while(y)
        {
            if(y & 1)
                ans = (ans * x) % mod;

            x = (x * x) % mod;
            y >>= 1;
        }
        
        return ans;
    }

public:
    Fancy() {
        increment = 0;
        multiplier = 1;
    }
    
    void append(int val) {
        sequence.push_back((((val - increment + mod) % mod) * binaryExponentation(multiplier, mod - 2)) % mod);
    }
    
    void addAll(int inc) {
        increment = (increment + inc) % mod;
    }
    
    void multAll(int m) {
        multiplier = ((multiplier % mod) * (m % mod)) % mod;
        increment = ((increment % mod) * (m % mod)) % mod;
    }
    
    int getIndex(int indx) {
        if(indx >= sequence.size())
            return -1;
        return ((sequence[indx] % mod * multiplier % mod) % mod + increment % mod) % mod;
    }
};

/**
 * Your Fancy object will be instantiated and called as such:
 * Fancy* obj = new Fancy();
 * obj->append(val);
 * obj->addAll(inc);
 * obj->multAll(m);
 * int param_4 = obj->getIndex(idx);
 */