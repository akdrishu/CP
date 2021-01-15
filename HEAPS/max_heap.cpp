//
// Created by INCOMPETENT CODER on 12-01-2021
//
#include "bits/stdc++.h"

using namespace std;
typedef long long int obs;
#define debug(...) cout<< " [" << #__VA_ARGS__ ": " << (__VA_ARGS__) << "] " ;

obs bin_search(obs a[], obs lb, obs ub, obs item) {
    while (lb <= ub) {
        obs mid = lb + (ub - lb) / 2;
        if (a[mid] == item) return mid;
        if (a[mid] > item) ub = mid - 1;
        else lb = mid + 1;
    }
    return -1;
}

obs power(obs x, obs y) {
    obs res = 1;
    while (y > 0) {
        if (y & 1)
            res = res * x;

        y = y >> 1;
        x = x * x;
    }
    return res;
}

obs powerp(obs x, obs y, obs p) {
    obs res = 1;
    x = x % p;
    if (x == 0) return 0;
    while (y > 0) {
        if (y & 1)
            res = (res * x) % p;

        y = y >> 1; // y = y/2
        x = (x * x) % p;
    }
    return res;
}

void solve() {
}
class node{
public:
    int data;
    node *left, *right;
    node(int x){
        data=x;
        left=right=NULL;
    }
};
void inorder(node *root){
    stack<node *> temp;
    while(root || !temp.empty()){
        while(root) {
            temp.push(root);
            root = root->left;
        }
        root= temp.top();
        temp.pop();
        cout<<root->data<<" ";
        root=root->right;
    }
}
void preorder(node *root){
    stack<node*> temp;
    while(root){
        cout<<root->data<<" ";
        if(root->right)
            temp.push(root->right);
        root = root->left;
        if(!root and !temp.empty()){
            root = temp.top(), temp.pop();
        }
    }
}
int main() {
    node *root= new node(1);
    root->left= new node(2);
    root->right= new node(3);
    root->left->left= new node(4);
    root->right->left= new node(5);
    inorder(root);
//    preorder(root);
//    obs tt;
//    cin >> tt;
//    while (tt--) {
//        solve();
//    }
}

