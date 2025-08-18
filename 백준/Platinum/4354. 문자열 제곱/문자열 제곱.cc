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

//vector<int> kmp(string pattern, string s) {
//	vector<int> ans;
//	int p_size = pattern.size();
//	int s_size = s.size();
//
//	vector<int> pi = getpi(pattern);
//
//	int start = 0;
//	int matched_len = 0;
//
//	while (start <= s_size - p_size) {
//		if (matched_len < p_size && s[start + matched_len] == pattern[matched_len]) {
//			matched_len++;
//			if (matched_len == p_size) {
//				ans.push_back(start);
//			}
//		}
//		else {
//			if (matched_len == 0) {
//				start++;
//			}
//			else {
//				start += matched_len - pi[matched_len - 1];
//				matched_len = pi[matched_len - 1];
//			}
//		}
//	}
//	return ans;
//}


int main() {


	while (1) {
		string s;
		cin >> s;
		if (s == ".") {
			return 0;
		}
		int len = s.length();
		auto pi = getpi(s);

		int ans = len - pi[len - 1];

		if (len % ans == 0) {
			cout << len / ans << "\n";
		}
		else {
			cout << 1 << "\n";
		}

	}




	return 0;
}