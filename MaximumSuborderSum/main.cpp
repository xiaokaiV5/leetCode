/*
给定一个整数数组 nums ，找到一个具有最大和的连续子数组（子数组最少包含一个元素），返回其最大和。

示例:

输入: [-2,1,-3,4,-1,2,1,-5,4],
输出: 6
解释: 连续子数组 [4,-1,2,1] 的和最大，为 6。

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/maximum-subarray
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。

*/

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

//我的方案 执行用时1500ms 

//class Solution {
//public:
//	int maxSubArray(vector<int>& nums) {
//		int maxValue= nums[0];
//		for (vector<int>::iterator iterHead = nums.begin(); iterHead!=nums.end(); iterHead++)
//		{
//			maxValue = maxValue>=*iterHead?maxValue:*iterHead;//存储最大数的变量
//			int sumValue = *iterHead;//存储相加和
//			for (vector<int>::iterator iterTail = iterHead+1; iterTail != nums.end(); iterTail++)
//			{
//				sumValue += *iterTail;
//				maxValue = maxValue >= sumValue ? maxValue : sumValue;
//
//			}
//		}
//		return maxValue;
//	}
//};


//leetcode优秀方案 执行用时8ms 
class Solution {
public:
	int maxSubArray(vector<int>& nums) {
		//if (nums.empty())    return 0;
		//vector<int> dp(nums.size());
		//dp[0] = nums[0];
		int res = nums[0];
		int dp0 = nums[0];
		int dpCurrent = 0;
		for (int i = 1; i < nums.size(); i++) {
			//dp用来存储以前元素组合与当前元素相加是否增大,若增大则将当前元素添加到元素组合中,
			//若减小则证明以前组合与当前元素组合会减小和,舍弃以前的元素组合,以当前元素为首元素继续组合.
	/*		dp[i] = max(dp[i - 1] + nums[i], nums[i]);
			res = max(dp[i], res);*/
			dpCurrent = max(dp0 + nums[i], nums[i]);
			res = max(dpCurrent, res);
			dp0 = dpCurrent;
		}
		return res;
	}
};

int main()
{
	vector<int> nums = { 4,-1,-1,-1,-1,5,1 };
	Solution a;
	int max = a.maxSubArray(nums);

	cout << "max:" << max << endl;


	return 0;
}
