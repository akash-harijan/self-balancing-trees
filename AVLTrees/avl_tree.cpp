//============================================================================
// Name        : assignment_5.cpp
// Author      : AKASH (14-1629)
// Version     : C++
// Copyright   : Your copyright notice
// Description : Hello World in C, Ansi-style
//============================================================================

# include <iostream>

using namespace std;

struct Node
{
    int data;
    struct Node* left;
    struct Node* right;
    int ht;
};

class AvlTree{
	private:
		Node * root;
	public:
		AvlTree();
		~AvlTree();
		Node * RotateLL(Node *);
		Node * RotateRR(Node *);
		Node * RotateLR(Node *);
		Node * RotateRL(Node *);
		Node * Insert(Node * ,int );
		Node * Delete();
		Node *& getRoot();
		int Height(Node *);
		int height(Node *);
		void inOrder(Node *);
		void Delete(int );
		void deleteNode(Node *&,int);
		Node * search(int);
};
AvlTree :: AvlTree(){
	root=NULL;
}
AvlTree:: ~AvlTree(){
	delete root;
}
int AvlTree :: Height(Node * Root){
	if (!Root)
		return -1;
	int l=Height(Root->right);
	int r=Height(Root->left);
	return (l>r)? l+1: r+1;
}
Node *& AvlTree:: getRoot(){
	return root;
}

void AvlTree :: inOrder(Node * Root ){
	if (!Root)
		return;
	inOrder(Root->left);
	cout<<Root->data<<" "<<Root->ht<<endl;
	inOrder(Root->right);
}
Node * AvlTree :: RotateLL(Node * a){
	Node * b=a->left;
    	a->left=b->right;
    	b->right=a;
    	a->ht=Height(a);
    	b->ht=Height(b);
    	return b;
}
Node * AvlTree :: RotateRR(Node * a){
    	Node * b=a->right;
   	a->right=b->left;
   	b->left=a;
    	a->ht=Height(a);
    	b->ht=Height(b);
    	return b;
}

Node * AvlTree :: RotateLR(Node * a){
    	a->left=RotateRR(a->left);
    	return RotateLL (a);
}
Node * AvlTree :: RotateRL(Node * a){
    	a->right=RotateLL(a->right);
    	return RotateRR(a);
}
int AvlTree :: height(Node * a){
    	if (!a)
    	    return -1;
    	return a->ht;
}	
Node * AvlTree :: Insert(Node * Root,int val)
{

    	if (!Root){
    	    Node * newNode = new Node;
    	    newNode->left=newNode->right=NULL;
    	    newNode->ht=0;
    	    newNode->data=val;
    	    if (this->root==NULL){
    	    	root=newNode;
    	    	return root;
    	    }
    	    return newNode;
    	}
   	if ( val < Root->data){
		
	       Root->left=Insert(Root->left,val);
	       if (height(Root->left)-height(Root->right) == 2){
	           if (val > Root->left->data)
	                Root=RotateLR(Root);
	           else
		        Root=RotateLL(Root);
       		}
   	}
   	else {
   	    
   	    Root->right=Insert(Root->right,val);
		
	       if (height(Root->right) - height(Root->left)==2 ){
		
	           if ( val > Root->right->data)
	              Root= RotateRR(Root);
	           else
	              Root=RotateRL(Root);
	       }
	   }
	Root->ht=(height(Root->left) > height(Root->right) )? 	height(Root->left)+1: height(Root->right)+1;
return Root;
}
void AvlTree :: Delete(int val){
	if(!root){
		cout<<"No value in tree\n";
	}
		
	Node * current=root;
	while(current && current->data!=val ){
		if (val > current->data	)
			current=current->right;
		else
			current=current->left;
	}
	if (!current){
		cout<<endl<<val<<" does not exist in tree\n";
		return;
	}
	if (current->right && current->left){
		Node * current2=current->right;
		while(current2->left)
			current2=current2->left;
		cout<<current2->data<<endl;
		int temp=current2->data;	
		Delete(current2->data);
		//search(current->data)->data=temp;	
		current->data=temp;	
	
	}	
	deleteNode (root,val);
}	

void AvlTree :: deleteNode (Node *& Root,int val){
	
	if (!Root)
		return;
	if (Root->data==val){
		if (!Root->left && !Root->right){
			delete Root;
			Root=NULL;
		}
		else if (Root->left){
			Node * temp=Root;
			Root=Root->left;
			delete temp;
		}
		else{
			Node * temp=Root;
			Root=Root->right;
			delete temp;
		}
		return;
	}
	if (val > Root->data){
		deleteNode (Root->right,val);
		if (height(Root->left)-height(Root->right) ==2){
			if (height(Root->left->right) > height(Root->left->left) )
				Root=RotateLR(Root);
			else
				Root=RotateLL(Root);	        	
		}

	}
	else{
		deleteNode (Root->left,val);
		if (height(Root->right) - height(Root->left)==2 ){
	        if (height(Root->right->left) > height(Root->right->right) )
				Root=RotateRL(Root);
			else
				Root=RotateRR(Root);
	       }
	}
Root->ht=(height(Root->left) > height(Root->right) )? 	height(Root->left)+1: height(Root->right)+1;
return;
}
Node * AvlTree :: search(int key){
	Node * current=root;
	while (current){
	
		if (key==current->data)
			return current;	
		if (key > current->data)
			current=current->right;
		else
			current=current->left;
	}
return 0;
} 		
int main(void) {
	
	int choice=1;
	AvlTree tree;

	int n,num;
	
	while(choice){
		cout<<"Press 1 for Insert\nPress 2 for Delete\nPress 3 for Search key\n";
		cin>>choice;
		if (choice==1){
			cout<<"Enter the total numbers : ";
			cin>>n;
			for (int i=0;i<n;i++){
			cin>>num;			
			tree.getRoot()=tree.Insert(tree.getRoot(),num);
			
			}
		}
		else if (choice==2){
			cin>>num;	
			tree.Delete(num);
		}
		else if (choice==3){
			cin>>num;
			tree.search(num)?cout<<"Present\n":cout<<"Absent\n";			
		}
		cout<<endl;
		tree.inOrder(tree.getRoot());
	}
	
}
