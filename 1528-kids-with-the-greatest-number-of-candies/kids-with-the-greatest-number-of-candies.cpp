class Solution {
public:
    vector<bool> kidsWithCandies(vector<int>& candies, int extraCandies) {
        int l1 = candies.size();
        
        int maxcandies = candies[0]; 
        
        for(int i = 0; i < l1; i++) {
            if(maxcandies < candies[i]) {
                maxcandies = candies[i];
            }
        }
        
        vector<bool> result;
        for(int j = 0; j < l1; j++) {
            if(candies[j] + extraCandies >= maxcandies) {
                result.push_back(true);
            } else {
                result.push_back(false);
            }
        }
        return result;
    }
};
