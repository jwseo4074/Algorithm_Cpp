#include <iostream>
using namespace std;
struct Node {
	char node;
	Node* left;
	Node* right;
	Node(char n, Node* l=nullptr, Node* r=nullptr) {
		node = n;
		left = l;
		right = r;  }
};
int get_root_idx(string in,char r) {
	for(int i=0;i<in.size();++i)
		if(in[i]==r) return i;
}
Node* get_pre(string in, string post) {
	if(in=="") return nullptr;
	char root = post[post.size()-1];
	int root_idx = get_root_idx(in,root);
	string in_l = in.substr(0,root_idx);
	string in_r = in.substr(root_idx+1);
	string post_l = post.substr(0,in_l.size());
	string post_r = post.substr(in_l.size(),in_r.size());
	return new Node(root, get_pre(in_l,post_l),get_pre(in_r,post_r));
}
Node* get_post(string in, string pre) {
	if(in=="") return nullptr;
	char root=pre[0];
	int root_idx=get_root_idx(in,root);
	string in_l=in.substr(0,root_idx);
	string in_r=in.substr(root_idx+1);
	string pre_l=pre.substr(1,in_l.size());
	string pre_r=pre.substr(1+in_l.size(),in_r.size());
	return new Node(root,get_post(in_l,pre_l),get_post(in_r,pre_r));
}
void pre_trv(Node* node) {
	if(node == nullptr) return;
	cout<<node->node;
	pre_trv(node->left);
	pre_trv(node->right);
}
void post_trv(Node* node) {
	if(node == nullptr) return;
	post_trv(node->left);
	post_trv(node->right);
	cout<<node->node;
}
int main(void) {
	string s1, s2;
	string str1, str2;
	Node* root;
	cin >> str1 >> s1 >> str2 >> s2;
	if(str1=="Inorder"){
        if(str2=="Preorder") {
            root=get_post(s1, s2);
            cout<<"Postorder ";
            post_trv(root);}
        else {
            root=get_pre(s1, s2);
            cout<<"Preorder ";
            pre_trv(root);  }
	}
	else {
        if(str1=="Preorder") {
            root=get_post(s2, s1);
            cout<<"Postorder ";
            post_trv(root); }
        else {
            root=get_pre(s2, s1);
            cout<<"Preorder ";
            pre_trv(root);  }
	}
	cout << endl;
	return 0;
}
