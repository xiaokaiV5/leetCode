/*
编写一个算法来判断一个数是不是“快乐数”。

一个“快乐数”定义为：对于一个正整数，每一次将该数替换为它每个位置上的数字的平方和，
然后重复这个过程直到这个数变为 1，也可能是无限循环但始终变不到 1。如果可以变为 1，那么这个数就是快乐数。

示例 :

输入: 19
	输出 : true
	解释 :
	12 + 92 = 82
	82 + 22 = 68
	62 + 82 = 100
	12 + 02 + 02 = 1

	来源：力扣（LeetCode）
	链接：https ://leetcode-cn.com/problems/happy-number
	著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
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
