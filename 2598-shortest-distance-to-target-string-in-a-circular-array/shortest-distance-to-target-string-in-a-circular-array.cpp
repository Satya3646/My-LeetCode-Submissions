class Solution {
public:
    int closestTarget(vector <string> &words, string target, int startIndex)
    {
        int n = words.size();

        int minDist = 1000;
        for(int i = 0; i < n; i++)
        {
            if(words[(startIndex + i) % n] == target)
                minDist = min(minDist, i);
            if(words[(startIndex - i + n) % n] == target)
                minDist = min(minDist, i);
        }
        
        return minDist == 1000? -1: minDist;
    }
};