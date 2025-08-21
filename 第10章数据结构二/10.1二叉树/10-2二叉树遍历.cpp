#include <stdio.h>
#include <string>
using namespace std;

struct TreeNode {
    char data;
    TreeNode* left;
    TreeNode* right;
    // 构造函数（可选）
    TreeNode() : data(0), left(nullptr), right(nullptr) {}
};

TreeNode* Rebuild(string preOrder, string inOrder) {
    if (preOrder.size() == 0) {
        return nullptr;  // 或 NULL
    }

    char rootData = preOrder[0];  // 根节点是先序的第一个字符
    TreeNode* pNew = new TreeNode;
    pNew->data = rootData;

    // 在中序中找到根的位置
    size_t pos = inOrder.find(rootData);
    if (pos == string::npos) {
        // 安全检查：没找到根（理论上不会发生）
        delete pNew;
        return nullptr;
    }

    // 分割中序：左子树 inOrder.substr(0, pos)，右子树 inOrder.substr(pos+1)
    // 分割先序：跳过第一个（根），前 pos 个是左子树，剩下是右子树
    string leftIn = inOrder.substr(0, pos);
    string rightIn = inOrder.substr(pos + 1);

    string leftPre = preOrder.substr(1, pos);           // 左子树长度 = pos
    string rightPre = preOrder.substr(pos + 1);         // 剩下的部分

    // 递归构建左右子树
    pNew->left = Rebuild(leftPre, leftIn);
    pNew->right = Rebuild(rightPre, rightIn);

    return pNew;
}

void PostOrder(TreeNode* proot) {
    if (proot == nullptr) {
        return;
    }
    PostOrder(proot->left);
    PostOrder(proot->right);
    printf("%c", proot->data);
}

int main() {
    char preStr[30];
    char inStr[30];

    while (scanf("%s %s", preStr, inStr) != EOF) {
        string preOrder(preStr);
        string inOrder(inStr);

        TreeNode* proot = Rebuild(preOrder, inOrder);
        PostOrder(proot);
        printf("\n");

        // 可选：释放内存（防止泄漏）
        // FreeTree(proot);
    }

    return 0;
}
