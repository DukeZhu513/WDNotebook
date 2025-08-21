#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>  
#include <queue>  // 必须包含 queue 头文件
using namespace std;

struct TreeNode {
	char data;
	TreeNode* left;
	TreeNode* right;
};
TreeNode* RecursiveBuildTree(int& i, char str[]) {
	char c = str[i];
	++i;
	if (c == '#') {
		return NULL;
	}
	else {
		TreeNode* pNew = new TreeNode;
		pNew->data = c;
		pNew->left = RecursiveBuildTree(i, str);
		pNew->right = RecursiveBuildTree(i, str);
		return pNew;
	}
}
void InOrder(TreeNode* proot) {
	if (proot == NULL) {
		return;
	}
	InOrder(proot->left);
	printf("%c ", proot->data);
	InOrder(proot->right);
}
int main() {
	char str[1000];
	while (scanf("%s",str) != EOF) {
		int i = 0;
		TreeNode* proot = RecursiveBuildTree(i, str);
		InOrder(proot);
		printf("\n");
	}
	return 0;
}
