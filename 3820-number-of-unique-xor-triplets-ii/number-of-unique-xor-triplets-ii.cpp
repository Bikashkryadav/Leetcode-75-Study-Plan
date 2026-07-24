class Solution {
public:
    int uniqueXorTriplets(vector<int>& nums) {
        std::ios_base::sync_with_stdio(false);
        std::cin.tie(NULL);

        int max_val = 0;
        for (int num : nums) {
            if (num > max_val) max_val = num;
        }

        int max_xor_bound = 1;
        while (max_xor_bound <= max_val) {
            max_xor_bound <<= 1;
        }
      
        max_xor_bound <<= 1; 


        std::unordered_set<int> unique_set(nums.begin(), nums.end());
        std::vector<int> u_nums(unique_set.begin(), unique_set.end());
        int u_size = u_nums.size();

        std::vector<bool> can_make_pair(max_xor_bound, false);
        


        for (int i = 0; i < u_size; ++i) {
            for (int j = i; j < u_size; ++j) {
                can_make_pair[u_nums[i] ^ u_nums[j]] = true;
            }
        }

        std::vector<bool> can_make_triplet(max_xor_bound, false);
        int total_unique_triplets = 0;

        for (int pair_xor = 0; pair_xor < max_xor_bound; ++pair_xor) {
            if (!can_make_pair[pair_xor]) continue;

            for (int num : u_nums) {
                int triplet_xor = pair_xor ^ num;
                if (!can_make_triplet[triplet_xor]) {
                    can_make_triplet[triplet_xor] = true;
                    total_unique_triplets++;
                }
            }
        }

        return total_unique_triplets;
    }
};