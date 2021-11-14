#include <bits/stdc++.h>

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
            // left shifting all values
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

bool findElement(Node* root, int val) {
    if(root->data == val) {
        return true;
    }
    else {
        for(Node *child : root->children) {
            bool found = findElement(child, val);
            if(found == true) {
                return true;
            }
        }
    }
    return false;
}

vector<int> nodeToRootPath(Node* root, int val) {
    if(root->data == val) {
        return {root->data};
    }
    for(Node *child : root->children) {
        vector<int> pathToVal = nodeToRootPath(child, val);
        if(pathToVal.size() > 0) {
            pathToVal.push_back(root->data);
            return pathToVal;
        }
    }
    return {};
}

int lca(Node* root, int val1, int val2) {
    vector<int> path1 = nodeToRootPath(root, val1);
    vector<int> path2 = nodeToRootPath(root, val2);
    int i = path1.size() - 1;
    int j = path2.size() - 1;
    while(i >= 0 && j >= 0 && path1[i] == path2[j]) {
        i--;
        j--;
    }
    i++;
    j++;
    return path1[i];
}

int distanceBetweenNodes(Node* root, int val1, int val2) {
    vector<int> path1 = nodeToRootPath(root, val1);
    vector<int> path2 = nodeToRootPath(root, val2);
    int i = path1.size() - 1;
    int j = path2.size() - 1;
    while(i >= 0 && j >= 0 && path1[i] == path2[j]) {
        i--;
        j--;
    }
    i++;
    j++;
    return i + j;
}

bool areSimilar(Node* root1, Node* root2) {
    if(root1->children.size() != root2->children.size()) {
        return false;
    }
    int n = root1->children.size();
    for(int i = 0; i < n; i++) {
        Node *child1 = root1->children[i];
        Node *child2 = root2->children[i];
        if(areSimilar(child1, child2) == false) {
            return false;
        }
    }
    return true;
}

bool areMirrorImage(Node* root1, Node* root2) {
    if(root1->children.size() != root2->children.size()) {
        return false;
    }
    int n = root1->children.size();
    for(int i = 0; i < n; i++) {
        Node *child1 = root1->children[i];
        Node *child2 = root2->children[n - 1 - i];
        if(areMirrorImage(child1, child2) == false) {
            return false;
        }
    }
    return true;
}

bool isSymmetric(Node* root) {
    return areMirrorImage(root, root);
}

Node* pre = NULL;
Node* suc = NULL;
int state = 0;

void findPredecessorAndSuccessor(Node* root, int val) {
    if(state == 0) {
        if(root->data == val) {
            state = 1;
        }
        else {
            pre = root;
        }
    }
    else if(state == 1) {
        suc = root;
        state = 2;
        return;
    }
    for(Node *child : root->children) {
        findPredecessorAndSuccessor(child, val);
    }
}

int ceilVal = INT_MAX;
int floorVal = INT_MIN;

void findCeilAndFloorValues(Node* root, int val) {
    if(node->data > data) {
        ceilVal = min(ceilVal, node->data);
    }
    if(node->data < data) {
        floorVal = max(floorVal, node->data);
    }
    for(Node *child : root->children) {
        findCeilAndFloorValues(child, val);
    }
}

void findKthLargestElement(Node* root, int k) {
    
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
    return 0;
}