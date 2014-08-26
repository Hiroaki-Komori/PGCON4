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

bool is_odd(int val)
{
	return val & 1;
}

int main()
{
	int inputNum;
	cin >> inputNum;

	std::vector<is_key> is_key_list;
    const size_t KEY_N = 26;
    for (int i = 0; i < KEY_N; ++i)
    {
        is_key_list.push_back(is_key('a' + i));
    }

	for (int n = 0; n < inputNum; ++n)
	{
	    string input;
		cin >> input;

		size_t iSize = input.length();
        int answer = iSize;

		for (int segment = 1; segment < iSize; ++segment)
		{
			for (int j = 0; j < iSize - segment; ++j)
			{
				int oddKey = 0;
				for (int k = 0; k < KEY_N && oddKey <= 1; ++k)
				{
					int num = count_if(input.begin() + j, input.begin() + j + segment + 1, is_key_list[k]);
					is_odd(num) ? ++oddKey : 0;
				}
				(oddKey <= 1) ? ++answer : 0;
			}
		}
		cout << answer << endl;
	}
	return 0;
}
