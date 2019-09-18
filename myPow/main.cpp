#include<iostream>
#include <vector>

using namespace std;

class Solution {
public:
	double myPow(double x, long long n){
		if (n == 0)
			return 1;
		else {
			double tmpx = x;
			long long nn = abs(n);
			vector<int> yu;

			while (nn > 1) {
				yu.push_back(nn % 2);
				nn = nn / 2;
			}
			double result = x;
			for (vector<int>::reverse_iterator iter = yu.rbegin(); iter != yu.rend(); ++iter)
			{
				if (*iter)
					result = result * result * x;
				else
					result = result * result;
			}

			return n > 0 ? (result) : (1 / result);
		}
	}
	Solution() {};
	~Solution() {};
};

int main()
{
	Solution a;
	a.myPow(1.00000, -2147483648);

	return 0;
}