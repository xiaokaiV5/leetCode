//����һ���ǿ��������飬����ĳ��Ԫ��ֻ����һ�����⣬����ÿ��Ԫ�ؾ��������Ρ��ҳ��Ǹ�ֻ������һ�ε�Ԫ�ء�
//
//˵����
//
//����㷨Ӧ�þ�������ʱ�临�Ӷȡ� ����Բ�ʹ�ö���ռ���ʵ����
//
//��Դ�����ۣ�LeetCode��
//���ӣ�https ://leetcode-cn.com/problems/single-number
//����Ȩ������������С���ҵת������ϵ�ٷ���Ȩ������ҵת����ע��������

#include <iostream>
#include <vector>
#include <unordered_map>
#include <unordered_set>

using namespace std;

//����1��ͨ����λ���ķ����� 0����κ��������κ����� ������ȵ���������0 
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

//������:hash��洢����
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
	cout << "ֻ����һ�ε����ǣ�" << onceTime;
	return 0;
}