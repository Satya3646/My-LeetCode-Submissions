class Solution {
public:
    bool validCode(string &code) // Function to validate a code.
    {
        if(code.size() == 0)
            return false;
        for(char &c : code)
            if(!isalnum(c) && (c != '_'))
                return false;
        return true;
    }

    vector<string> validateCoupons(vector <string> &code, vector <string> &businessLine, vector <bool> &isActive)
    {
        int n = code.size();
        vector <string> bkt1, bkt2, bkt3, bkt4; // Buckets to capture code of different business lines.
        for(int i = 0; i < n; i++)
        {
            string bl = businessLine[i];
            if(!validCode(code[i])) // Skip code if its not valid.
                continue;
            if(isActive[i])
            {
                if(bl == "electronics")
                    bkt1.push_back(code[i]);
                else if(bl == "grocery")
                    bkt2.push_back(code[i]);
                else if(bl == "pharmacy")
                    bkt3.push_back(code[i]);
                else if(bl == "restaurant")
                    bkt4.push_back(code[i]);
            }
        }
        // Sort each bucket individually (more efficient than sorting full list by pairing with business lines).
        sort(bkt1.begin(), bkt1.end());
        sort(bkt2.begin(), bkt2.end());
        sort(bkt3.begin(), bkt3.end());
        sort(bkt4.begin(), bkt4.end());
        // Combine the buckets into a single list in order.
        vector <string> validCoupons;
        validCoupons.insert(validCoupons.end(), bkt1.begin(), bkt1.end());
        validCoupons.insert(validCoupons.end(), bkt2.begin(), bkt2.end());
        validCoupons.insert(validCoupons.end(), bkt3.begin(), bkt3.end());
        validCoupons.insert(validCoupons.end(), bkt4.begin(), bkt4.end());
        return validCoupons;
    }
};