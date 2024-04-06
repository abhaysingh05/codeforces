class Solution{
public:
    int kthCommonAncestor(Node *root, int k, int x, int y){
        Node *curr = root; vector<int> ancestors;
        while (curr){
            ancestors.push_back(curr->data);
            if (curr->data > x && curr->data > y) curr = curr->left;
            else if (curr->data < x && curr->data < y) curr = curr->right;
            else break;
        }
        if (ancestors.size() < k) return -1;
        return ancestors[(int)ancestors.size() - k];
    }
};