/*
   FILE          : SortingAlgorithm.c
   PROGRAMMER    : Rohit Bhardwaj
   DESCRIPTION   : This program uses quicksort while partitions are more than 10 elements long and insertion sort for anything less. 
*/

//Header Files
#include<stdio.h>


//Function Protoype declaration
void sort(int* arr_ptr, int arr_sz); 
int* quicksort(int* array, int firstIndex, int lastIndex);
    
//main function    
int main()
{
    //Declaring variables
    int array[100],n,i;

    //Number of elements in array form user input
    printf("Enter the number of element you want to Sort : ");
    scanf("%d",&n);

    //code to ask to enter elements from user equal to n
    printf("Enter Elements in the list : ");
    for(i = 0; i < n; i++)
    {
        scanf("%d",&array[i]);
    }
    
    //calling the sort function
    sort(array, n); 
}

// FUNCTION      : sort()
// DESCRIPTION   : Sort the elements of the array using quicksort while partitions are 
//                 more than 10 elements long and insertion sort for anything less
// PARAMETERS    : arr_ptr is a pointer to the first element, an arr_sz length of array
// RETURNS       : nothing
void sort(int* arr_ptr, int arr_sz)
{
 
 	int j,temp,i;
 	
 	//Conditional statement to check if partition is less than or equal to 10 elements
 	if(arr_sz <= 10)
 	{
      //Iterate start from second element 
      for (i = 1; i < arr_sz; i++)
      {
         j = i;
         //Iterate and compare till it satisfies condition 
         while ( j > 0 && arr_ptr[j] < arr_ptr[j-1])
         {
            //Swaping operation
            temp = arr_ptr[j];
            arr_ptr[j]   = arr_ptr[j-1];
            arr_ptr[j-1] = temp;
            j--;
          }
       }
    
        //print sorted array
        printf("Sorted By InsertionSort:\n");
        for(i = 0; i < arr_sz; i++ )
        {
          printf("%d\t",arr_ptr[i]);
        }
    }
    
    else
    { 
      //Calling the quicksort function
	  int *sortArray = quicksort(arr_ptr,0,arr_sz-1);
	  
      //print sorted array
      printf("Sorted By QuickSort:\n");
      
      for(i = 0; i < arr_sz; i++ )
      {
        printf("%d\t",sortArray[i]);
      }
    }
}

// FUNCTION      : quicksort()
// DESCRIPTION   : Sort the elements of the array using quick sort algorithm
// PARAMETERS    : array is a pointer to the first element, firstIndex, lastIndex
// RETURNS       : pointer integer array
int* quicksort(int* array, int firstIndex, int lastIndex)
{
    //declaring index variables
    int pivotIndex, temp, index1, index2;

    if(firstIndex < lastIndex)
    {
        //assigning first element index as pivot element
        pivotIndex = firstIndex; 
        index1 = firstIndex;     
        index2 = lastIndex;     

        //Sorting in Ascending order with quick sort
        while(index1 < index2)
        {
            while(array[index1] <= array[pivotIndex] && index1 < lastIndex) 
            {
                index1++;   
            }
            while(array[index2]>array[pivotIndex]) 
            {
                index2--;
            }

            if(index1<index2)
            {
                //Swapping opertation
                temp = array[index1];
                array[index1] = array[index2];
                array[index2] = temp;
            }
        }

        //At the end of first iteration, swap pivot element with index2 element
        temp = array[pivotIndex];
        array[pivotIndex] = array[index2];
        array[index2] = temp;

        //Recursive call for quick sort, with partiontioning
        quicksort(array, firstIndex, index2-1);
        quicksort(array, index2+1, lastIndex);
    }
        //return Sorted array
    return array;
}
