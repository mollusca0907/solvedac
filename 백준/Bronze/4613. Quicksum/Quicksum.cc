#include <iostream>
#include <string>
using namespace std;
int main(void)
{
	while (1)
	{
		string s;
		getline(cin, s);
		if (s == "#")
			break;
		int sum = 0, len = s.length();
		for (int i = 0; i < len; i++)
		{
			if ((char)s[i] == ' ');
			else
				sum += (int)(s[i] - 'A' + 1)*(i + 1);
		}
		cout << sum << '\n';
	}
}