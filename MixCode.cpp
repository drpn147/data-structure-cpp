#include<iostream>
using namespace std;
class MixCode
{
	public:
	void fibonicc();
	void palindrom();
	void simplepattern();
	void DiamondPattern();
	void primeno();
	
	
};


int main()
{
	MixCode m;
	int choice;
	do
	{
		cout<<"\n1.Fibonnicc\n2.Palindrom\n3.SimplePattern\n4.DiamondPattern\n5.Primeno\n";
		cin>>choice;
		switch(choice)
		{
			case 1:
					m.fibonicc();
					break;
			case 2:
					m.palindrom();
					break;
			case 3:
					m.simplepattern();
					break;
			case 4:
					m.DiamondPattern();
					break;
			case 5:
					m.primeno();
					break;
			default:
					cout<<"invalid choice"<<endl;
		}
	}while(choice!=0);
}

void MixCode::fibonicc()
{
	int a=0,b=1,c;
	int n;
	cout<<"Enter the element"<<endl;
	cin>>n;
	for(int i=0;i<n;i++)
	{
		cout<<a<<"\t";
		c=a+b;
		a=b;
		b=c;
	}
}


void MixCode::palindrom()
{
	int number;
	int sum=0;
	int r,temp;
	cout<<"Enter the number"<<endl;
	cin>>number;
	temp=number;
	while(number>0)
	{
		r=number%10;
		sum=sum*10+r;
		number=number/10;
		cout<<"r: "<<r<<endl;
		cout<<"sum: "<<sum<<endl;
		cout<<"number: "<<number<<endl;
	}
	number=temp;
	if(number==sum)
	{
		cout<<"Palindrom"<<endl;
	}
	else
	{
		cout<<"Not Palindrom"<<endl;
	}
}

void MixCode::simplepattern()
{
	for(int i=0;i<=4;i++)
	{
		for(int j=0;j<=i;j++)
		{
			cout<<"*";
		}
		cout<<"\n";
	}
}

void MixCode::DiamondPattern()
{
	int n;
	cout<<"Enter the no. of rows"<<endl;
	cin>>n;
	int space=n-1;
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<space;j++)
		{
			cout<<" ";
		}
		for(int k=0;k<=i;k++)
		{
			cout<<"*";
		}
			
		cout<<endl;	
		space--;
			
		
	}
	space =0;
	for(int i=n;i>0;i--)
	{
		for(int j=0;j<space;j++)
		{
			cout<<" ";
		}
		for(int k=0;k<i;k++)
		{
			cout<<"*";
		}
		cout<<endl;
		space++;
	}
}

void MixCode::primeno()
{
	int n;
	bool isPrime=true;
	cout<<"Enter the no."<<endl;
	cin>>n;
	if(n==0||n==1)
	{
		isPrime=false;
	}
	else
	{
		for(int i=2;i<n;i++)
		{
			if(n%i==0)
			{
				isPrime=false;
				break;
			}
		}
	}
	if(isPrime)
	{
		cout<<"Prime no."<<endl;
	}
	else
	{
		cout<<"Not a prime no."<<endl;
	}
}