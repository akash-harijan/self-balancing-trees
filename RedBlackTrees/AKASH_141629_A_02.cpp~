
//============================================================================
// Name        : AKASH_141629_A_02
// Author      : AKASH (14-1629)
// Version     : C++
// Copyright   : Your copyright notice
// Description : Hello World in C, Ansi-style
//============================================================================

# include <iostream>

using namespace std;

enum color{Red,Black,doubleBlack};

struct Node{
	Node * left;
	Node * right;
	Node * parent;
	int data;
	int color;
};

class RBTree{
	
	private:
		Node * root;
	public:
		RBTree();
		~RBTree();
		Node * RotateRR(Node *);
		Node * RotateRR2(Node *);
		Node * RotateLL(Node *);
		Node * RotateLL2(Node *);
		Node * RotateRL(Node *);
		Node * RotateLR(Node *);
		Node *& getSibling (Node *);
		Node * getUncle(Node *);
		Node *& getRoot();
		int getColor(Node *);
		void Insert( int );
		void CheckError(Node *, int);	
		void InsertNode(Node * , int);
		void inOrder(Node * );
		void Delete(Node *&, int );
		void changeDoubleBlack(Node * );
};

RBTree :: RBTree(){
	root=NULL;
}
RBTree :: ~RBTree(){
	delete root;
}
Node *& RBTree :: getRoot(){
	return root;
}
int RBTree :: getColor(Node * Root){
	if (!Root)
		return Black;
	return Root->color;
}
Node *& RBTree :: getSibling(Node * Root){
	if (!Root)
		return Root;
	if (Root==this->root){
		if (Root->color==doubleBlack)
			Root->color=Black;
		return Root;
	}
	if (!Root->parent)
		return Root;
	if (Root->parent->left==Root)
		return Root->parent->right;
	return Root->parent->left;
}

	
void RBTree :: inOrder(Node * Root){
	if (!Root)
		return;
	inOrder(Root->left);
	cout<<Root->data<<" ";
	if (Root->color==Red)cout<<"Red\n";
	else if (Root->color==Black)cout<<"Black\n";
	else cout<<"Double Black\n";
	inOrder(Root->right);
	
}

Node * RBTree :: getUncle(Node * Root){
	
	if (Root==this->root)
		return NULL;
	if ( Root->parent==this->root)
		return NULL;
	if (Root->parent->parent->left==Root->parent)
		return Root->parent->parent->right;
	return Root->parent->parent->left;

}
Node * RBTree :: RotateRR(Node * a){
	
	Node * b=a->right;	
	a->color=Red;
	b->color=Black;
	a->right=b->left;
	if (b->left)
		b->left->parent=a;
	b->left=a;
	b->parent=a->parent;
	a->parent=b;
	return b;
}

Node * RBTree :: RotateRR2(Node * a){
	
	Node * b=a->right;
	a->right=b->left;
	if (b->left)
		b->left->parent=a;
	b->left=a;
	b->parent=a->parent;
	a->parent=b;
	return b;
}
Node * RBTree :: RotateLL (Node * a){

	Node * b=a->left;	
	a->color=Red;
	b->color=Black;
	a->left=b->right;
	if (b->right)
		b->right->parent=a;
	b->right=a;
	b->parent=a->parent;
	a->parent=b;
	return b;
}

Node * RBTree :: RotateLL2 (Node * a){

	Node * b=a->left;	
	a->left=b->right;
	if (b->right)
		b->right->parent=a;
	b->right=a;
	b->parent=a->parent;
	a->parent=b;
	return b;
}

Node * RBTree :: RotateRL(Node * a){

	a->right=RotateLL(a->right);
	return RotateRR(a);
}

Node * RBTree :: RotateLR(Node * a){

	a->left=RotateRR(a->left);
	return RotateLL(a);
}

void RBTree :: Insert (int val){

	Node * newNode=new Node;
	newNode->left=newNode->right=newNode->parent=NULL;
	newNode->color=Red;
	newNode->data=val;
	
	if (!root){	
		newNode->color=Black;
		root=newNode;
		return;
	}
	Node * curr=root;
	while(1){
		if (val > curr->data){
			if (!curr->right){
				newNode->parent=curr;
				curr->right=newNode;
				break;
			}
			curr=curr->right;
		}
		else{
			if ( !curr->left){
				newNode->parent=curr;
				curr->left=newNode;
				break;
			}
			curr=curr->left;
		}		
	}
	InsertNode(root,val);
}
void RBTree :: CheckError(Node * curr, int val){

	if (curr->color==Red  && (getColor(curr->left)==Red || getColor(curr->right)==Red) ){
		if ( getColor(getSibling(curr))==Black){
			if (curr->parent->left==curr){
				if ( curr->left && curr->left->data >= val){
					if (curr->parent==this->root)
						root=RotateLL(root);
					else{
						if (val > curr->parent->parent->data){
							Node *& saved=curr->parent->parent->right;
							saved=RotateLL(curr->parent);
						}
						else{
							Node *&saved=curr->parent->parent->left;
							saved=RotateLL(curr->parent);
						}
					}				
				}				
				else if (curr->right->data <= val){
					if (curr->parent==this->root)
						root=RotateLR(root);
					else{
						if ( val > curr->parent->parent->data){
							Node *& save=curr->parent->parent->right;
							save=RotateLR(curr->parent);
						}
						else{
							Node *&save=curr->parent->parent->left;
							save=RotateLR(curr->parent);
						}
						
					}				
				}
			}	
			else if ( curr->parent->right==curr){
				if ( curr->right && curr->right->data <= val){
					if (curr->parent==this->root)
						root=RotateRR(root);
					else{
						if (val > curr->parent->parent->data){
							Node *& saved=curr->parent->parent->right;
							saved=RotateRR(curr->parent);							
						}
						else{
							Node *&saved =curr->parent->parent->left;
							saved =RotateRR(curr->parent);
						}
					}
				}
				else if ( curr->left && curr->left->data >= val){
					if (curr->parent==this->root)
						root=RotateRL(root);
					else{
						if( val > curr->parent->parent->data){
							Node *& save=curr->parent->parent->right;
							save=RotateRL(curr->parent);
						}
						else{
							Node *& save=curr->parent->parent->left;
							save=RotateRL(curr->parent);
						}
					}
				}		
			}
		}
	}
}

void RBTree :: Delete (Node*& Root, int val){

	if (!Root){
		cout<<"Entered Value does not exist in Tree\n";
		return;
	}
	
	if (Root->data==val){
		if (!Root->left && !Root->right){
			
			if (Root->color==Red ){
				
				delete Root;
				Root=NULL;
				
			}
			else{
				
				Root->color=doubleBlack;
				changeDoubleBlack(Root);
				delete Root;
				Root=NULL;
			}
		}
		else if (Root->left && !Root->right){
			
			if ( ( getColor(Root)==Red && getColor(Root->left)==Black)||
			     ( getColor(Root)==Black && getColor(Root->left)==Red) ){
				Node * temp=Root;
				Root=Root->left;
				delete temp;
				Root->color=Black;
				return;	
			}
			else{
				Node * temp=Root;
				Root=Root->left;
				delete temp;
				Root->color=doubleBlack;
				changeDoubleBlack(Root);
			}
		}
		else if (Root->right && !Root->left){
			
			if ( ( getColor(Root)==Red && getColor(Root->right)==Black) || 
			     ( getColor(Root)==Black && getColor(Root->right)==Red) ){
				Node * temp=Root;
				Root=Root->right;
				delete temp;
				Root->color=Black;
				return;
	
			}	
			else{

				Node * temp=Root;
				Root=Root->right;
				delete temp;
				Root->color=doubleBlack;
				changeDoubleBlack(Root);
			}	
		}
		else if (Root->left && Root->right){
			
			Node * temp=Root;
			temp=temp->left;
			
			while(temp->right){				
				temp=temp->right;
			}
			
			int save=temp->data;
			Delete (root,save);  // Mehtab ri error mon wat ase kabardar rahe hoshyar rahe			
			if (Root->data==val)
				Root->data=save;
			else if (Root->left && Root->left->data==val)			
				Root->left->data=save;
			else if (Root->right && Root->right->data==val)
				Root->right->data=save;
				
		}
	
	}
	else if (val > Root->data)
		Delete(Root->right,val);	
	else if (val < Root->data)
		Delete(Root->left,val);
	
}

void RBTree :: changeDoubleBlack(Node * u){
	
	if (u==this->root){
		u->color=Black;
		return;
	}
	else if (u->parent->left==u){
			
		if (getColor(getSibling(u))==Red){
			
			if (u->parent==this->root)
				this->root=RotateRR(this->root);
			else{
				if (u->parent->parent->left==u->parent){
					Node *& save=u->parent->parent->left;
					save=RotateRR(u->parent);
				}
				else{
					Node *& save=u->parent->parent->right;
					save=RotateRR(u->parent);
				}			
			}
		}
		if (getColor(getSibling(u))==Black && getColor(getSibling(u)->right)==Black && getColor(getSibling(u)->left)==Black ){
			
			u->color=Black;
			getSibling(u)->color=Red;
			if (u->parent->color==Red){
				u->parent->color=Black;
				return;
			}
			u->parent->color=doubleBlack;
			u=u->parent;
			changeDoubleBlack(u);
		}
		if ( getColor(getSibling(u))==Black && getColor(getSibling(u)->left)==Red && getColor(getSibling(u)->right)==Black){
						
			getSibling(u)=RotateLL(getSibling(u));
		}
		if (getColor(getSibling(u))==Black && getColor(getSibling(u)->right)==Red){
						
			int temp=u->parent->color;
			u->parent->color=getSibling(u)->color;
			getSibling(u)->color=temp;

			getSibling(u)->right->color=Black;
			if (u->parent==this->root){
				root=RotateRR2(this->root);
			}
			else{		
	
				if (u->parent->parent->left==u->parent){
					Node *& save=u->parent->parent->left;
					save=RotateRR2(u->parent);
				}
				else{
					Node *& save=u->parent->parent->right;
					save=RotateRR2(u->parent);
				}
			}
			u->color=Black;
			return;
		}
	}
	else if (u->parent->right==u){
	
		if (getColor(getSibling(u))==Red){
			
			if (u->parent==this->root)
				this->root=RotateLL(this->root);
			else{
				if (u->parent->parent->left==u->parent){
					Node *& save=u->parent->parent->left;
					save=RotateLL(u->parent);
				}
				else{
					Node *& save=u->parent->parent->right;
					save=RotateLL(u->parent);
				}			
			}
		}
		if (getColor(getSibling(u))==Black && getColor(getSibling(u)->left)==Black && getColor(getSibling(u)->right)==Black ){
			
			u->color=Black;
			getSibling(u)->color=Red;
			if (u->parent->color==Red){
				u->parent->color=Black;
				return;
			}
			u->parent->color=doubleBlack;
			u=u->parent;
			changeDoubleBlack(u);
		}
		if ( getColor(getSibling(u))==Black && getColor(getSibling(u)->right)==Red && getColor(getSibling(u)->left)==Black){
			
			getSibling(u)=RotateRR(getSibling(u));
			inOrder(getSibling(u));
		}
		if (getColor(getSibling(u))==Black && getColor(getSibling(u)->left)==Red){			
			int temp=u->parent->color;
			u->parent->color=getSibling(u)->color;
			getSibling(u)->color=temp;

			getSibling(u)->left->color=Black;
			
			if (u->parent->parent->left==u->parent){
				Node *& save=u->parent->parent->left;
				save=RotateLL2(u->parent);
			}
			else{
				Node *& save=u->parent->parent->right;
				save=RotateLL2(u->parent);
			}
			u->color=Black;
			return;
		}

	}
}
void RBTree :: InsertNode(Node * Root, int val){

	if (Root->data==val)
		return;
	if (val > Root->data){
		InsertNode(Root->right,val);
		if (Root==this->root){
			Root->color=Black;
			return;
		}			
		CheckError(Root,val);		
		if (Root->color==Red && getColor(Root->right)==Red){
			if (getSibling(Root)->color==Red){
				Root->color=Black;
				getSibling(Root)->color=Black;
				Root->parent->color=Red;
			}			
		}
	}
	else{
		InsertNode(Root->left,val);
		if (Root==this->root){
			Root->color=Black;
			return;
		}		
		CheckError(Root,val);				
		if (Root->color==Red && getColor(Root->left)==Red){
			if (getSibling(Root)->color==Red){
				Root->color=Black;
				getSibling(Root)->color=Black;
				Root->parent->color=Red;
			}
		}		
	}
}

int main(){

	int choice=1;
	RBTree tree;

	int n,num;
	
	while(choice){
		cout<<"Press 1 for Insert\nPress 2 for Delete\n";
		cin>>choice;
		if (choice==1){
			cout<<"Enter the total numbers : ";
			cin>>n;
			for (int i=0;i<n;i++){
			cin>>num;			
			tree.Insert(num);
			}
		}
		else if (choice==2){
			cin>>num;	
			tree.Delete(tree.getRoot(),num);

		}
		
		cout<<endl;
		tree.inOrder(tree.getRoot());
	}
}

