class Solution {
public:
    int bestClosingTime(string &customers) {
        int n = customers.size();
        int yCnt = 0, nCnt = 0;
        for(char c : customers)
            if(c == 'Y')
                yCnt++;
        int minPenalty = n;
        int indx = 0;
        for(int i = 0; i < n; i++)
        {
            int penalty = yCnt + nCnt;
            if(minPenalty > penalty)
            {
                minPenalty = penalty;
                indx = i;
            }
            if(customers[i] == 'Y') 
                yCnt--;
            else
                nCnt++;
        }
        if(minPenalty > nCnt)
            return n;
        return indx;
    }
};