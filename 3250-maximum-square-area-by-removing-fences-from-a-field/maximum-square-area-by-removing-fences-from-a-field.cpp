const int mod = 1e9+7;

class Solution {
public:
    int maximizeSquareArea(int m, int n, vector<int>& hFences, vector<int>& vFences) {
        // push the outer boundaries into the fences since they can also form square.
        hFences.push_back(1);
        hFences.push_back(m);
        vFences.push_back(1);
        vFences.push_back(n);

        unordered_set <int> hGaps; // hash set to store horizontal gaps b/w any two fences.
        hGaps.reserve(hFences.size());
        for(int i : hFences)
            for(int j : hFences)
                if(j != i) // prevent zero.
                    hGaps.insert(abs(j - i));

        int maxSide = -1;
        for(int i : vFences)
        {
            for(int j : vFences)
            {
                int vGap = abs(j - i); // take a vertical gap between the fence i and j.
                if(hGaps.find(vGap) != hGaps.end()) // if same gap is found in horizontal axis too then a square can be formed so update the answer.
                    maxSide = max(maxSide, vGap);
            }
        }
        
        if(maxSide == -1) // no square formed.
            return -1;
        return 1LL * maxSide * maxSide % mod; // return area.
    }
};