#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>
#include <climits>
#include <queue>

using namespace std;

class Node {
    public:
      int data;
      vector<Node*> children;
};

Node *root = NULL;

Node* constructGenericTree(vector<int> &arr) {
    stack<Node*> st;
    for(int i = 0; i < arr.size(); i++) {
        if(arr[i] == -1) {
            st.pop();
        }
        else {
            Node *curr = new Node;
            curr->data = arr[i];
            if(st.empty()) {
                root = curr;
            }
            else {
                st.top()->children.push_back(curr);
            }
            st.push(curr);
        }
    }
    return root;
}

void display(Node *root) {
    string res = to_string(root->data) + " -> ";
    for(Node *child : root->children) {
        res += to_string(child->data) + ", ";
    }
    cout << res << endl;
    for(Node *child : root->children) {
        display(child);
    }
}

int getSizeOfGenericTree(Node *root) {
    int size = 0;
    for(Node *child : root->children) {
        int childSize = getSizeOfGenericTree(child);
        size += childSize;
    }
    return 1 + size;
}

int printMaxValueInGenericTree(Node *root) {
    int maxe = INT_MIN;
    for(Node *child : root->children) {
        int childMax = printMaxValueInGenericTree(child);
        maxe = max(maxe, childMax);
    }
    maxe = max(maxe, root->data);
    return maxe;
}

int printHeightOfGenericTree(Node *root) {
    int height = -1;
    for(Node *child : root->children) {
        int childHeight = printHeightOfGenericTree(child);
        height = max(height, childHeight);
    }
    return 1 + height;
}

void levelOrderTraversal(Node *root) {
    queue<Node*> q;
    q.push(root);
    while(!q.empty()) {
        Node *curr = q.front();
        cout << curr->data << " ";
        q.pop();
        for(Node *child : curr->children) {
            q.push(child);
        }
    }
}

void levelOrderTraversalZigZag(Node *root) {
    queue<Node*> q;
    q.push(root);
    int level = 1;
    while(!q.empty()) {
        int n = q.size();
        vector<int> temp;
        while(n--) {
            Node *curr = q.front();
            q.pop();
            temp.push_back(curr->data);
            for(Node *child : curr->children) {
                q.push(child);
            }
        }
        if(level % 2 == 0) {
            reverse(temp.begin(), temp.end());
        }
        for(int ele : temp) {
            cout << ele << " ";
        }
        cout << endl;
        level++;
    }
}

void invertGenericTree(Node *root) {
    if(root == NULL) {
        return;
    }
    for(Node *child : root->children) {
        invertGenericTree(child);
    }
    reverse(root->children.begin(), root->children.end());
}

Node* removeLeaves(Node* root) {
    if(root == NULL) {
        return NULL;
    }
    if(root->children.size() == 0) {
        delete(root);
        return NULL;
    }
    for(int i = 0; i < root->children.size(); i++) {
        Node *child = root->children[i];
        if(child->children.size() == 0) {
            delete(child);
            // update the parent children vector
            for(int j = i; j < root->children.size() - 1; j++) {
                root->children[j] = root->children[j + 1];
            }
            root->children.pop_back();
            i--;
        }
    }
    for(int i = 0; i < root->children.size(); i++) {
        root->children[i] = removeLeaves(root->children[i]);
    }
    return root;
}

int main() {
    int n;
    cin >> n;
    vector<int> arr(n);
    for(int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    root = constructGenericTree(arr);
    cout << "Tree Structure:\n\n";
    display(root);
    cout << endl;
    cout << "Number of Nodes in the Tree: " << getSizeOfGenericTree(root);
    cout << endl << endl;
    cout << "Max value of the Node in the Tree: " << printMaxValueInGenericTree(root);
    cout << endl << endl;
    cout << "Height of the Tree in terms of Edges: " << printHeightOfGenericTree(root);
    cout << endl << endl;
    cout << "Level Order Traversal:\n\n";
    levelOrderTraversal(root);
    cout << endl << endl;
    cout << "Level Order Traversal ZigZag:\n\n";
    levelOrderTraversalZigZag(root);
    cout << endl << endl;
    cout << "Inverted Generic Tree:\n\n";
    invertGenericTree(root);
    display(root);
    cout << endl << endl;
    cout << "Tree After Removing Leaf Nodes:\n\n";
    root = removeLeafs(root);
    display(root);
    return 0;
}