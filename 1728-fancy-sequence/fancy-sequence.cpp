const unsigned int mod = 1e9+7;

class Fancy {
    vector <int> sequence; // Store the sequence.
    long long increment, multiplier;
    
private:
    int binaryExponentation(long long x, long long y)
    {
        long long ans = 1;

        while(y)
        {
            if(y & 1) // When power is odd we mulitply.
                ans = (ans * x) % mod;

            // When power is even mulitply value with itself and halve the power.
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
        /* Since we can lose increment and multiplier due to addition of new value to   
        sequence we will simply modify the new value such that when returning the effects 
        of increment and multiplier get cancelled, do (new - increment) / multiplier. */
        sequence.push_back((((val - increment + mod) % mod) * binaryExponentation(multiplier, mod - 2)) % mod);
        /* Since (a/b) % m = ((a % m) * (b^-1 % m)) % m.
        m = 1^9+7 which is prime so we can use Fermat's Theorem which startes : 
        a^m = a % m if m is prime ==> a^(m-2) = a^-1 % m, hence we just need to 
        calculate a^(m-2) using binary exponentation. */
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
        // Deupdate the value in sequence and return.
        // Original = val * multiplier + increment.
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