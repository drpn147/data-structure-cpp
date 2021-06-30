#include<iostream>
using namespace std;
class Sorting
{
	public:
	void mergesorting();
	void mergesort(int arr[],int beg,int end);
	void merge(int arr[],int beg,int mid,int end);
};
int main()
{
	Sorting s;
	s.mergesorting();
	
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