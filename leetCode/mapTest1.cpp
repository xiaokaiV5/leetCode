#include <iostream>
#include <unordered_map>
#include <string>
using namespace std;

typedef list<int> ListInt;

class MyHashSet {
public:
	/** Initialize your data structure here. */
	MyHashSet() {
		//cout<<"init!"<<endl;
	}

	void add(int value) {
		if (contains(value))
		{
			//cout << "add: "<<value <<" :元素已存在。" << endl;
		}
		else
		{
			int key = hashKey(value);
			arrval[key].push_back(value);
			//cout << "add: "<< value <<"成功" << endl;
		}
	}

	void remove(int value) {
		int key = hashKey(value);
		bool ret = false;
		for (list<int>::iterator i = arrval[key].begin(); i != arrval[key].end(); ++i)
		{
			if (*i == value)
			{
				arrval[key].erase(i);
				//cout << "erase: "<< value;
				break;
			}
		}
	}

	/** Returns true if this set contains the specified element */
	bool contains(int value) {
		int key = hashKey(value);
		bool ret = false;
		for (list<int>::const_iterator i = arrval[key].begin(); i != arrval[key].end(); ++i)
		{
			if (*i == value)
			{
				ret = true;
				break;
			}
		}
		//if(ret == true)
			//cout << "contains: "<< value << endl;
		//else
			//cout << "contains: "<< value << " does not exist " << endl;

		return ret;
	}

	int hashKey(int element)
	{
		if (element >= 0)
		{
			return element % 1000;
		}
		else
		{
			//cout << "元素小于0，获取hash值失败。" << endl;
			return -1;
		}
	}

	enum { bucket = 1000 };
	ListInt arrval[bucket];
};

/**
 * Your MyHashSet object will be instantiated and called as such:
 * MyHashSet* obj = new MyHashSet();
 * obj->add(key);
 * obj->remove(key);
 * bool param_3 = obj->contains(key);
 */
/*
["MyHashSet", "add", "remove", "add", "remove", "remove", "add", "add", "add", "add", "remove"]
[[],          [9],    [19],     [14],   [19],      [9],    [0],   [3],   [4],    [0],    [9]]
*/

int main(int argc, char *argv[])
{
	MyHashSet* obj = new MyHashSet();
	obj->add(9);
	obj->remove(19);
	obj->add(14);
	obj->remove(19);
	obj->remove(9);
	obj->add(0);
	obj->add(3);
	obj->add(4);
	obj->add(0);
	obj->remove(9);

	system("pause");
	return 0;
}