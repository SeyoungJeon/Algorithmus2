#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
#include <deque>

using namespace std;

vector<int> pre, post;

struct Node {
	int node, x, y;
	Node *left, *right;
};

bool compare(const Node &a, const Node &b) {
	if (a.y == b.y)
		return a.x < b.x;

	return a.y > b.y;
}

void InsertNode(Node *parent, Node *child) {
	
	if (parent->x > child->x) {
		// 왼쪽 자식인 경우
		if (parent->left == NULL) {
			// 왼쪽 자식이 없는 경우
			parent->left = child;
		}
		else {
			// 왼쪽 자식이 있는 경우
			InsertNode(parent->left, child);
		}
	}
	else {
		// 오른쪽 자식인 경우
		if (parent->right == NULL) {
			// 오른쪽 자식이 없는 경우
			parent->right = child;
		}
		else {
			// 오른쪽 자식이 있는 경우
			InsertNode(parent->right, child);
		}
	}
}

void postOrder(Node *root) {
	if (root) {
		postOrder(root->left);
		postOrder(root->right);
		post.push_back(root->node);
	}
}

void preOrder(Node *root) {
	if (root) {
		pre.push_back(root->node);
		preOrder(root->left);
		preOrder(root->right);
	}
}

vector<vector<int>> solution(vector<vector<int>> nodeinfo) {
	vector<vector<int>> answer;
	
	vector<Node> v;
	for (int i = 0; i < nodeinfo.size(); i++) {
		v.push_back({ i + 1,nodeinfo[i][0],nodeinfo[i][1] });
	}
	
	sort(v.begin(), v.end(), compare);

	Node *root = &v[0];

	for (int i = 1; i < v.size(); i++) {
		InsertNode(root, &v[i]);
	}

	preOrder(root);
	postOrder(root);

	answer.push_back(pre);
	answer.push_back(post);

	return answer;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	solution({ {5,3},{11,5},{13,3},{3,5},{6,1},{1,3},{8,6},{7,2},{2,2} });

	return 0;
}