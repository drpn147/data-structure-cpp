#include<iostream>
#define SIZE 5
using namespace std;
class CircularQueue
{
	public:
	int front=-1,rear=-1;
	int queue[SIZE];
	void enqueue();
	void dequeue();
	void display();
};

int main()
{
	CircularQueue cq;
	int choice;
	do
	{
		cout<<"\n1.enqueue()\n2.dequeue()\n3.display()\n";
		cin>>choice;
		switch(choice)
		{
			case 1:
					cq.enqueue();
					break;
			case 2:
					cq.dequeue();
					break;
			case 3:
					cq.display();
					break;
			default:
					cout<<"Invalide choice"<<endl;
		}
	}while(choice!=0);
}

void CircularQueue::enqueue()
{
	int element;
	if(front==rear+1||rear==SIZE-1)
	{
		cout<<"Queue is full";
	}
	else if(front==-1&&rear==-1)
	{
		front=0;
		rear=0;
		cout<<"Enter the element"<<endl;
		cin>>element;
		queue[rear]=element;
	}
	else if(rear==SIZE-1)
	{
		rear=0;
		cout<<"Enter the element"<<endl;
		cin>>element;
		queue[rear]=element;
	}
	else
	{
		rear++;
		cout<<"Enter the element"<<endl;
		cin>>element;
		queue[rear]=element;
	}
	
}

void CircularQueue::dequeue()
{
	if(front==-1&&rear==-1)
	{
		cout<<"Queue is empty"<<endl;
	}
	else if(front==SIZE-1)
	{
		cout<<queue[front]<<" is deleted"<<endl;
		front=0;
	}
	else if(front==rear)
	{
		cout<<queue[front]<<" is deleted"<<endl;
		front=-1;
		rear=-1;
	}
	else
	{
		cout<<queue[front]<<" is deleted"<<endl;
		front++;
	}
}

void CircularQueue::display()
{
	if(front==-1&&rear==-1)
	{
		cout<<"Queue is empty"<<endl;
	}
	else if(front<=rear)
	{
		cout<<"Queue element is:"<<endl;
		for(int i=front;i<=rear;i++)
		{
			cout<<queue[i]<<endl;
		}
	}
	else if(front>=rear)
	{
		cout<<"Queue element is:"<<endl;
		for(int i=front;i<=SIZE-1;i++)
		{
			cout<<queue[i]<<endl;
		}
		for(int i=0;i<=rear;i++)
		{
			cout<<queue[i]<<endl;
		}
	}
}