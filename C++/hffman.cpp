#include<bits/stdc++.h>
using namespace std;

struct Node{
    char n;
    int f;
    Node* l;
    Node* r;
};
struct compare{
    bool operator()(Node* n1,Node* n2){
        return n1->f>n2->f;
    }
};
Node* haffman(char lt[],int fr[],int n){
    priority_queue<Node*,vector<Node*>,compare> pq;

    for(int i=0;i<n;i++){
        Node *node = new Node();
        node->l = NULL;
        node->r = NULL;
        node->n = lt[i];
        node->f = fr[i];
        pq.push(node);
    }
    for(int i=0;i<n-1;i++){
        Node* x = pq.top();
        pq.pop();
        Node* y = pq.top();
        cout<<x->n<<" "<<x->f<<" "<<y->n<<" "<<y->f<<endl;
        pq.pop();
        Node* z = new Node();
        z->l = x;
        z->r = y;
        z->f = x->f + y->f;
        z->n = '\0';
        pq.push(z);
    }
    return pq.top();
}
/**
nodeTraverse(root,str){
    if(root->l == NULL && root->r==NULL){
        cout<<str<<endl;
    }
    if(root->l != NULL && root->r!=NULL){
        str1 = nodeTraverse(root->l,0)
        str2 = nodeTraverse(root->r,1)
        return str1+str2;
    }
    return str;
}*/
int main(){
    char letter[] = {'a','b','c','d','e'};
    int freq[] = {20,12,10,8,30};
    int n = sizeof(freq)/sizeof(freq[0]);
    Node* node = haffman(letter,freq,n);
    cout<<node->f<<endl;
    return 0;
}
