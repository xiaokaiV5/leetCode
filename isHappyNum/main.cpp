/*
��дһ���㷨���ж�һ�����ǲ��ǡ�����������

һ����������������Ϊ������һ����������ÿһ�ν������滻Ϊ��ÿ��λ���ϵ����ֵ�ƽ���ͣ�
Ȼ���ظ��������ֱ���������Ϊ 1��Ҳ����������ѭ����ʼ�ձ䲻�� 1��������Ա�Ϊ 1����ô��������ǿ�������

ʾ�� :

����: 19
	��� : true
	���� :
	12 + 92 = 82
	82 + 22 = 68
	62 + 82 = 100
	12 + 02 + 02 = 1

	��Դ�����ۣ�LeetCode��
	���ӣ�https ://leetcode-cn.com/problems/happy-number
	����Ȩ������������С���ҵת������ϵ�ٷ���Ȩ������ҵת����ע��������
*/

#include <vector>
#include <unordered_set>
#include <iostream>

using namespace std;

class Solution {
public:
	bool isHappy(int n) {
		unordered_set<int> historyRst;

		historyRst.insert(n);
		int tmpNum = 0;

		while (true)
		{
			if (n == 1)
				return true;

			while (n) {
				tmpNum += (int)pow((n % 10), 2);
				n = n / 10;
			}
			n = tmpNum;
			tmpNum = 0;

			if (historyRst.find(n) != historyRst.end())
				return false;
			historyRst.insert(n);
		}
	}
};

int main()
{
	Solution solution;
	bool rst = solution.isHappy(2);
	string strRst = (rst == true ? "YES" : "NO");
	cout << "happy num? --->" << strRst << endl;
	return 0;
}
