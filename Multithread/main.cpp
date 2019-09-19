/*
我们提供了一个类：

public class Foo {
	public void one() { print("one"); }
	public void two() { print("two"); }
	public void three() { print("three"); }
}
三个不同的线程将会共用一个 Foo 实例。

线程 A 将会调用 one() 方法
线程 B 将会调用 two() 方法
线程 C 将会调用 three() 方法
请设计修改程序，以确保 two() 方法在 one() 方法之后被执行，three() 方法在 two() 方法之后被执行。



示例 1:

输入: [1, 2, 3]
	输出 : "onetwothree"
	解释 :
	有三个线程会被异步启动。
	输入[1, 2, 3] 表示线程 A 将会调用 one() 方法，线程 B 将会调用 two() 方法，线程 C 将会调用 three() 方法。
	正确的输出是 "onetwothree"。

	来源：力扣（LeetCode）
	链接：https ://leetcode-cn.com/problems/print-in-order
	著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

#include <iostream>
#include <vector>
#include <thread>

using namespace std;
constexpr static int FirstThread = 0x01 << 0;
constexpr static int SecondThread = 0x01 << 1;
constexpr static int ThirdThread = 0x01 << 2;
class Foo {
public:
	Foo() {
		powerBy = FirstThread;
	}

	void first() {
		// printFirst() outputs "first". Do not change or remove this line.
		cout << "printFirst" << endl;

	}

	void second() {

		// printSecond() outputs "second". Do not change or remove this line.
		cout << "printFirst" << endl;
	}

	void third() {

		// printThird() outputs "third". Do not change or remove this line.
		cout << "printFirst" << endl;
	}
private:
	int powerBy;
};

int main()
{

	return 0;
}