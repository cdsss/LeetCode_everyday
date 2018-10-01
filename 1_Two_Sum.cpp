/* Two Sum easy */
// Given an array of integers, return indices of the two numbers such that they add up to a specific target.
// You may assume that each input would have exactly one solution, and you may not use the same element twice.

/* Example */
// Input: [3, 2, 4], 6
// Output: [1, 2]

/* solution 1: Brute Force O(n2) */
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        for(int i = 0; i < nums.size(); i++)
            for(int j = i+1; j < nums.size(); j++)
                if(nums[i]+nums[j] == target){
                    vector<int> res;
                    res.push_back(i);
                    res.push_back(j);
                    return res;
                }
    }
};

/* solution 2: Hash using a hash table to store the index of each number */
class Solution{
public:
    vector<int> twoSum(vector<int> &nums, int target){
        unordered_map<int, int> mapping;
        vector<int> result;
        for(int i = 0; i<nums.size(); i++){
            mapping[nums[i]] = i;
        }
        for(int i = 0; i<nums.size(); i++){
            const int gap = target - nums[i];
            if(mapping.find(gap) != mapping.end() && mapping[gap] > i){
                result.push_back(i+1);
                result.push_back(mapping[gap]+1);
                break;
            }
        }
        return result;
    }
};    
