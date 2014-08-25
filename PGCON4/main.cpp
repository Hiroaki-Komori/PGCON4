#include<iostream>
#include<string>
#include<vector>
#include<algorithm>

using namespace std;

struct is_key : public std::unary_function<bool, char> {
    char key_;
    is_key(char key) : key_(key) {}
    bool operator()(char target) { return key_ == target; }
};

struct is_not_key : public std::unary_function<bool, char> {
    char key_;
    is_not_key(char key) : key_(key) {}
    bool operator()(char target) { return key_ != target; }
};

bool is_odd(int val)
{
	return val & 1;
}

int main()
{
	int inputNum;
	cin >> inputNum;


	for (int n = 0; n < inputNum; ++n)
	{
	    string input;
		cin >> input;

		int iSize = input.size();
		int answer = iSize;

		string keyList(iSize, 0);//for listing each type of character.
		string keyScan(iSize, 0);//for filtering the target key.
		vector< vector<int> > indexList(iSize, vector<int>(iSize, 0));//list of each character's position.

		int keyN = 0;
		for (int i = 0; i < iSize; ++i)
		{
			char key = input[i];//pickup one char from the input.
			is_key is_key_func(key);
			is_not_key is_not_key_func(key);
			if (keyList.find(key) == string::npos)
			{
				keyScan = input;//input -> filter
				replace_if(keyScan.begin(), keyScan.end(), is_not_key_func, 0);
				replace_if(keyScan.begin(), keyScan.end(), is_key_func, 1);
				copy(keyScan.begin(), keyScan.end(), indexList[keyN].begin());
				keyList[keyN] = key;
				++keyN;
			}
		}
		for (int segment = 1; segment < iSize; ++segment)
		{
			for (int j = 0; j < iSize - segment; ++j)
			{
				int oddKey = 0;
				for (int k = 0; k < keyN; ++k)
				{
					int num = count(indexList[k].begin() + j, indexList[k].begin() + j + segment + 1, 1);
					is_odd(num) ? ++oddKey : 0;
				}
				(oddKey <= 1) ? ++answer : 0;
			}
		}
		cout << answer << endl;
	}
return 0;
}
