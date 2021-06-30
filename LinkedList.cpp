#include<iostream>
using namespace std;

struct node
{
	int data;
	struct node *link;
};
struct node *root=NULL;



class LinkedList
{
	public:
	void insert();
	void display();
	int length();
	void remove();
	void insertMiddle();
	void insertBegin();
	void swap();
	void reverse();
};


int main()
{
	int choice;
	LinkedList l;
	do
	{
		cout<<"\n1.insert()\n2.display()\n3.length()\n4.remove()\n5.insertMiddle()\n6.insertBegin()\n7.swap()\n8.reverse()\n";
		cin>>choice;
		switch(choice)
		{
			case 1:
					l.insert();
					break;
			case 2:
					l.display();
					break;
			case 3:
					cout<<"length:"<<l.length()<<endl;
					break;
			case 4:
					l.remove();
					break;
			case 5:
					l.insertMiddle();
					break;
			case 6:
					l.insertBegin();
					break;
			case 7:
					l.swap();
					break;
			case 8:
					l.reverse();
					break;
			default:
					cout<<"Invalid choice"<<endl;
					
		}
	}while(choice!=0);	
}


void LinkedList::insert()
{
	struct node *temp;
	temp=(struct node*)malloc(sizeof(struct node));
	cout<<"Enter the data"<<endl;
	cin>>temp->data;
	temp->link=NULL;
	if(root==NULL)
	{
		root=temp;
	}
	else
	{
		struct node *p;
		p=root;
		while(p->link!=NULL)
		{
			p=p->link;
		}
		p->link=temp;
	}
}


void LinkedList::display()
{
	struct node *temp;
	temp=root;
	if(temp==NULL)
	{
		cout<<"List is empty";
	}
	else
	{
		while(temp!=NULL)
		{
			cout<<temp->data<<"\t";
			temp=temp->link;
		}
	}
}


int LinkedList::length()
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
			temp=temp->link;
		}
	}
	return count;
}


void LinkedList::remove()
{
	struct node *temp;
	int loc;
	cout<<"Enter the location of node to delete"<<endl;
	cin>>loc;
	if(loc>length())
	{
		cout<<"Out of range"<<endl;
	}
	else if(loc==1)
	{
		struct node*temp;
		temp=root;
		root=temp->link;
		temp->link=NULL;
		free(temp);
	}
	else
	{
		int i=1;
		struct node *p,*q;
		p=root;
		while(i<loc-1)
		{
			p=p->link;
			i++;
		}
		q=p->link;
		p->link=q->link;
		q->link=NULL;
		free(q);
		
	}
}


void LinkedList::insertMiddle()
{
	struct node *temp,*p;
	int i=1;
	int loc;
	cout<<"Enter the location"<<endl;
	cin>>loc;
	if(loc>length())
	{
		cout<<"Out of Range"<<endl;
	}
	else 
	{
		p=root;
		while(i<loc)
		{
			p=p->link;
			i++;
		}
		temp=(struct node*)malloc(sizeof(struct node));
		cout<<"Enter the data"<<endl;
		cin>>temp->data;
		temp->link=p->link;
		p->link=temp;
	}
}

void LinkedList::insertBegin()
{
	struct node *temp;
	temp=(struct node*)malloc(sizeof(struct node));
	cout<<"Enter the data"<<endl;
	cin>>temp->data;
	temp->link=NULL;
	if(root==NULL)
	{
		root=temp;
	}
	else
	{
		temp->link=root;
		root=temp;
	}
}	

void LinkedList::swap()
{
	struct node *p, *q, *r;
	int i=1;
	int loc;
	cout<<"Enter the location to swap"<<endl;
	cin>>loc;
	p=root;
	while(i<loc-1)
	{
		p=p->link;
		i++;
	}
	q=p->link;
	r=q->link;
	q->link=r->link;
	r->link=q;
	p->link=r;
	cout<<"Swapped Successfully"<<endl;
}

void LinkedList::reverse()
{
	int i=0;
	int j=length()-1;
	struct node *p, *q;
	p=q=root;
	while(i<j)
	{
		int k=0;
		while(k<j)
		{
			q=q->link;
			k++;
		}
		int temp=p->data;
		p->data=q->data;
		q->data=temp;
		i++;
		j--;
		p=p->link;
		q=root;
		
	}
	cout<<"Reverse successfully"<<endl;
}