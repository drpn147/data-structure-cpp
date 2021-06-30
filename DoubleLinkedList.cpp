#include<iostream>
using namespace std;
struct node
{
	int data;
	struct node *prev;
	struct node *next;
};
struct node *root=NULL;

class DoubleLinkedList
{
	public:
	void insert();
	void insertBegin();
	void display();
	void insertMiddle();
	int length();
	void deletelast();

};

int main()
{
	DoubleLinkedList d;
	int choice;
	do
	{
		cout<<"\n1.insert()\n2.display()\n3.insertBegin()\n4.insertMiddle()\n5.length()\n6.deletelast()\n";
		cin>>choice;
		switch(choice)
		{
			case 1:
					d.insert();
					break;
			case 2:
					d.display();;
					break;
			case 3:
					d.insertBegin();
					break;
			case 4:
					d.insertMiddle();
					break;
			case 5:
					cout<<"Length:"<<d.length()<<endl;
					break;
			case 6:
					d.deletelast();
					break;
			default:
					cout<<"invalid choice"<<endl;
		}
	}while(choice!=0);
}

void DoubleLinkedList::insert()
{
	struct node *temp;
	temp=(struct node*)malloc(sizeof(struct node));
	cout<<"Enter the data"<<endl;
	cin>>temp->data;
	temp->prev=NULL;
	temp->next=NULL;
	if(root==NULL)
	{
		root=temp;
	}
	else
	{
		struct node *p;
		p=root;
		while(p->next!=NULL)
		{
			p=p->next;
		}
			p->next=temp;
			temp->prev=p;
			temp->next=NULL;
		
	}
}

void DoubleLinkedList::display()
{
	struct node *temp;
	temp=root;
	while(temp!=NULL)
	{
		cout<<temp->data<<"\t";
		temp=temp->next;
	}
}


int DoubleLinkedList::length()
{
	int count=0;
	struct node *temp;
	temp=root;
	if(temp==NULL)
	{
		return 0;
	}
	else
	{
		while(temp!=NULL)
		{
			count++;
			temp=temp->next;
		}
	}
	return count;
}

void DoubleLinkedList::insertBegin()
{
	struct node *temp;
	temp=(struct node*)malloc(sizeof(struct node));
	cout<<"Enter the data"<<endl;
	cin>>temp->data;
	temp->prev=NULL;
	temp->next=NULL;
	if(root==NULL)
	{
		root=temp;
	}
	else
	{
		struct node *p;
		p=root;
		temp->next=p;
		p->prev=p;
		root=temp;
	}
}

void DoubleLinkedList::insertMiddle()
{
	struct node *temp,*p;
	int i=1,loc;
	cout<<"Enter the location"<<endl;
	cin>>loc;
	if(loc>length())
	{
		cout<<"Out of Range";
	}
	else
	{
		p=root;
		while(i<loc)
		{
			p=p->next;
			i++;
		}
		temp=(struct node*)malloc(sizeof(struct node));
		cout<<"Enter the daata"<<endl;
		cin>>temp->data;
		//temp->prev=NULL;
		//temp->next=NULL;
	
		temp->next=p->next;
		temp->prev=p;
		//p->next=temp;
		p->next->prev=temp;
		p->next=temp;
	}
}

void DoubleLinkedList::deletelast()
{
	struct node *p;
	if(root==NULL)
	{
		cout<<"List is empty"<<endl;
	}
	else if(root->next==NULL)
	{
		root==NULL;
		free(root);
	}
	else
	{
		p=root;
		while(p->next!=NULL)
		{
			p=p->next;	
		}
		p->prev->next=NULL;
		free(p);
	}
}