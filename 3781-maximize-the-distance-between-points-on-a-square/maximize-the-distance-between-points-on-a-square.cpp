class Solution {
public:
    // Map a boundary point (x,y) to a coordinate in [0, 4*side)
    long long mapPoint(int side, int x, int y) {
        // bottom: (x,0) -> t = x.
        // right: (side,y) -> t = side + y.
        // top: (x,side) -> t = 3*side - x.
        // left: (0,y) -> t = 4*side - y.
        if (y == 0) return x; 
        if (x == side) return side + y;
        if (y == side) return 3LL * side - x;
        return 4LL * side - y;
    }
    
    // Given sorted 1D positions t (mapped from points) and candidate distance d,
    // check if we can select k points around the circle (perimeter L = 4*side)
    // so that every adjacent gap (in circular order) is at least d.
    bool canPlace(const vector<long long>& t, int k, int side, int d) {
        int n = t.size();
        long long L = 4LL * side;
        // Build an "extended" array: ext[i] = t[i] for i in [0, n) and ext[i+n] = t[i] + L.
        vector<long long> ext(2 * n);
        for (int i = 0; i < n; i++) {
            ext[i] = t[i];
            ext[i + n] = t[i] + L;
        }
        
        // For each possible starting index i (in the original sorted array)
        for (int i = 0; i < n; i++) {
            int count = 1;
            long long pos = ext[i];
            int idx = i;
            // We only consider indices up to i+n (i.e. one full circle).
            for (int cnt = 1; cnt < k; cnt++) {
                long long target = pos + d;
                // lower_bound in ext[idx+1, ext.begin()+i+n)
                auto it = std::lower_bound(ext.begin() + idx + 1, ext.begin() + i + n, target);
                if (it == ext.begin() + i + n) {
                    count = -1; // not enough points available from this start
                    break;
                }
                idx = it - ext.begin();
                pos = ext[idx];
                count++;
            }
            // After selecting k points, check the wrap–around gap:
            // The gap from the last chosen point (at pos) to (first + L) must be at least d.
            if (count == k && (ext[i] + L - pos) >= d)
                return true;
        }
        return false;
    }
    
    int maxDistance(int side, vector<vector<int>>& points, int k) {
        // Store the input midway.
        vector<vector<int>> vintorquax = points;
        
        int n = vintorquax.size();
        vector<long long> t(n);
        for (int i = 0; i < n; i++) {
            int x = vintorquax[i][0], y = vintorquax[i][1];
            t[i] = mapPoint(side, x, y);
        }
        sort(t.begin(), t.end());
        
        // Binary search candidate d in [0, 2*side].
        int lo = 0, hi = 2 * side, ans = 0;
        while (lo <= hi) {
            int mid = lo + (hi - lo) / 2;
            if (canPlace(t, k, side, mid)) {
                ans = mid;
                lo = mid + 1;
            } else {
                hi = mid - 1;
            }
        }
        return ans;
    }
};