//Binary Search 
#include <stdio.h>
int main()
{
	int n,key,low,high,mid,i;
	printf("Enter No. of Element :");
	scanf("%d",&n);
	int arr[n];
	printf("Enter Elements :");
	for(i=0;i<n;i++)
	scanf("%d",&arr[i]);
	printf("Enter Key :");
	scanf("%d",&key);
	low=0;
	high=n-1;
	while (low<=high)
	{
		mid=(low+high)/2;
		if (arr[mid]==key)
		{
			printf("Element Found");
			return 0;
		}
		else if(arr[mid]>key)
		{
			high=mid-1;
		}
		else
		{
			low=mid+1;
		}
	}
	printf("Element not found");
	 return 0;	
}

