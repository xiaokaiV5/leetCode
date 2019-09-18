#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

//我的方案 效率很低  力扣题库约500ms
class Solution {
public:
	vector<int> twoSum(vector<int>& nums, int target) {
		vector<int> result;

		for (vector<int>::iterator iterI = nums.begin(); iterI != nums.end(); ++iterI)
		{
			for (vector<int>::iterator iterJ = iterI + 1; iterJ != nums.end(); ++iterJ)
			{
				if (*iterI + *iterJ == target)
				{
					result.push_back(iterI - nums.begin());
					result.push_back(iterJ - nums.begin());
					return result;
				}
			}
		}
	}
};

//力扣上的优秀方案, 效率非常高 力扣题库约15ms


class Solution {
public:
	vector<int> twoSum(vector<int>& nums, int target) {
		vector<int> result;
		unordered_map<int, int> hashList;
		for (size_t i = 0; i < nums.size(); i++)
		{
			if (hashList.find(nums[i]) != hashList.end() )
			{
				result.push_back( hashList.find(nums[i])->second );
				result.push_back(i);
				break;
			}
			hashList[target - nums[i]] = i;//save index.
		}
		return result;
	}
};
