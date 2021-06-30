#include<iostream>
using namespace std;
class Sorting
{
	public:
	void bubble();
	void selection();
	void insertion();
	void mergesorting();
	void mergesort(int arr[],int beg,int end);
	void merge(int arr[],int beg,int mid,int end);
};

int main()
{
	int choice;
	Sorting s;
	do
	{
		cout<<"\n1.Bubble()\n2.Selection()\n3.Insertion()\n4.merge()\n";
		cin>>choice;
		switch(choice)
		{
			case 1:
					s.bubble();
					break;
			case 2:
					s.selection();
					break;
			case 3:
					s.insertion();
					break;
			case 4:
					s.mergesorting();
					break;
			default:
					cout<<"Invalid choice";
		}
	}while(choice!=0);
}



void Sorting::bubble()
{
	int n;
	cout<<"Enter the size of array"<<endl;
	cin>>n;
	int arr[n];
	cout<<"Enter the element"<<endl;
	for(int i=0;i<n;i++)
	{
		cin>>arr[i];
	}
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
	cout<<"After sorting"<<endl;
	for(int i=0;i<n;i++)
	{
		cout<<arr[i]<<endl;
	}
}


void Sorting::selection()
{
	int n;
	cout<<"Enter the size of array"<<endl;
	cin>>n;
	int arr[n];
	cout<<"Enter the element"<<endl;
	for(int i=0;i<n;i++)
	{
		cin>>arr[i];
	}
	int min;
	for(int i=0;i<n-1;i++)
	{
		min=i;
		for(int j=i+1;j<n;j++)
		{
			if(arr[min]>arr[j])
			{
				min=j;
			}
		}
		int temp=arr[i];
		arr[i]=arr[min];
		arr[min]=temp;
	}
	cout<<"After sorting:"<<endl;
	for(int i=0;i<n;i++)
	{
		cout<<arr[i]<<endl;
	}
}

void Sorting::insertion()
{
	int n;
	cout<<"Enter the size of array"<<endl;
	cin>>n;
	int arr[n];
	cout<<"Enter the element"<<endl;
	for(int i=0;i<n;i++)
	{
		cin>>arr[i];
	}
	int key,j;
	for(int i=1;i<n;i++)
	{
		key=arr[i];
		j=i-1;
		while(j>=0 && arr[j]>key)
		{
			arr[j+1]=arr[j];
			j--;
		}
		arr[j+1]=key;
	}
	cout<<"After Sorting:"<<endl;
	for(int i=0;i<n;i++)
	{
		cout<<arr[i]<<endl;
	}

}

void Sorting ::mergesorting()
{
	int n;
	cout<<"Enter the size of array"<<endl;
	cin>>n;
	int arr[n];
	cout<<"Enter the element"<<endl;
	for(int i=0;i<n;i++)
	{
		cin>>arr[i];
	}
	mergesort(arr,0,n-1);
	cout<<"After Sorting"<<endl;
	for(int i=0;i<n;i++)
	{
		cout<<arr[i];
	}
}

void Sorting::mergesort(int arr[],int beg,int end)
{
	int mid;
	if(beg<end)
	{
		mid=(beg+end)/2;
		mergesort(arr,beg,mid);
		mergesort(arr,mid+1,end);
		merge(arr,beg,mid,end);
	}
}


void Sorting::merge(int arr[],int beg,int mid,int end)
{
	int i=beg;
	int j=mid+1;
	int k;
	int index=beg;
	int temp[end];
	while(i<=mid&&j<=end)
	{
		if(arr[i]<arr[j])
		{
			temp[index]=arr[i];
			i++;
		}
		else
		{
			temp[k]=arr[j];
			j++;
		}
		index++;
	}
	
	if(i>mid)
	{
		while(j<=end)
		{
			temp[index]=arr[i];
			j++;
			index++;
		}
	}
	else
	{
		while(i<=mid)
		{
			temp[index]=arr[i];
			i++;
			index++;
		}
	}
	k=beg;
	while(k<index)
	{
		arr[k]=temp[k];
		k++;
	}
}
