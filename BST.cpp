#include<iostream>
using namespace std;
struct node
{
	int data;
	struct node *left;
	struct node *right;
};

struct node *root=NULL;
class BST
{
	public:
	void insert();
	void remove();
};

int main()
{
	int choice;
	do
	{
		BST b;
		cout<<"\n1.insert()\n2.delete()\n";
		cin>>choice;
		switch(choice)
		{
			case 1:
				b.insert();
				break;
			case 2:
				b.remove();
				break;
			default:
				cout<<"Invalid choice"<<endl;
		}
	}while(choice!=0);
}

void BST::insert()
{
	int element;
	cout<<"Enter the element"<<endl;
	cin>>element;
	struct node *t;
	t=(struct node*)malloc(sizeof(struct node));
	t->data=element;
	t->left=NULL;
	t->right=NULL;
	struct node *p;
	p=root;
	if(root==NULL)
	{
		root=t;
		cout<<"Enter data at root successfully"<<endl;
	}
	else
	{
		struct node *curr;
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
			cout<<"Data at right";
		}
		else
		{
			p->left=t;
			cout<<"Data at left";
		}
	}
}


void BST :: remove()
{
	int element;
	cout<<"Enter the element to deleted"<<endl;
	cin>>element;
	struct node *p;
	//p=root;
	if(root==NULL)
	{
		cout<<"No node in tree"<<endl;
	}
	else
	{
		struct node *curr;
		curr=root;
		while(curr)
		{
			p=curr;
			if(element>curr->data)
			{
				curr=curr->right;
			}
			else if(element<curr->data)
			{
				curr=curr->left;
			}	
		}
		if(element==curr->data)
		{
			if(curr->left!=NULL)
			{
				if(curr==p->right)
				{
					p->right=curr->left;
				}
				cout<<"p->right=curr->left"<<endl;
			curr->left=NULL;
			free(curr);
			cout<<"Deleted"<<endl;
			}
			else if(curr->right!=NULL)
			{
				if(curr==p->right)
				{
					p->right=curr->right;
				}
				curr->right=NULL;
				free(curr);
			}
		}
	}
	cout<<"Deleted successfullly"<<endl;
}