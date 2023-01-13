#include <bits/stdc++.h>

using namespace std;

string ltrim(const string &);
string rtrim(const string &);
vector<string> split(const string &);



/*
 * Complete the 'minimumTreePath' function below.
 *
 * The function is expected to return an INTEGER.
 * The function accepts following parameters:
 *  1. INTEGER n
 *  2. 2D_INTEGER_ARRAY edges
 *  3. INTEGER_ARRAY visitNodes
 */
vector<vector<int>> adjlist;
vector<int> visit;
vector<int> path;
int cnt;
int check(vector<int>visitNodes) {
	int cnt = 0;
	for (int i = 0; i < visitNotes.size(); i++) {
		if (path.find(visitNotes[i]) != path.end()) {
			cnt++;
		}
	}
	if (cnt == visitNodes.size())return 1;
	return 0;
}
int DFS(int nowNode, vector<vector<int>> edges, vector<int>visitNodes) {
	if (check(visitNodes)) return 1;
	cnt++;
	for (int i = 0; i < (int)adjlist[nowNode].size(); i++) {
		int nextNode = adjlist[nowNode][i];
		for (int j = nextNode; j)
			DFS(nextNode, edges);
		cnt++;
	}
	return 0;
}
int minimumTreePath(int n, vector<vector<int>> edges, vector<int> visitNodes) {
	adjlist.resize(n + 1);
	visit.resize(n + 1);
	for (int i = 0; i < edges.size(); i++) {
		adjlist[edges[i][0]].push_back(edges[i][1]);
		adjlist[edges[i][1]].push_back(edges[i][0]);

	}
	DFS(1, edges, visitNodes);
	if (cnt - 2 < 0) return 0;
	return cnt - 2;
}

int main()
{
	ofstream fout(getenv("OUTPUT_PATH"));

	string n_temp;
	getline(cin, n_temp);

	int n = stoi(ltrim(rtrim(n_temp)));

	string edges_rows_temp;
	getline(cin, edges_rows_temp);

	int edges_rows = stoi(ltrim(rtrim(edges_rows_temp)));

	string edges_columns_temp;
	getline(cin, edges_columns_temp);

	int edges_columns = stoi(ltrim(rtrim(edges_columns_temp)));

	vector<vector<int>> edges(edges_rows);

	for (int i = 0; i < edges_rows; i++) {
		edges[i].resize(edges_columns);

		string edges_row_temp_temp;
		getline(cin, edges_row_temp_temp);

		vector<string> edges_row_temp = split(rtrim(edges_row_temp_temp));

		for (int j = 0; j < edges_columns; j++) {
			int edges_row_item = stoi(edges_row_temp[j]);

			edges[i][j] = edges_row_item;
		}
	}

	string visitNodes_count_temp;
	getline(cin, visitNodes_count_temp);

	int visitNodes_count = stoi(ltrim(rtrim(visitNodes_count_temp)));

	vector<int> visitNodes(visitNodes_count);

	for (int i = 0; i < visitNodes_count; i++) {
		string visitNodes_item_temp;
		getline(cin, visitNodes_item_temp);

		int visitNodes_item = stoi(ltrim(rtrim(visitNodes_item_temp)));

		visitNodes[i] = visitNodes_item;
	}

	int result = minimumTreePath(n, edges, visitNodes);

	fout << result << "\n";

	fout.close();

	return 0;
}

string ltrim(const string &str) {
	string s(str);

	s.erase(
		s.begin(),
		find_if(s.begin(), s.end(), not1(ptr_fun<int, int>(isspace)))
	);

	return s;
}

string rtrim(const string &str) {
	string s(str);

	s.erase(
		find_if(s.rbegin(), s.rend(), not1(ptr_fun<int, int>(isspace))).base(),
		s.end()
	);

	return s;
}

vector<string> split(const string &str) {
	vector<string> tokens;

	string::size_type start = 0;
	string::size_type end = 0;

	while ((end = str.find(" ", start)) != string::npos) {
		tokens.push_back(str.substr(start, end - start));

		start = end + 1;
	}

	tokens.push_back(str.substr(start));

	return tokens;
}
