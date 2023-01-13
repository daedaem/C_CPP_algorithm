#include <bits/stdc++.h>

using namespace std;

string ltrim(const string &);
string rtrim(const string &);



/*
 * Complete the 'longestChain' function below.
 *
 * The function is expected to return an INTEGER.
 * The function accepts STRING_ARRAY words as parameter.
 */
vector<string> arr;
int maxx;
map<string, int>visited;
int check(string newWord) {
	for (int i = 0; i < arr.size(); i++) {
		if (newWord == arr[i]) return 1;
	}
	return 0;
}
int DFS(int len, string word, int cnt) {
	//cout << word << cnt <<'\n';
	if (visited[word]) return visited[word];
	if (!len) return 0;
	if (cnt > maxx) maxx = cnt;
	int sum = 0;
	for (int i = 0; i < word.size(); i++) {
		string newWord = word;
		newWord.erase(i, 1);
		if (newWord.empty()) continue;
		int ret = check(newWord);
		if (ret) visited[newWord] = cnt;
		sum += DFS(len - 1, newWord, cnt + 1);
	}
	return sum;
}
bool COMP(string a, string b) {
	return a.size() < b.size();
}
int longestChain(vector<string> words) {
	sort(words.begin(), words.end(), COMP);
	arr = words;

	maxx = 0;
	for (int i = 0; i < words.size(); i++) {
		if(words[i].size() > 1)DFS(words[i].size(), words[i], 1);
		//cout << maxx<<'\n';
	}
	return maxx + 1;
}

int main()
{
	int C;
	vector<string> words;
	cin >> C;
	words.resize(C);
	for (int i = 0; i < C; i++) {
		cin >> words[i];
	}
	int result = longestChain(words);


	return 0;
}
