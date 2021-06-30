#include<iostream>
#define SIZE 10
using namespace std;
class Queue
{
	public:
	int front=0,rear=0;
	int q[SIZE];
	void enqueue();
	void dequeue();
	void display();
};

int main()
{
	Queue q;
	int choice;
	/*int n;
	cout<<"Enter the no. of element"<<endl;
	cin>>n;
	int queue[n];
	cout<<"Enter the element"<<endl;
	for(int i=0;i<n;i++)
	{
		cin>>queue[i];
	}*/
	
	do{
		cout<<"\n1.Enqueue()\n2.Dequeue\n3.display()\n";
		cin>>choice;
		switch(choice)
		{
			case 1:
					q.enqueue();
					break;
			case 2:
					q.dequeue();
					break;
			case 3:
					q.display();
					break;
			default:
					cout<<"Invalid choice"<<endl;
		}
		
	}while(choice!=0);
}


void Queue::enqueue()
{
	if(rear==SIZE)
	{
		cout<<"Queue is full"<<endl;
	}
	else
	{
		int element;
		cout<<"Enter the element"<<endl;
		cin>>element;
		q[rear]=element;
		rear++;
	}
}

void Queue::dequeue()
{
	if(front==rear)
	{
		cout<<"Queue is empty"<<endl;
	}
	else
	{
		cout<<"Deleted element "<<q[front]<<endl;
		for(int i=0;i<rear-1;i++)
		{
			q[i]=q[i+1];
		}
		rear--;
	}
}

void Queue::display()
{
	if(front==rear)
	{
		cout<<"Queue is empty"<<endl;
	}
	else
	{
		cout<<"Element are:"<<endl;
		for(int i=0;i<rear;i++)
		{
			cout<<q[i]<<"\t";
		}
	}
}


