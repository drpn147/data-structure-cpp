#include<iostream>
using namespace std;
class Searching
{
	public:
	void linear();
	void binary();
};

int main()
{
	Searching s;
	int choice;
	do
	{
		cout<<"\n1.Linear()\n2.Binary()\n";
		cin>>choice;
		switch(choice)
		{
			case 1:
					s.linear();
					break;
			case 2:
					s.binary();
					break;
			default:
					cout<<"Invalid choice"<<endl;
					
		}
	}while(choice!=0);
}

void Searching::linear()
{
	int n;
	cout<<"Enter the no. of element"<<endl;
	cin>>n;
	int arr[n];
	cout<<"Enter the element"<<endl;
	for(int i=0;i<n;i++)
	{
		cin>>arr[i];
	}
	int key;
	cout<<"Enter the element want to search"<<endl;
	cin>>key;
	for(int i=0;i<n;i++)
	{
		if(arr[i]==key)
		{
			cout<<"Key found at"<<i+1<<"location"<<endl;
			break;
		}
	}
	cout<<"Not found"<<endl;
}

void Searching::binary()
{
	int n;
	cout<<"Enter the no. of element"<<endl;
	cin>>n;
	int arr[n];
	cout<<"Enter the element"<<endl;
	for(int i=0;i<n;i++)
	{
		cin>>arr[i];
	}
	/*
	for(int i=0;i<n-1;i++)
	{
		for(int j=0;j<n-1-i;j++)
		{
			int temp;
			if(arr[j]>arr[j+1])
			{
				temp=arr[j];
				arr[j]=arr[j+1];
				arr[j+1]=temp;
			}
		}
	}
	*/
	int l=0,u=n;
	int key;
	cout<<"Enter the element to found"<<endl;
	cin>>key;
	while(l<=u)
	{
		int mid=(l+u)/2;
		if(arr[mid]==key)
		{
			cout<<key<<" found at "<<mid+1<<endl;
			break;
		}
		else if(key>arr[mid])
		{
			l=mid+1;
		}
		else if(key<arr[mid])
		{
			u=mid-1;
		}
		else
		{
			cout<<"Not found"<<endl;
		}
	}
}