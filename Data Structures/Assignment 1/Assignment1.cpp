#include <iostream>
#include <iomanip>
#include <chrono>
#include <cstdlib>
#include <string>
#include <fstream>

using namespace std;

/*
	Student class representing a student
*/
class Student
{
private:
	string firstName;
	string lastName;
	int mNumber;

public:

	Student()
	{
		firstName = "";
		lastName = "";
		mNumber = 0;
	}

	Student( string firstName, string lastName, int mNumber )
	{
		this->firstName = firstName;
		this->lastName = lastName;
		this->mNumber = mNumber;
	}

	/*
		Getter : Student First Name
	*/
	string getFirstName()
	{
		return firstName;
	}

	/*
		Getter : Student Last Name
	*/
	string getLastName()
	{
		return lastName;
	}

	/*
		Getter : Student ID Number
	*/
	int getMNumber()
	{
		return mNumber;
	}
};

//Bare bones linked list
class LinkedList
{
private:
	// Node structure with a type definition for pointers
	// To create a node pointer, you can use both Node* or nodePtr
	typedef struct Node
	{
		Student student;
		Node* next;
	}*nodePtr;

	// Pointers
	// Head pointer | Beginning of list
	nodePtr head;

	nodePtr curr;
	nodePtr temp;

public:
	// Declare empty list on constructor
	LinkedList()
	{
		head = NULL;
		curr = NULL;
		temp = NULL;
	}

	// Deconstruct
	~LinkedList()
	{
		curr = head;
		nodePtr nextNode = NULL;

		while (curr != NULL)
		{
			nextNode = curr->next;
			delete curr;
			curr = nextNode;
		}
		head = NULL;
	}

	// Appends a new node to the list
	void push(const Student& newStudent )
	{
		nodePtr n = new Node;

		n->next = NULL;
		n->student = newStudent;

		if (head != NULL)
		{
			curr = head;

			while (curr->next != NULL)
			{
				curr = curr->next;
			}
			curr->next = n;
		}
		else
		{
			//This line is wrong but too late to change
			//Should be head->next = n but its too late to change 
			head = n;
		}
	}

	void getStudentData(string const fileName )
	{
		ifstream studentFile( fileName );

		if (studentFile.is_open())
		{
			string firstName, lastName, mNum;
			int mNumber;

			while (!studentFile.eof())
			{
				studentFile >> firstName >> lastName >> mNum;

				mNumber = stoi( mNum );

				Student newStudent( firstName, lastName, mNumber );
				push( newStudent );
			}

			studentFile.close();
		}
		else
		{
			cout << "Failed to load data..." << endl;
		}
	}

	void printData()
	{
		curr = head;

		while (curr != NULL)
		{
			string name = curr->student.getFirstName() + " " + curr->student.getLastName();

			cout << name << " " << curr->student.getMNumber() << endl;

			curr = curr->next;
		}
	}	

	//Will be used to achieve ascending/descending functionality
	void reverse()
    {
        
        Node* current = head;
        Node *prev = NULL, *next = NULL;
 
        while (current != NULL) 
		{
            
            next = current->next;
            current->next = prev;
            
            prev = current;
            current = next;
        }
        head = prev;
    }

	nodePtr* getHead()
	{
		return &head;
	}

    // Gets last node of linked list.
    Node *getTail(Node *current) {
      while ((current != NULL) && (current->next != NULL)) {
        current = current->next;
      }
      return current;
    }

	//Sorting Algorithms
	////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
		

	//Merge Sort
	////////////////////////////////////////////////////////////	
	
	void MergeSort(Node** headRef)
	{
		Node* head = *headRef;
		Node* a;
		Node* b;
	
		//Base case -- length 0 or 1
		if ((head == NULL) || (head->next == NULL)) {
			return;
		}
	
		//Split head into a and b sublists
		FrontBackSplit(head, &a, &b);
	
		// Recursively sort the sublists
		MergeSort(&a);
		MergeSort(&b);
	
		// Merge the two sorted lists together
		*headRef = SortedMerge(a, b);
	}
	

	Node* SortedMerge(Node* a, Node* b)
	{
		Node* result = NULL;
	
		//Base cases
		if (a == NULL)
			return (b);
		else if (b == NULL)
			return (a);
	
		//Pick either a or b
		if (a->student.getFirstName() <= b->student.getFirstName()) {
			result = a;
			result->next = SortedMerge(a->next, b);
		}
		else {
			result = b;
			result->next = SortedMerge(a, b->next);
		}
		return (result);
	}	
	
	void FrontBackSplit(Node* source,
						Node** frontRef, Node** backRef)
	{
		Node* fast;
		Node* slow;
		slow = source;
		fast = source->next;	
		
		while (fast != NULL) {
			fast = fast->next;
			if (fast != NULL) {
				slow = slow->next;
				fast = fast->next;
			}
		}	
		
		*frontRef = source;
		*backRef = slow->next;
		slow->next = NULL;
	}
	////////////////////////////////////////////////////////////

	//Bubble Sort 
	////////////////////////////////////////////////////////////
	void BubbleSort()
	{
		
		Node* currentNode = head;		


		int maxPossibleIndex = 	getSize() - 2;	

		for(int i = 0; i < maxPossibleIndex; i++)
		{			
			//Keep swapping while index != getSize - 2
			//Change condition to - 3 and as so each pass
			for(int j = 0; j < maxPossibleIndex - i; j++)
			{	
				swap(currentNode, currentNode->next, currentNode->next->next);	
				currentNode = currentNode->next;						
			}			
			
			currentNode = head;	
		}

		Node* headTemp = head->next;
		head = headTemp;				
	}

	
		

	int getSize()
	{		
		/* Counts no. of nodes in linked list */
		int i = 0; // Initialize count
		Node* current = head; // Initialize current
		while (current != NULL)
		{
			i++;
			current = current->next;
		}
		int nodes = i;
	}	

	//Don't ever call at the last index
	void swap(Node * n0, Node * n1, Node * n2)
	{
		if(n1->student.getLastName() >= n2->student.getLastName())
		{			
			n1->next = n2->next;
			n2->next = n1;
			n0->next = n2;
		}
		
	}
	


	////////////////////////////////////////////////////////////


	//Quick Sort
	////////////////////////////////////////////////////////////

	////////////////////////////////////////////////////////////
    // Partition list using last element as pivot
    Node *partition(Node *head, Node *last, Node **updateHead, Node **updateLast) {
      Node *pivot = last;
      Node *previous = NULL;
      Node *current = head;
      Node *tail = pivot;

      // Update head and last element of list with updateHead and updateLast variables
      // if head and last change
      while (current != pivot) {
        if (current->student.getMNumber() <= pivot->student.getMNumber()) {
          // New head becomes node with value less than pivot (last element)
          if ((*updateHead) == NULL) {
            (*updateHead) = current;
          }
          previous = current;
          current = current->next;
        } else {
          // Current node greater than pivot, move current to next to tail
          if (previous) {
            previous->next = current->next;
          }
          Node *temp = current->next;
          current->next = NULL;
          tail->next = current;
          tail = current;
          current = temp;
        }
      }

      // If pivot is smallest, pivot becomes head
      if ((*updateHead) == NULL) {
        (*updateHead) = pivot;
      }

      // Last is updated to tail
      (*updateLast) = tail;

      return pivot;
    }

    // Sorting exclusive of last
    Node *quickSortRecursion(Node *head, Node *last) {
      // Base case
      if (!head || head == last) {
        return head;
      }

      Node *updateHead = NULL;
      Node *updateLast = NULL;

      // Partition list
      Node *pivot = partition(head, last, &updateHead, &updateLast);

      // If pivot smallest, no recursion needed on left side
      if (updateHead != pivot) {
        Node *temp = updateHead;
        while (temp->next != pivot) {
          temp = temp->next;
        }
        temp->next = NULL;

        // Recursion is used for before pivot
        updateHead = quickSortRecursion(updateHead, temp);

        temp = getTail(updateHead);
        temp->next = pivot;
      }

      // Recursion for after pivot
      pivot->next = quickSortRecursion(pivot->next, updateLast);

      return updateHead;
    }

    // Main quick sort function utilizing recursion function
    void QuickSort(Node **headRef) {
      (*headRef) = quickSortRecursion(*headRef, getTail(*headRef));
      return;
    }
};

//Bubble sort method
void bubbleSort(int array[], int const ArraySize)
{
//Bubble sort iterates through a list, comparing and swapping adjacent elements with nested loops, bubble sort has a runtime of O(N)^2
   int i, j, temp = 0;
   // Given a list with N elements, the outer i-loop iterates N - 1 times. Each iteration moves the largest element into sorted position
   for (i = 0; i < ArraySize - 1; i++) {
      // Inner loop j iterates through all adjacent pairs, swapping adjacent elements as needed, except for i pairs that are already in the correct position.
       for (j = 0; j < ArraySize - i - 1; j++) {
         if (array[j] > array[j+1]) {
            // Stores array as temp before swapping element values
            temp = array[j];
            array[j] = array[j + 1];
            array[j + 1] = temp;
         }
      }
   }
}
////////////////////////////////////////////////////////////
//Insertion sort method
////////////////////////////////////////////////////////////
void insertionSort( int array[], int const arraySize )
{
	int j, temp = 0;

	for (int i = 1; i < arraySize; i++)
	{
		j = i;

		while (j > 0 && array[j] < array[j - 1])
		{
			temp = array[j];
			array[j] = array[j - 1];
			array[j - 1] = temp;
			j -= 1;
		}
	}
}
////////////////////////////////////////////////////////////

//Merge sort method
////////////////////////////////////////////////////////////
void merge( int array[], int const left, int const mid, int const right )
{
	int const subArrayOne = mid - left + 1;
	int const subArrayTwo = right - mid;

	// Create temp arrays
	auto* leftArray = new int[subArrayOne],
		* rightArray = new int[subArrayTwo];

	// Copy data to temp arrays leftArray[] and rightArray[]
	for (int i = 0; i < subArrayOne; i++)
		leftArray[i] = array[left + i];
	for (int j = 0; j < subArrayTwo; j++)
		rightArray[j] = array[mid + 1 + j];

	int indexOfSubArrayOne = 0, // Initial index of first sub-array
		indexOfSubArrayTwo = 0; // Initial index of second sub-array
	int indexOfMergedArray = left; // Initial index of merged array

	// Merge the temp arrays back into array[left..right]
	while (indexOfSubArrayOne < subArrayOne && indexOfSubArrayTwo < subArrayTwo)
	{
		if (leftArray[indexOfSubArrayOne] <= rightArray[indexOfSubArrayTwo])
		{
			array[indexOfMergedArray] = leftArray[indexOfSubArrayOne];
			indexOfSubArrayOne++;
		}
		else {
			array[indexOfMergedArray] = rightArray[indexOfSubArrayTwo];
			indexOfSubArrayTwo++;
		}
		indexOfMergedArray++;
	}
	// Copy the remaining elements of left[], if there are any
	while (indexOfSubArrayOne < subArrayOne)
	{
		array[indexOfMergedArray] = leftArray[indexOfSubArrayOne];
		indexOfSubArrayOne++;
		indexOfMergedArray++;
	}

	// Copy the remaining elements of right[], if there are any
	while (indexOfSubArrayTwo < subArrayTwo)
	{
		array[indexOfMergedArray] = rightArray[indexOfSubArrayTwo];
		indexOfSubArrayTwo++;
		indexOfMergedArray++;
	}
}

// begin is for left index and end is
// right index of the sub-array
// of arr to be sorted */
void mergeSort( int array[], int const begin, int const end )
{
	if (begin >= end)
		return; // Returns recursively

	int mid = begin + (end - begin) / 2;
	mergeSort( array, begin, mid );
	mergeSort( array, mid + 1, end );
	merge( array, begin, mid, end );
}
////////////////////////////////////////////////////////////

//Quicksort method
////////////////////////////////////////////////////////////

// Partition function utilized in quick sort method.
int partition( int array[], int low_index, int high_index ) {
	int midpoint = low_index + (high_index - low_index) / 2;
	int pivot = array[midpoint];
	int temp = 0;

	bool find_high_index = false;
	// Finding index of highest element.
	while (!find_high_index) {
		// Checks elements below pivot are less than pivot.
		while (array[low_index] < pivot) {
			low_index += 1;
		}
		// Checks elements above pivot are greater than pivot.
		while (pivot < array[high_index]) {
			high_index -= 1;
		}
		// Ends partitioning if low index and high index move past pivot or meet.
		if (low_index >= high_index) {
			find_high_index = true;
		}
		else {
			// Continues partitioning by reassigning elements around pivot.
			temp = array[low_index];
			array[low_index] = array[high_index];
			array[high_index] = temp;
			low_index += 1;
			high_index -= 1;
		}
	}
	return high_index;
}

// Quick sort function utilizing partition function.
void quickSort( int array[], int low_index, int high_index ) {
	// Continues until low index is greater than high index.
	if (low_index < high_index) {
		// Calls partition function to partition elements around pivot.
		int partition_index = partition( array, low_index, high_index );
		// Uses recursion to sort each partition on either side of pivot.
		quickSort( array, low_index, partition_index - 1 );
		quickSort( array, partition_index + 1, high_index );
	}
}


////////////////////////////////////////////////////////////
//Heap-sort method
// This function will be used to take the array and transform it to the heap
void MaxHeapPercolateDown(int nodeIndex, int array[], int ArraySize) {
   int childIndex = 2 * nodeIndex + 1;
   int value = array[nodeIndex];
   int i = 0;

   while (childIndex < ArraySize) {
      // Find the max among the node and all the node's children and initialize the max index
      int maxValue = value;
      int maxIndex = -1;
      // All children are checked before any child key is moved into the parent
      for (i = 0; i < 2 && i + childIndex < ArraySize; i++) {
         if (array[i + childIndex] > maxValue) {
            maxValue = array[i + childIndex];
            maxIndex = i + childIndex;
         }
      }
      if (maxValue == value) {
         return;
      }
      else {
         swap (array[nodeIndex], array[maxIndex]);
         nodeIndex = maxIndex;
         childIndex = 2 * nodeIndex + 1;
      }
   }
}
void heapSort(int array[], int ArraySize) {
   int i = 0;
   // Calls the MaxHeap function to heapify array then builds and sorts the array in reverse
   for (i = ArraySize / 2 - 1; i >= 0; i--) {
      MaxHeapPercolateDown(i, array, ArraySize);
   }
   for (i = ArraySize - 1; i > 0; i--) {
      swap (array[0], array[i]);
      MaxHeapPercolateDown(0, array, i);
   }
}
////////////////////////////////////////////////////////////
//Counting sort  method
////////////////////////////////////////////////////////////

void countSort( int array[], int size ) {
	int max = array[0];
	int* sorted = new int[size + 1];
	int i = 0;

	// Find max element.
	for (i = 0; i < size; ++i) {
		if (array[i] > max) {
			max = array[i];
		}
	}

	// Declare count array and initialize to zero set.
	int* count = new int[max + 1];
	for (i = 0; i <= max; ++i) {
		count[i] = 0;
	}

	// Find and store the count of each element in array.
	for (i = 0; i < size; ++i) {
		count[array[i]]++;
	}
  
  // Update count to have position of element in output.
    for (i = 1; i <= max; ++i) {
      count[i] += count[i - 1];
    }

	// Take index from original array. Use to find element in count array.
	// Copy element into sorted array.
	for (i = size - 1; i >= 0; --i) {
		sorted[count[array[i]] - 1] = array[i];
		count[array[i]]--;
	}

	// Copy sorted array to original array.
	for (int i = 0; i < size; ++i) {
		array[i] = sorted[i];
	}
}
////////////////////////////////////////////////////////////

//Radix sort method
////////////////////////////////////////////////////////////

int getMax( int arr[], int n )
{
	int mx = arr[0];
	for (int i = 1; i < n; i++)
		if (arr[i] > mx)
			mx = arr[i];
	return mx;
}

void helperSort( int arr[], int n, int exp )
{
	int* output = new int[n]; // output array
	int i, count[10] = { 0 };

	// Store count of occurrences in count[]
	for (i = 0; i < n; i++)
		count[(arr[i] / exp) % 10]++;

	// Change count[i] so that count[i] now contains actual
	//  position of this digit in output[]
	for (i = 1; i < 10; i++)
		count[i] += count[i - 1];

	// Build the output array
	for (i = n - 1; i >= 0; i--)
	{
		output[count[(arr[i] / exp) % 10] - 1] = arr[i];
		count[(arr[i] / exp) % 10]--;
	}

	for (i = 0; i < n; i++)
		arr[i] = output[i];
}

void radixSort( int arr[], int n )
{
	int m = getMax( arr, n );

	for (int exp = 1; m / exp > 0; exp *= 10)
		helperSort( arr, n, exp );
}
////////////////////////////////////////////////////////////

typedef chrono::high_resolution_clock Clock;

int main()
{
	// Initialize seed
	srand( (unsigned)time( 0 ) );

	const int numberOfSorts = 7;
	const int sampleSizes[] = { 10, 100, 500, 5000, 25000 };

	int input = 0;
	string algoPicked;

	//Initialize Linked List
	LinkedList list;
	list.getStudentData("students.txt");		

	cout << "1: Bubble" << endl
		<< "2: Insertion" << endl
		<< "3: Merge" << endl
		<< "4: Quick" << endl
		<< "5: Heap" << endl
		<< "6: Counting" << endl
		<< "7: Radix" << endl
		<< "8: Merge - Linked List(First Name)" << endl
		<< "9: Bubble - Linked List(Last Name)" << endl
		<< "10: Quick - Linked List(MNumber)" << endl
		<< "Enter the number of the sort to test: ";

	cin >> input;
	cout << endl;

	//Get sorting direction
	//Output will be reversed if descending is entered, otherwise do nothing
	int sortDirection = 0;		
	if(input == 8 || input == 9 || input == 10)
	{
		cout << "Sort ascending(0) or descending(1)?";
		cin >> sortDirection;
		cout << endl;		
	}

	for (int j = 0; j < sizeof( sampleSizes ) / sizeof( sampleSizes[0] ); ++j)
	{
		//Create random array from sampleSizes[j]
		int* arr = new int[sampleSizes[j]];

		// Populate Array with random integers ranging from 0 to 2n where n is the size of array
		for (int i = 0; i < sampleSizes[j]; i++) {
			arr[i] = (rand() % (2 * sampleSizes[j]));
		}
		

		auto startTime = Clock::now();

		switch (input)
		{
		case 1:
			//Bubble sort
      		bubbleSort(arr, sampleSizes[j]);
			algoPicked = "Bubble";
			break;
		case 2:
			insertionSort( arr, sampleSizes[j] );
			algoPicked = "Insertion";
			break;
		case 3:
			//Merge sort
			mergeSort( arr, 0, sampleSizes[j] - 1 );
			algoPicked = "Merge";
			break;
		case 4:
			//Quicksort
			quickSort( arr, 0, sampleSizes[j] );
			algoPicked = "Quick";
			break;
		case 5:
			//Heap-sort
			heapSort(arr, sampleSizes[j]);
      		algoPicked = "Heap";
			break;
		case 6:
			//Counting sort
			countSort( arr, sampleSizes[j] );
			algoPicked = "Counting";
			break;
		case 7:
			//Radix sort
			radixSort( arr, sampleSizes[j] );
			algoPicked = "Radix";
			break;
		case 8:
			//Mergesort - Linked List
			if(j == 0) 
			{
				//Only gets called on the first loop through
				list.MergeSort(list.getHead());
				algoPicked = "MergeL";
			}
			
			break;
		case 9:
			//Bubblesort - Linked List
			if(j == 0)
			{
				list.BubbleSort();
				algoPicked = "BubbleL";
			}			
			break;
		case 10:
			//Quicksort - Linked List
			if(j == 0)
			{
                list.QuickSort(list.getHead());
				algoPicked = "QuickL";
			}
			break;

		default:
			cout << "Invalid input" << endl;
			break;
		}

		auto endTime = Clock::now();
		
		//Linked List Display
		if(algoPicked == "MergeL" || algoPicked == "BubbleL" || algoPicked == "QuickL")
		{
			if(j == 0)
			{				
				if(sortDirection == 1)
				{
					list.reverse();
				}
				cout << algoPicked << " sort with 50 values: "
				<< chrono::duration_cast<chrono::nanoseconds>(endTime - startTime).count()
				<< " nanoseconds" << endl;

				cout << "Sorted Values: " << endl;
				list.printData();
			}
		}
		else
		{
			cout << algoPicked << " Sort " << "with " << sampleSizes[j] << " values: "
			<< chrono::duration_cast<chrono::nanoseconds>(endTime - startTime).count()
			<< " nanoseconds" << endl;
		}

		

		// cleanup
		delete[] arr;	
		//No point in deleting the linked list
	}

	return 0;
}
