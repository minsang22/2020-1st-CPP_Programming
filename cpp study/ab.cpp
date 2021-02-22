#include <iostream>
#include <cstring>
#include <stdio.h>

using namespace std;

char prec[4][2] = { '*',2,'/',2,'+',1,'-',1 };

struct Node {
    char data;
    int prio;
    Node *left;
    Node *right;
    Node(char data) {
        this -> data = data;
        prio = 4;
        left = NULL;
        right = NULL;
    }
};

class Tree {
public:
    Tree();
    ~Tree();
    bool isDigit(int value);
    bool isEmpty();
    void buildTree(char value);
    void insertOperand(Node *p);
    void insertOperator(Node *p);
    void inorder(Node *p); 
    void callInorder(); 
   void preorder(Node *p); 
    void callPreorder(); 
    void postorder(Node *p); 
    void callPostorder(); 
    void expression(Node *p); 
    void callExpression(); 
    int evaluation(Node *p); 
    int callEvaluation(); 
private:
    Node *root;
};

Tree::Tree() { 
     root = NULL;
 } 
 
 
Tree::~Tree() { 
    delete root; 
} 
 
bool Tree::isDigit(int value) { 
    if (value == 4) {
        return true;
    } 
    else {
        return false;
    } 
}
 
bool Tree::isEmpty() { 
    if (root == NULL) {
        return true;
    }
    else {
        return false;
    } 
} 
 
void Tree::buildTree(char value) {
    Node *temp = new Node(value);

    for (int i = 0; i < 4; i++) {
        if (temp -> data == prec[i][0]) {
            temp -> prio = prec[i][1] - '0';
            break;
        }
        else {
                temp -> prio = 4;
        }
    }
    if (isDigit(temp -> prio)) {
        insertOperand(temp); 
    }
    else {
        insertOperator(temp);
    }
} 
void Tree::insertOperand(Node *poi) {
    if (isEmpty()) {
        root = poi;
    }
    else {
        Node *p = root; 
        while (p -> right != NULL) {
            p = p -> right;
        }
        p -> right = poi;
    }
}

 
void Tree::insertOperator(Node *p) {
    if (root -> prio >= p -> prio) {
        p -> left = root;
        root = p;
    } 
    else {
        p -> left = root -> right;
        root -> right = p;
    }
}
void Tree::inorder(Node *p) {
    if (p) {
        inorder(p -> left);
        cout << p -> data << " ";
        inorder(p -> right);
    }
}
 
void Tree::callInorder() { 
    inorder(root); 
} 
 
 
void Tree::preorder(Node *p) {
    if (p) {
        cout << p -> data << " ";
        preorder(p -> left);
        preorder(p -> right);
    }
}
 
void Tree::callPreorder() {
    preorder(root); 
}
 
void Tree::postorder(Node *p) {
    if (p) {
        postorder(p -> left);
        postorder(p -> right);
        cout << p -> data << " "; 
    } 
}
void Tree::callPostorder() {
    postorder(root); 
}
 
void Tree::expression(Node *p) {
    if (p) {
        if (!isDigit(p -> prio)) {
            cout << "( ";
        }
        expression(p -> left);
        cout << p -> data << " ";
        expression(p -> right);
        if (!isDigit(p -> prio)) {
            cout << ") "; 
        }
    }
}
void Tree::callExpression() {
    expression(root);
}
int Tree::evaluation(Node *p) {
    int value, left, right;
    if (p) {
        if (isDigit(p -> prio)) {
            value = p -> data - '0'; 
        }
        else {
            left = evaluation(p -> left);
            right = evaluation(p -> right);
            switch (p -> data) {
                case '+':
                    value = left + right;
                    break; 
                case '-':
                    value = left - right;
                    break;
                case '*':
                    value = left * right;
                    break;
                case '/':
                    value = left / right;
                    break;
            }
        }
    }
    else {
        cout << "Tree is empty" << endl;
        return 0;
    }
    return value; 
}
int Tree::callEvaluation() {
    return evaluation(root);
}
int main() {
    Tree tree;
    char data[100];
    cout << "Infix Expression : ";
    cin >> data;
    int len = strlen(data);
    for (int i = 0; i < len; i++) {
        tree.buildTree(data[i]);
    }
    cout << endl;
    cout << "Expression : ";
    tree.callExpression();
    cout << endl;
    cout << "inorder : ";
    tree.callInorder();
    cout << endl;
    cout << "postorder : ";
    tree.callPostorder();
    cout << endl;
    cout << "preorder : ";
    tree.callPreorder();
    cout << endl;
    cout << "Evaluation : ";
    cout << tree.callEvaluation();
    cout << endl;
    return 0;
} 