
#include<iostream>
#include<string>
#include<vector>
#include<stack>
#include<queue>

using namespace std;

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode* left, TreeNode* right) : val(x), left(left), right(right) {}
};

class Solution {

public:

    //构建二叉搜索树
    inline TreeNode* build(TreeNode* root, int val) {
        if (root == NULL) {
            root = new TreeNode();
            root->val = val;
            return root;
        }
        if (val < root->val) root->left = build(root->left, val);
        else if (val > root->val) root->right = build(root->right, val);
        return root;
    }

    //前序递归遍历
    inline void preOrderTreverselRecision(TreeNode* root) {
        if (NULL != root) {
            cout << root->val << " ";
            preOrderTreverselRecision(root->left);
            preOrderTreverselRecision(root->right);
        }
    }

    //中序递归遍历
    inline void inOrderTreverselRecision(TreeNode* root) {
        if (NULL != root) {
            inOrderTreverselRecision(root->left);
            cout << root->val << " ";
            inOrderTreverselRecision(root->right);
        }
    }

    //后序递归遍历
    inline void postOrderTreverselRecision(TreeNode* root) {
        if (NULL != root) {
            postOrderTreverselRecision(root->left);
            postOrderTreverselRecision(root->right);
            cout << root->val << " ";
        }
    }

    //前序非递归遍历
    inline vector<int> preOrderTraversel(TreeNode* root) {
        vector<int> vector_preOrder;
        stack<TreeNode*> stack_preOrder;

        if (root == NULL) {
            return vector_preOrder;
        }
        
        TreeNode* pNode = root;
        while(pNode || !stack_preOrder.empty()){
            if (pNode != NULL) {
                vector_preOrder.push_back(pNode->val);
                stack_preOrder.push(pNode);
                pNode = pNode->left;
            }
            else {
                pNode = stack_preOrder.top();
                stack_preOrder.pop();
                pNode = pNode->right;
            }
        }

        return vector_preOrder;
    }

    //中序非递归遍历
    inline vector<int> inOrderTraversel(TreeNode* root) {
        
        vector<int> vector_inOrder;
        stack<TreeNode*> stack_inOrder;

        if (root == NULL) {
            return vector_inOrder;
        }

        TreeNode* pNode = root;
        while (pNode || !stack_inOrder.empty()) {
            if (pNode) {
                stack_inOrder.push(pNode);
                pNode = pNode->left;
            }
            else {
                pNode = stack_inOrder.top();
                stack_inOrder.pop();

                vector_inOrder.push_back(pNode->val);

                pNode = pNode->right;
            }
        }
        return vector_inOrder;

    }

    //后序非递归遍历
    vector<int> postOrderTraversel(TreeNode* root) {
        vector<int> vector_postOrder;
        stack<TreeNode*> stack_postOrder;

        if (root == NULL) {
            return vector_postOrder;
        }

        TreeNode* pNode = root;
        TreeNode* r = NULL;
        while (pNode || !stack_postOrder.empty()) {
            if (pNode) {
                stack_postOrder.push(pNode);
                pNode = pNode->left;
            }
            else {
                pNode = stack_postOrder.top();
                if (pNode->right != NULL && pNode->right != r) {
                    pNode = pNode->right;
                    stack_postOrder.push(pNode);
                    pNode = pNode->left;
                }
                else {
                    stack_postOrder.pop();
                    vector_postOrder.push_back(pNode->val);
                    r = pNode;
                    pNode = NULL;
                }
            }
        }
        return vector_postOrder;
    }

    //层次遍历
    vector<int> levelTraversel(TreeNode* root) {
        vector<int> vector_level;
        queue<TreeNode*> queue_level;

        if (root == NULL) {
            return vector_level;
        }
        
        queue_level.push(root);
        TreeNode* pNode = NULL;
        while (!queue_level.empty()) {
            pNode = queue_level.front();
            queue_level.pop();
            vector_level.push_back(pNode->val);
            if(pNode->left) queue_level.push(pNode->left);
            if (pNode->right) queue_level.push(pNode->right);
        }

        return vector_level;
    }


    int kthSmallest(TreeNode* root, int k) {
        vector<int> small = levelTraversel(root);
        sort(small.begin(),small.end());
        return small.at(k-1);
    }
};

 
int main()
{
    Solution s;
    vector<int> valTree = { 5,3,6,2,4,1 };
    TreeNode* root = NULL;
    for (auto& itemVal : valTree) {
        root = s.build(root, itemVal);
    }

    cout << "level Traversel" << endl;
    vector<int> traversel = s.levelTraversel(root);
    for (auto& itemVal : traversel) {
        cout << itemVal << " ";
    }
    cout << endl;

    cout << "pre Order Traversel" << endl;
    traversel = s.preOrderTraversel(root);
    for (auto& itemVal : traversel) {
        cout << itemVal << " ";
    }
    cout << endl;

    cout << "in Order Traversel" << endl;
    traversel = s.inOrderTraversel(root);
    for (auto& itemVal : traversel) {
        cout << itemVal << " ";
    }
    cout << endl;

    cout << "post Order Traversel" << endl;
    traversel = s.postOrderTraversel(root);
    for (auto& itemVal : traversel) {
        cout << itemVal << " ";
    }
    cout << endl;

    cout << "pre Order Treversel Recision" << endl;
    s.preOrderTreverselRecision(root);
    cout << endl;
    cout << "in Order Treversel Recision" << endl;
    s.inOrderTreverselRecision(root);
    cout << endl;
    cout << "post Order Treversel Recision" << endl;
    s.postOrderTreverselRecision(root);
    cout << endl;
}

