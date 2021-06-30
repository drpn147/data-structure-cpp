#include<iostream>
#define SIZE 5
using namespace std;
class Dequeue
{
	public:
	int front=-1,rear=-1;
	int queue[SIZE];
	void insertbegin();
	void insertend();
	void deleteend();
	void deletebegin();
	void display();
}

int main()
{
	Dequeue d;
	int choice;
	do
	{
		cout<<"\n1.insertbegin()\n2.insertend()\n3.deleteend()\n4.deletebegin()\n5.display()\n";
		cin>>choice;
		switch(choice)
		{
			case 1:
					d.insertbegin();
					break;
			case 2:
					d.insertend();
					break;
			case 3:
					d.deleteend();
					break;
			case 4:
					d.deletebegin();
					break;
			case 5:
					d.display();
					break;
			default:
					cout<<"Invalid choice"<<endl;
		}
	}while(choice!=0);
}