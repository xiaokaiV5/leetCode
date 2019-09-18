//给定一个非空整数数组，除了某个元素只出现一次以外，其余每个元素均出现两次。找出那个只出现了一次的元素。
//
//说明：
//
//你的算法应该具有线性时间复杂度。 你可以不使用额外空间来实现吗？
//
//来源：力扣（LeetCode）
//链接：https ://leetcode-cn.com/problems/single-number
//著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。

#include <iostream>
#include <vector>
#include <unordered_map>
#include <unordered_set>

using namespace std;

//方案1：通过按位异或的方法， 0异或任何数等于任何数， 两个相等的数异或等于0 
class Solution {
public:
	int singleNumber(vector<int>& nums) {
		int rst = 0;
		for (auto element : nums)
		{
			rst = rst^element;
		}
		return rst;
	}
};

//方案二:hash表存储查找
class SolutionHash {
public:
	int singleNumber(vector<int>& nums) {
		unordered_set<int> vFind;
		for (int i = 0; i < nums.size(); i++)
		{
			if (vFind.find(nums[i]) == vFind.end())
				vFind.insert(nums[i]);
			else
				vFind.erase(nums[i]);
		}
		auto ret = vFind.cbegin();
		return *ret;
	}
};



int main()
{
	vector<int> num = { 1,3,5,3,4,1,5 };
	SolutionHash sul;
	int onceTime = sul.singleNumber(num);
	cout << "只出现一次的数是：" << onceTime;
	return 0;
}