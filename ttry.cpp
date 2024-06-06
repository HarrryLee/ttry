








































/* c039. 00100 - The 3n + 1 problem */
#include <iostream>

using namespace std;

int main() {
	int i, j;
	int m, M;
	int count, test, cycle_Max;

	ios::sync_with_stdio(0);
	cin.tie(0);
	while (cin >> i >> j) {
		m = min(i, j);
		M = max(i, j);
		cycle_Max = 0;

		for (int num = m; num <= M; num++) {
			test = num;
			count = 0;
			while (1) {
				count++;
				if (test == 1) {
					break;
				}
				if (test % 2 == 1) {
					test = test * 3 + 1;
				}
				else {
					test /= 2;
				}

			}
			cycle_Max = max(cycle_Max, count);
		}
		cout << i << " " << j << " " << cycle_Max << endl;
	}
	return 0;
}

/* c007. 00272 - TeX Quotes */
#include <iostream>
#include <string>
using namespace std;
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	string s;
	int count = 0;
	while (getline(cin, s)) {
		for (int i = 0; i < s.length(); i++) {
			if (s[i] == '\"') {
				count++;
				if ((count % 2) == 1) {
					cout << "``";
				}
				else {
					cout << "''";
				}
			}
			else {
				cout << s[i];
			}
		}
		cout << endl;
	}
	return 0;
}

/*c054. 10082 - WERTYU*/
#include <iostream>
#include <string>
using namespace std;
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	string keyboard = "`1234567890-=QWERTYUIOP[]\\ASDFGHJKL;'ZXCVBNM,./";
	char n;
	int count;
	while (cin.get(n)) {
		if (n == ' ' || n == '\n') {
			cout << n;
		}
		else {
			count = keyboard.find(n);
			cout << keyboard[count - 1];
		}
	}
	return 0;
}

/*e543. 00401 - Palindromes*/
#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

string SS = "ABCDEFGHIJKLMNOPQRSTUVWXYZ123456789";
string SR = "A   3  HIL JM O   2TUVWXY51SE Z  8 ";
bool isP(string s) {
	string rs = s;
	reverse(rs.begin(), rs.end());
	return rs == s;
}
bool isM(string s) {
	string rs = s;
	int index;
	reverse(rs.begin(), rs.end());
	for (int i = 0; i < s.size(); i++)
	{
		index = SS.find(rs[i]);
		rs[i] = SR[index];
	}
	return rs == s;
}
int main()
{
	string s;
	bool p, m;
	while (cin >> s)
	{
		p = isP(s);
		m = isM(s);
		cout << s << " -- is ";
		if (p && m == 1)
		{
			cout << "a mirrored palindrome.";
		}
		else if (p)
		{
			cout << "a regular palindrome.";
		}
		else if (m)
		{
			cout << "a mirrored string.";
		}
		else
		{
			cout << "not a palindrome.";
		}
		cout << "\n\n";
	}
}

/* e558. 01583 - Digit Generator */
#include <iostream>
#include <string>
using namespace std;
int mg[100001] = { 0 };
int main() {

	int x, y, i, T;
	for (i = 0; i < 100000; i++)
	{
		y = x = i;
		while (x > 0)
		{
			y = y + x % 10;
			x /= 10;
		}
		if (y > 100000)
		{
			continue;
		}
		if (mg[y] == 0)
		{
			mg[y] = i;
		}
	}int num;
	cin >> T;
	while (T--)
	{
		cin >> num;
		cout << mg[num] << endl;
	}
}

/* d132. 00340 - Master-Mind Hints */
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
	//ios::sync_with_stdio(0);
	//cin.tie(0);
	int game = 0;
	int n;
	int A, B, zeroNum, sc, gc;
	vector<int> s(n);
	vector<int> g(n);

	while (cin >> n && n != 0) {
		printf("Game %d:\n", ++game);
		for (int i = 0; i < n; i++) {
			cin >> s[i];
		}

		while (true) {
			A = 0;
			zeroNum = 0;

			for (int i = 0; i < n; i++) {
				cin >> g[i];
				if (s[i] == g[i]) {
					A++;
				}
				if (g[i] == 0) {
					zeroNum++;
				}
			}

			if (zeroNum == n) {
				break;
			}

			B = 0;

			for (int d = 0; d <= 9; d++) {
				sc = 0;
				gc = 0;
				for (int i = 0; i < n; i++) {
					if (s[i] == d) {
						sc++;
					}
					if (g[i] == d) {
						gc++;
					}
				}
				B += min(sc, gc);
			}
			printf("    (%d,%d)\n", A, B - A);
		}
	}
	return 0;
}

/* j121. 01339 - Ancient Cipher */
#include <iostream>
#include <algorithm>
#include <vector>
#include <string>

using namespace std;

int main() {
	string strA, strB;
	while (cin >> strA >> strB)
	{
		vector<int> vA(26, 0), vB(26, 0);
		for (auto c : strA)
		{
			vA[c - 'A']++;
		}for (auto c : strB)
		{
			vB[c - 'A']++;
		}
		sort(vA.begin(), vA.end());
		sort(vB.begin(), vB.end());
		if (vA == vB)
		{
			cout << "YES" << endl;
		}
		else
		{
			cout << "NO" << endl;
		}
	}
	return 0;
}

/* c073. 00101 - The Blocks Problem */
#include <iostream>
#include <string>
#include <vector>

using namespace std;
int n;
vector<int> v[25];

void find_block(int a, int& p, int& h) {
	for (p = 0; p < n; p++)
	{
		for (h = 0; h < v[p].size(); h++)
		{
			if (v[p][h] == a)
			{
				return;
			}
		}
	}
}
void clear_above(int p, int h) {
	int ori;
	for (int i = v[p].size() - 1; i > h; i--)
	{
		ori = v[p][i];
		v[ori].push_back(ori);
		v[p].pop_back();
	}
	return;
}
void pipe_over(int a, int h, int b) {
	v[b].insert(v[b].end(), v[a].begin() + h, v[a].end());
	v[a].erase(v[a].begin() + h, v[a].end());
}
void show() {
	for (int i = 0; i < n; i++)
	{
		cout << i << ":";
		for (int j = 0; j < v[i].size(); j++)
		{
			cout << " " << v[i][j];
		}
		cout << endl;
	}
}
int main()
{
	int a, b;
	string s1, s2;
	int pa, pb;
	int ha, hb;
	while (cin >> n)
	{
		for (int i = 0; i < n; i++) {
			v[i].clear();
			v[i].push_back(i);
		}
		while (cin >> s1)
		{
			if (s1 == "quit")
			{
				break;
			}
			cin >> a >> s2 >> b;
			find_block(a, pa, ha);
			find_block(b, pb, hb);
			if (pa != pb)
			{
				if (s1 == "move")
				{
					clear_above(pa, ha);
				}
				if (s2 == "onto")
				{
					clear_above(pb, hb);
				}
				pipe_over(pa, ha, pb);
			}
		}
		show();
	}
}

/* e541. 10474 - Where is the marble */
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

#define ALL(x) x.begin(), x.end()
int main() {
	int Case = 0;
	int N, Q;
	while (cin >> N >> Q && N != 0)
	{
		printf("CASE# %d:\n", ++Case);
		vector<int> v(N);
		for (int i = 0; i < N; i++)
		{
			cin >> v[i];
		}
		sort(v.begin(), v.end());
		while (Q--)
		{
			int find_num;
			cin >> find_num;
			int p = lower_bound(v.begin(), v.end(), find_num) - v.begin();
			if (p < N && v[p] == find_num)
			{
				printf("%d found at %d\n", find_num, (p + 1));
			}
			else {
				printf("%d not found\n", find_num);
			}
		}
	}
}

/* e155. 10935 - Throwing cards away I */
#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>
using namespace std;
int main() {
	int n;
	bool first;
	while (cin >> n && n != 0)
	{
		queue<int>q;
		for (int i = 1; i <= n; i++)
		{
			q.push(i);
		}
		first = true;
		printf("Discarded cards: ");
		while (q.size() >= 2)
		{
			if (first)
			{
				first = false;
			}
			else {
				cout << ", ";
			}
			cout << q.front();
			q.pop();
			q.push(q.front());
			q.pop();
		}
		cout << endl;
		cout << "Remaining card: " << q.front() << endl;;
	}
	return 0;
}

/* f166. 傳送點 */
#include<iostream>
#include<queue>
using namespace std;
int S[1000000];
int count[1000000];

int main() {
	int n, P, R, L;
	int currentP, newL, newR;
	queue<int> q;

	cin >> n >> P >> L >> R;

	for (int i = 0; i < n; i++) {
		cin >> S[i];
	}
	q.push(0);
	while (true) {
		if (q.empty()) {
			cout << -1;
			break;
		}
		currentP = q.front();
		q.pop();
		if (currentP == P) {
			cout << count[currentP];
			break;
		}
		newL = currentP - L;
		if (newL >= 0) {
			newL = S[newL];
			if (newL >= 0 && newL < n && count[newL] == 0) {
				count[newL] = count[currentP] + 1;
				q.push(newL);
			}
		}
		newR = currentP + R;
		if (newR < n) {
			newR = S[newR];
			if (newR >= 0 && newR < n && count[newR] == 0) {
				count[newR] = count[currentP] + 1;
				q.push(newR);
			}
		}
	}
	return 0;
}

/*b838. 104北二2.括號問題*/

#include<iostream>
#include<stack>
#include<string>
using namespace std;
int main()
{
	int times;
	cin >> times;
	while (times--)
	{
		string s;
		cin >> s;
		stack<char>st;
		bool valid = true;
		int ans = 0;
		for (auto c : s)
		{
			if (c == '(')
			{
				st.push('(');
			}
			else
			{
				if (!st.empty() && st.top() == '(')
				{
					ans++;
					st.pop();
				}
				else
				{
					valid = false;
					break;
				}
			}
		}
		if (!st.empty())
		{
			valid = false;
		}if (valid)
		{
			cout << ans << endl;
		}
		else
		{
			cout << 0 << endl;
		}
	}
}

/* h028. 202001_3 砍樹 */
#include <iostream>
#include <utility>
#include <stack>
#include <algorithm> 
#include <climits>
using namespace std;

pair<int, int> T[100002];

int main() {
	int N, L;
	int total = 0, height = 0;

	stack<pair<int, int>> s;
	cin >> N >> L;

	T[0].first = 0;
	T[0].second = INT_MAX;

	for (int i = 1; i <= N; i++) {
		cin >> T[i].first;
	}
	for (int i = 1; i <= N; i++) {
		cin >> T[i].second;
	}

	T[N + 1].first = L;

	s.push(T[0]);
	for (int i = 1; i <= N; i++) {
		bool left = T[i].first - T[i].second >= s.top().first;
		bool right = T[i].first + T[i].second <= T[i + 1].first;
		if (left || right) {
			total++;
			height = max(height, T[i].second);

			while (s.top().first + s.top().second <= T[i + 1].first) {
				total++;
				height = max(height, s.top().second);
				s.pop();
			}
		}
		else {
			s.push(T[i]);
		}
	}
	cout << total << '\n' << height;
	return 0;
}

/* f698. 後序運算式求值 */
#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>
#include<stack>
#include<string>
using namespace std;
int main() {
	string opstr = "+-*/";
	stack<int> num;
	int op, n1, n2;
	string s;
	while (cin >> s)
	{
		op = opstr.find(s);
		if (op == -1)
		{
			num.push(stoi(s));
		}
		else
		{
			n2 = num.top();
			num.pop();
			n1 = num.top();
			num.pop();
			switch (op)
			{
			case 0:
				num.push(n1 + n2);
				break;
			case 1:
				num.push(n1 - n2);
				break;
			case 2:
				num.push(n1 * n2);
				break;
			default:
				num.push(n1 / n2);
				break;
			}
		}
	}
	cout << num.top();
	return 0;
}

/* d217. 00489 - Hangman Judge */
#include<iostream>
#include<set>
#include<string>
using namespace std;
int main()
{
	int round, chance;
	bool win, lose;
	string s0, s1;
	while (cin >> round)
	{
		if (round == -1)
		{
			break;
		}
		cin >> s0 >> s1;
		set<char> correctStr(s0.begin(), s0.end());
		set<char>guessStr;
		win = lose = false;
		chance = 7;
		for (int i = 0; i < s1.length(); i++)
		{
			if (guessStr.count(s1[i]))
			{
				continue;
			}
			guessStr.insert(s1[i]);
			if (correctStr.count(s1[i]))
			{
				correctStr.erase(s1[i]);
			}
			else
			{
				chance--;
			}
			if (chance == 0)
			{
				lose = true;
			}
			else if (correctStr.empty())
			{
				win = true;
			}
			if (win || lose)
			{
				break;
			}
		}
		cout << "Round " << round << endl;
		if (win)
		{
			cout << "You win." << endl;
		}
		else if (lose)
		{
			cout << "You lose." << endl;
		}
		else
		{
			cout << "You chickened out." << endl;
		}
	}
}

/* d244. 一堆石頭 */
#include<iostream>
#include<map>
using namespace std;

int main() {
	map	<int, int>st;
	int n;
	while (cin >> n)
	{
		st[n]++;
	}
	for (auto c : st)
	{
		if (c.second % 3)
		{
			cout << c.first;
			break;
		}
	}
	return 0;
}

/* e564. 00540 - Team Queue */
#include<iostream>
#include<string>
#include <queue>
#include <map>
using namespace std;


int main() {
	int t, n, x;
	int t0;
	int group = 0;

	while (cin >> t && t) {
		map<int, int> team;
		for (int i = 0; i < t; i++) {
			cin >> n;
			while (n--) {
				cin >> x;
				team[x] = i;
			}
		}
		queue<int> teamQueue;
		queue<int> elementQueue[1000];

		printf("Scenario #%d\n", ++group);

		string cmd;
		while (cin >> cmd && cmd != "STOP") {
			if (cmd == "ENQUEUE") {
				cin >> x;
				t0 = team[x];
				if (elementQueue[t0].empty()) {
					teamQueue.push(t0);
				}
				elementQueue[t0].push(x);
			}
			else if (cmd == "DEQUEUE") {
				t0 = teamQueue.front();
				cout << elementQueue[t0].front() << endl;
				elementQueue[t0].pop();
				if (elementQueue[t0].empty()) {
					teamQueue.pop();
				}
			}
		}
		cout << endl;
	}
	return 0;
}

/* d221. 10954 - Add All */
#include<iostream>
#include <queue>
#include<vector>
using namespace std;


int main() {
	int n;
	int i, d;
	while (cin >> n && n)
	{
		priority_queue<int, vector<int>, greater<int>>pq;
		for (i = 0; i < n; i++)
		{
			cin >> d;
			pq.push(d);
		}
		long long sum, cost = 0;
		while (pq.size() != 1)
		{
			sum = pq.top();
			pq.pop();
			sum += pq.top();
			pq.pop();
			cost += sum;
			pq.push(sum);
		}
		cout << cost << endl;
	}
	return 0;
}

/* e548. 11995 - I Can Guess the Data Structure! */
#include<iostream>
#include<set>
#include<string>
#include <iostream>
#include <utility>
#include <stack>
#include <algorithm> 
#include <climits> 
#include <map>
#include <queue>
using namespace std;


int main() {
	int n;
	int t, x;

	while (cin >> n) {
		bool ans[3] = { true, true ,true };
		stack<int> s;
		queue<int> q;
		priority_queue<int> pq;

		while (n--) {
			cin >> t >> x;
			if (t == 1) {
				s.push(x);
				q.push(x);
				pq.push(x);
			}
			else {
				if (ans[0]) {
					if (!s.empty() && x == s.top()) {
						s.pop();
					}
					else {
						ans[0] = false;
					}
				}
				if (ans[1]) {
					if (!q.empty() && x == q.front()) {
						q.pop();
					}
					else {
						ans[1] = false;
					}
				}
				if (ans[2]) {
					if (!pq.empty() && x == pq.top()) {
						pq.pop();
					}
					else {
						ans[2] = false;
					}
				}
			}
		}
		if (ans[0] && !ans[1] && !ans[2]) {
			cout << "stack" << endl;
		}
		else if (!ans[0] && ans[1] && !ans[2]) {
			cout << "queue" << endl;
		}
		else if (!ans[0] && !ans[1] && ans[2]) {
			cout << "priority queue" << endl;
		}
		else if (!ans[0] && !ans[1] && !ans[2]) {
			cout << "impossible" << endl;
		}
		else {
			cout << "not sure" << endl;
		}
	}

	return 0;
}

/* h083. 3. 數位占卜 */
#include<iostream>
#include <queue>
#include<vector>
#include<algorithm>
using namespace std;


int main() {
	int m, len;
	int ans = 0;
	string s0;
	vector<string>v;
	cin >> m;
	while (m--)
	{
		cin >> s0;
		v.push_back(s0);
	}
	sort(v.begin(), v.end());
	for (auto s1 : v)
	{
		len = s1.length();
		for (int i = 1; i <= len / 2; i++)
		{
			if (s1.substr(0, i) == s1.substr(len - i, i))
			{
				if (binary_search(v.begin(), v.end(), s1.substr(i, len - 2 * i)))
				{
					ans++;
				}

			}
		}
	}
	cout << ans;
	return 0;
}

/* f640. 函數運算式求值 */
#include<iostream>
#include<string>
using namespace std;

int recur_equal() {
	string token;
	int x, y, z;
	cin >> token;
	if (token == "f")
	{
		x = recur_equal();
		return 2 * x - 3;
	}
	if (token == "g")
	{
		x = recur_equal();
		y = recur_equal();
		return 2 * x + y - 7;
	}
	if (token == "h")
	{
		x = recur_equal();
		y = recur_equal();
		z = recur_equal();
		return 3 * x - 2 * y + z;
	}
	return(stoi(token));
}
int main()
{
	cout << recur_equal() << endl;
	return 0;
}

/* f637. DF-expression */
#include <iostream>

using namespace std;

string s;
int p;
int recur_decode(int size_n);

int main()
{
	int size_n;

	cin >> s;
	cin >> size_n;

	p = -1;
	cout << recur_decode(size_n) << endl;
	return 0;
}
int recur_decode(int size_n)
{
	int black = 0;
	p++;

	if (s[p] == '0')
	{
		black = 0;
	}
	else if (s[p] == '1')
	{
		black = size_n * size_n;
	}
	else
	{
		for (int i = 0; i <= 3; i++)
		{
			black += recur_decode(size_n / 2);
		}
	}
	return black;
}

/* k733. 3. 磁軌移動序列 */
#include<iostream>
#include<string>

using namespace std;

long long loop(int& head, int& tail); //
string s0;
int tape = 0;

int main() {
	int h, t;
	long long walk = 0;
	cin >> s0;
	walk = loop(h, t);
	walk = walk + abs(h - 10);
	cout << walk;
	return 0;
}
long long loop(int& head, int& tail) {
	long long walk = 0, subwalk;
	int num, h, t;
	head = tail = -1;
	while (1)
	{
		if (tape == s0.size()) {
			return walk;
		}
		if (s0[tape] == 'T') {
			num = stoi(s0.substr(tape + 1, 2));
			tape = tape + 3;
			if (tail == -1) {
				head = num;
			}
			else
			{
				walk = walk + abs(num - tail);
			}
			tail = num;
		}
		else if (s0[tape] == 'L') {
			num = stoi(s0.substr(tape + 1, 1));
			tape = tape + 2;
			subwalk = loop(h, t);
			if (tail == -1)
			{
				head = h;
			}
			else
			{
				walk = walk + abs(h - tail);
			}
			tail = t;
			walk = walk + subwalk * num + abs(t - h) * (num - 1);
		}
		else
		{
			tape++;
			return walk;
		}
	}
}