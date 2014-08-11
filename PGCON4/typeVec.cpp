#include<iostream>
#include<string>

#include<conio.h>//for
#include<time.h>//ŽžŠÔŒv‘ª

#include<vector>
#include<algorithm>


using namespace std;

char key;

bool is_key(char tgt)
{
	return tgt == key;
}

bool isn_key(char tgt)
{
	return tgt != key;
}

bool is_odd(int val)
{
	return val & 1;
}

void main()
{
	bool escape = false;
	while (!escape)
	{
		clock_t start, finish;
		string input;
		int inputNum;

		cout << "Enter the NUMBER of strings" << endl;
		cin >> inputNum;

		vector<string> inputList(inputNum, input);

		cout << "Enter the strings" << endl;
		for (int n = 0; n < inputNum; ++n)
		{
			cin >> input;
			inputList[n] = input;
		}

		start = clock();
		for (int iNum = 0; iNum < inputNum; ++iNum)
		{
			int iSize = inputList[iNum].size();
			int answer = iSize;

			string keyList(iSize, 0);//for listing each type of character.
			string keyScan(iSize, 0);//for filtering the target key.
			vector< vector<int> > indexList(iSize, vector<int>(iSize, 0));//list of each character's position.

			int keyN = 0;
			for (int i = 0; i < iSize; ++i)
			{
				key = inputList[iNum][i];//pickup one char from the input.
				if (keyList.find(key) == string::npos)
				{
					keyScan = inputList[iNum];//input -> filter
					replace_if(keyScan.begin(), keyScan.end(), isn_key, 0);
					replace_if(keyScan.begin(), keyScan.end(), is_key, 1);
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

					//for (int l = j; l <= j + segment; ++l)
					//{
					//	cout << inputList[iNum][l];
					//}
					//cout << ( (oddKey<=1) ? " :is anagram " : " :- " ) << endl;
				}
			}
			cout << "Number of anagram is " << answer << endl;
		}
		finish = clock();
		double time = (double)(finish - start)/CLOCKS_PER_SEC;
		cout << " time: " << time << endl;

		getchar();
		cout << "Continue: press Any key / Exit: press Esc key" << endl<<endl;
		escape = ((_getch() == 0x1B) ? true : false) ;
	}
}