#include<iostream>
using namespace std;
class node
{
	int data;
	node *left;
	node *right;
	public:
	friend class BinarySearchTree;
	node()
	{
		data=0;
		left=NULL;
		right=NULL;
	}
	
};

class BinarySearchTree
{
	node *root;
	int count=0;
	public:
	BinarySearchTree()
	{
		root=NULL;
	}
	void insert();
	node *getroot()
	{
		return root;
	}
	void inorder(node *t);
	void postorder(node *t);
	void preorder(node *t);
	void search();
	void minimum();
	void maximum();
	int depth(node *t);
	void mirror(node *t);
	void remove();
};

int main()
{
	BinarySearchTree b;
	int h;
	int choice;
	do
	{
		cout<<"\n1.insert()\n2.inorder()\n3.postorder\n4.preorder()\n5.search()\n6.minimun()\n7.maximum()\n8.depth()\n9.mirror\n10.delete\n";
		cin>>choice;
		switch(choice)
		{
			case 1:
				b.insert();
				break;
			case 2:
				node *n;
				n=b.getroot();
				b.inorder(n);
				break;
			case 3:
				//node *n;
				n=b.getroot();
				b.postorder(n);
				break;
			case 4:
				n=b.getroot();
				b.preorder(n);
				break;
			case 5:
				b.search();
				break;
			case 6:
				b.minimum();
				break; 
			case 7:
				b.maximum();
				break;
			case 8:
				n=b.getroot();
				h=b.depth(n);
				cout<<"Height:"<<h<<endl;
				break;
			case 9:
				n=b.getroot();
				b.mirror(n);
				break;
			case 10:
				b.remove();
				break;
			default:
				cout<<"invalid choice"<<endl;
		}
	}while(choice!=0);
}

void BinarySearchTree::insert()
{
	//cout<<"Function call";
	node *t,*p;
	p=root;
	t=new node();
	//int element;
	cout<<"Enter the element"<<endl;
	cin>>t->data;
	if(root==NULL)
	{
		//cout<<"inside root"<<endl;
		root=t;
	}
	else
	{
		node *curr;
		curr=root;
		while(curr)
		{
			p=curr;
			if(t->data>curr->data)
			{
				curr=curr->right;
			}
			else
			{
				curr=curr->left;
			}
		}
		if(t->data>p->data)
		{
			p->right=t;
		}
		else
		{
			p->left=t;
		}
	}
}

void BinarySearchTree::inorder(node *t)
{
	if(t->left)
	{
		inorder(t->left);
	}
	cout<<t->data<<endl;
	if(t->right)
	{
		inorder(t->right);
	}
}

void BinarySearchTree::postorder(node *t)
{
	if(t->left)
	{
		postorder(t->left);
	}
	if(t->right)
	{
		postorder(t->right);
	}
	cout<<t->data<<endl;
}

void BinarySearchTree::preorder(node *t)
{
	cout<<t->data<<endl;
	if(t->left)
	{
		preorder(t->left);
	}
	if(t->right)
	{
		preorder(t->right);
	}
}

void BinarySearchTree::search()
{
	bool result=false;
	node *p;
	p=root;
	int key;
	cout<<"Enter the key to found"<<endl;
	cin>>key;
	if(root==NULL)
	{
		cout<<"Tree is empty"<<endl;
	}
	else
	{
		while(p)
		{
			if(key==p->data)
			{
				result=true;
				break;
			}
			else if(key>p->data)
			{
				p=p->right;
			}
			else if(key<p->data)
			{
				p=p->left;
			}
		}
		if(result==true)
		{
			cout<<"Found"<<endl;
		}
		else
		{
			cout<<"Not found"<<endl;
		}
	}
}

void BinarySearchTree::minimum()
{
	node *p;
	p=root;
	if(root==NULL)
	{
		cout<<"Tree is empty"<<endl;
	}
	else
	{
		int min=p->data;
		while(p)
		{
			//int min=p->data;
			if(min>p->data)
			{
				min=p->data;
			}
			p=p->left;
		}
		cout<<"Minimum value is:"<<min<<endl;
	}
}

void BinarySearchTree::maximum()
{
	node *p;
	p=root;
	if(root==NULL)
	{
		cout<<"Tree is empty"<<endl;
	}
	else
	{
		int max=p->data;
		while(p)
		{
			if(max<p->data)
			{
				max=p->data;
			}
			p=p->right;
		}
		cout<<"Maximum value is:"<<max<<endl;
	}
}

int BinarySearchTree::depth(node *t)
{
	int maxdepth;
	//cout<<count++;
	//node *p;
	//p=root;
	//int ldepth=0;
	//int rdepth=0;
	if(t==NULL)
	{
		return 0;
	}
	else
	{
		int ldepth=depth(t->left);
		int rdepth=depth(t->right);
		if(ldepth>rdepth)
		{
			maxdepth=ldepth+1;
		}
		else
		{
			maxdepth=rdepth+1;
		}
		return maxdepth;
	}
}	

void BinarySearchTree::mirror(node *t)
{
	if(t==NULL)
	{
		return ;
		//cout<<"Tree is empty"<<endl;
	}
	else
	{
		node *temp;
		mirror(t->left);
		mirror(t->right);
		temp=t->left;
		t->left=t->right;
		t->right=temp;
	}
	
	//cout<<"Mirror successfully"<<endl;
}

void BinarySearchTree::remove()
{
	bool result=false;
	node *p;
	p=root;
	int element;
	cout<<"Enter the element to delete"<<endl;
	cin>>element;
	if(root==NULL)
	{
		cout<<"Empty tree"<<endl;
	}
	else
	{
		node *curr;
		curr=root;
		while(curr)
		{
			p=curr;
			if(element==curr->data)
			{
				result=true;
				break;
			}
			else if(element>curr->data)
			{
				curr=curr->right;
			}
			else if(element<curr->data)
			{
				curr=curr->left;
			}
		}
		if(result==true)
		{
			//**********deleting leaf node**************//
			if(curr==p->left)
			{
				p->left=NULL;
				free(curr);
			}
			else if(curr==p->right)
			{
				p->right=NULL;
				free(curr);
			}
			//****************end of deleting leaf node****************************//
			//***************Deletion of node with 1 child**************************//
			else if(curr->left!=NULL&&curr->right==NULL)
			{
				if(curr==p->right)
				{
					p->right=curr->left;
				}
				curr->left=NULL;
				cout<<"curr->left!=NULL&&curr==p->right"<<endl;
				free(curr);
			}
			else if(curr->right!=NULL&&curr->left==NULL)
			{
				if(curr==p->right)
				{
					p->right=curr->right;
				}
				curr->right=NULL;
				cout<<"curr->right!=NULL&&curr==p->right"<<endl;
				free(curr);
			}
			else if(curr->right!=NULL&&curr->left==NULL)
			{
				if(curr==p->left)
				{
					p->left=curr->right;
				}
				curr->right=NULL;
				cout<<"curr->right!=NULL&&curr=p->left"<<endl;
				free(curr);
			}
			else if(curr->left!=NULL&&curr->right==NULL)
			{
				if(curr==p->left)
				{
					p->left=curr->left;
				}
				curr->left=NULL;
				cout<<"curr->left!=NULL&&curr=p->left"<<endl;
				free(curr);
			}
			//***********end of Deletion of node with 1 child***********************************//
			//***********Deletion of node with 2 child******************************************//
			else if(curr->left!=NULL&&curr->right!=NULL)
			{
				node *t1,*t2;
				t1=curr->right;
				if(t1->left==NULL&&t1->right==NULL)
				{
					curr->data=t1->data;
					curr->right=NULL;
					cout<<"t1->left==NULL&&t1->right==NULL"<<endl;
					free(t1);
				}
				if(t1->right!=NULL&&t1->left==NULL)
				{
					curr->data=t1->data;
					curr->right=t1->right;
					t1->right=NULL;
					cout<<"t1->right!=NULL&&t1->left==NULL"<<endl;
					free(t1);
				}
			}
			//else if()
		}
		cout<<"Deletion successfull"<<endl;
	}
}