#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

vector<int> getpi(string pattern) {

	int size = pattern.length();
	vector<int> pi(size, 0);
	int start = 1;
	int matched_len = 0;

	while (start + matched_len < size) {
		//원본 문자열 대비 복사된 문자열은 start만큼의 gap을 가지고 오른쪽으로 이동
		//이 gap을 메우기 위해 원본 문자열에서는 start + matched 접근, 복사된 문자열은 matched 접근
		if (pattern[start + matched_len] == pattern[matched_len]) { //둘이 같으면?????????? 
			matched_len++; //길이 증가
			pi[start + matched_len - 1] = matched_len; //pi배열에 넣음 (0-based)
		}
		else { //다르면???????????
			if (matched_len == 0) { //다른데 맞는것도 없었으면???????????
				start++; //무지성 +1해버리기
			}
			else { //적어도 뭐가 맞긴 하면????????????
				start += matched_len - pi[matched_len - 1]; //최대 맞은 개수에서 최장 접두사 길이만큼 빼서 점프
				matched_len = pi[matched_len - 1]; //점프 후 맞은 개수는 최장 접미사 길이와 같다
			}
		}
	}

	return pi;
}
int main() {

	int len;
	string pattern;
	cin >> len;
	cin >> pattern;

	auto pi = getpi(pattern);

	cout << len - pi.back();

	return 0;
}