#include <bits/stdc++.h>
using namespace std;

// Binary Search
// Iterative Approach
int binarySearch(int arr[],int n,int x){
    int low=0,high=n-1;
    while(low<=high){
        int mid=(low+high)/2;
        if(arr[mid]==x) return mid;
        else if(arr[mid]>x) high=mid-1;
        else    low=mid+1;
    }
    return -1;
}
// Recursive Approach
int binarySearch(int arr[],int low,int high,int x){
    if(low>high)   return -1;
    int mid=(low+high)/2;
    if(arr[mid]==x)     return mid;
    else if(arr[mid]>x) return binarySearch(arr,low,mid-1,x);
    else return binarySearch(arr,mid+1,high,x);
}

// Ternary search
int ternarySearch(int l, int r, int key, int ar[])
{
    if (r >= l) {
        int mid1 = l + (r - l) / 3;
        int mid2 = r - (r - l) / 3;
        if (ar[mid1] == key) return mid1;
        if (ar[mid2] == key) return mid2;

        if (key < ar[mid1]) return ternarySearch(l, mid1 - 1, key, ar);
        else if (key > ar[mid2]) return ternarySearch(mid2 + 1, r, key, ar);
        else return ternarySearch(mid1 + 1, mid2 - 1, key, ar);
        
    }
    return -1;
}
// merge sort
void merge(int a[],int b[],int m,int n){
    int i=0,j=0;
    while(i<m && j<n){
        if(a[i]<=b[j]){
            cout<<a[i]<< " ";
            i++;
        }
        else{
            cout<<b[j]<< " ";
            j++;
        }
    }
    while(i<m){
        cout<<a[i]<<" ";
        i++;
    }
    while(j<m){
        cout<<b[j]<<" ";
    }
}

// Quick Sort
int partition(int arr[], int low, int high)
{
    int pivot = arr[high];
    int i = (low - 1);
 
    for (int j = low; j <= high - 1; j++) {
        if (arr[j] < pivot) {
            i++;
            swap(arr[i], arr[j]);
        }
    }
    swap(arr[i + 1], arr[high]);
    return (i + 1);
}
void quickSort(int arr[], int low, int high)
{
    if (low < high) {
        int pi = partition(arr, low, high);
        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
}


// External Sort
struct MinHeapNode {
	int element;
	int i;
};
void swap(MinHeapNode* x, MinHeapNode* y);
class MinHeap {
	MinHeapNode* harr;
	int heap_size;
public:
	MinHeap(MinHeapNode a[], int size);
	void MinHeapify(int);
	int left(int i) { return (2 * i + 1); }
	int right(int i) { return (2 * i + 2); }

	MinHeapNode getMin() { return harr[0]; }
	void replaceMin(MinHeapNode x)
	{
		harr[0] = x;
		MinHeapify(0);
	}
};
MinHeap::MinHeap(MinHeapNode a[], int size)
{
	heap_size = size;
	harr = a; // store address of array
	int i = (heap_size - 1) / 2;
	while (i >= 0) {
		MinHeapify(i);
		i--;
	}
}
void MinHeap::MinHeapify(int i)
{
	int l = left(i);
	int r = right(i);
	int smallest = i;
	
	if (l < heap_size && harr[l].element < harr[i].element)
		smallest = l;
	
	if (r < heap_size
		&& harr[r].element < harr[smallest].element)
		smallest = r;
	
	if (smallest != i) {
		swap(&harr[i], &harr[smallest]);
		MinHeapify(smallest);
	}
}
void swap(MinHeapNode* x, MinHeapNode* y)
{
	MinHeapNode temp = *x;
	*x = *y;
	*y = temp;
}
void merge(int arr[], int l, int m, int r)
{
	int i, j, k;
	int n1 = m - l + 1;
	int n2 = r - m;

	int L[n1], R[n2];

	for (i = 0; i < n1; i++)    L[i] = arr[l + i];
	for (j = 0; j < n2; j++)	R[j] = arr[m + 1 + j];

	i = 0; j = 0; k = l;

	while (i < n1 && j < n2) {
		if (L[i] <= R[j])
			arr[k++] = L[i++];
		else
			arr[k++] = R[j++];
	}
	while (i < n1)
		arr[k++] = L[i++];
	while (j < n2)
		arr[k++] = R[j++];
}
void mergeSort(int arr[], int l, int r)
{
	if (l < r) {
		int m = l + (r - l) / 2;
		mergeSort(arr, l, m);
		mergeSort(arr, m + 1, r);

		merge(arr, l, m, r);
	}
}
FILE* openFile(char* fileName, char* mode)
{
	FILE* fp = fopen(fileName, mode);
	if (fp == NULL) {
		perror("Error while opening the file.\n");
		exit(EXIT_FAILURE);
	}
	return fp;
}
void mergeFiles(char* output_file, int n, int k)
{
	FILE* in[k];
	for (int i = 0; i < k; i++) {
		char fileName[2];
		snprintf(fileName, sizeof(fileName), "%d", i);
		in[i] = openFile(fileName, "r");
	}
	FILE* out = openFile(output_file, "w");
	MinHeapNode* harr = new MinHeapNode[k];
	int i;
	for (i = 0; i < k; i++) {
		if (fscanf(in[i], "%d ", &harr[i].element) != 1)
			break;
		harr[i].i = i;
	}
	MinHeap hp(harr, i);

	int count = 0;
	while (count != i) {
		MinHeapNode root = hp.getMin();
		fprintf(out, "%d ", root.element);
		if (fscanf(in[root.i], "%d ", &root.element) != 1) {
			root.element = INT_MAX;
			count++;
		}
		hp.replaceMin(root);
	}
	for (int i = 0; i < k; i++)
		fclose(in[i]);
	fclose(out);
}
void createInitialRuns(char* input_file, int run_size, int num_ways)
{
	FILE* in = openFile(input_file, "r");
	FILE* out[num_ways];
	char fileName[2];
	for (int i = 0; i < num_ways; i++) {
		snprintf(fileName, sizeof(fileName), "%d", i);
		out[i] = openFile(fileName, "w");
	}
	int* arr = (int*)malloc(run_size * sizeof(int));

	bool more_input = true;
	int next_output_file = 0;

	int i;
	while (more_input) {
		for (i = 0; i < run_size; i++) {
			if (fscanf(in, "%d ", &arr[i]) != 1) {
				more_input = false;
				break;
			}
		}
		mergeSort(arr, 0, i - 1);
		for (int j = 0; j < i; j++)
			fprintf(out[next_output_file], "%d ", arr[j]);

		next_output_file++;
	}
	for (int i = 0; i < num_ways; i++)
		fclose(out[i]);
	fclose(in);
}
void externalSort(char* input_file, char* output_file, int num_ways, int run_size)
{
	createInitialRuns(input_file, run_size, num_ways);
	mergeFiles(output_file, run_size, num_ways);
}

// Dynamic Array
class DynamicArray {
private:
	int* array = NULL;
	int size;
	int capacity;

public:
	DynamicArray()
	{
		capacity = 1;
		size = 0;
		array = new int[capacity];
	}
	DynamicArray(int capacity)
	{
		this->capacity = capacity;
		array = new int[capacity];
		size = 0;
	}
	// Returns the size of Array
	// i.e Total elements stored currently
	int getSize() { return size; }

	// Returns the size of container
	int getCapacity() { return capacity; }

	// Inserting element after last stored index
	void push_back(int value)
	{
		// check is array having size to store element or
		// not
		if (size == capacity) {

			// if not then grow the array by double
			growArray();
		}

		// insert element
		array[size] = value;
		// increment the size or last_index+1
		size++;
	}

	// Deleting element at last stored index
	void pop_back()
	{
		// Replace the last index by 0
		array[size - 1] = 0;

		// Decrement the array size
		size--;

		// Reduce if the container half element of its
		// capacity
		if (size == (capacity / 2)) {
			shrinkArray();
		}
	}

	// Increase the array size by double of current capacity
	void growArray()
	{

		// Creating new array of double size
		int* temp = new int[capacity * 2];

		capacity = capacity * 2;
		// copy element of old array in newly created array
		for (int i = 0; i < size; i++) {
			temp[i] = array[i];
		}

		// Delete old array
		delete[] array;

		// Assign newly created temp array to original array
		array = temp;
	}

	// Reduce the size of array by half
	void shrinkArray()
	{

		// Creating new array of half size
		capacity = size;
		int* temp = new int[capacity];

		// copy element of old array in newly created array
		for (int i = 0; i < size; i++) {
			temp[i] = array[i];
		}

		// Delete old array
		delete[] array;

		// Assign newly created temp array to original array
		array = temp;
	}

	// Searching element in the given array
	int search(int key)
	{
		for (int i = 0; i < size; i++) {
			if (array[i] == key) {
				// If element found return its index
				return i;
			}
		}

		// Return -1 if element not found;
		return -1;
	}

	// Insert element at given index
	void insertAt(int index, int value)
	{
		// check is array having size to store element or
		// not
		if (size == capacity) {

			// if not then grow the array by double
			growArray();
		}

		for (int i = size - 1; i >= index; i--) {
			array[i + 1] = array[i];
		}

		array[index] = value;
		size++;
	}

	// Delete element at given index
	void deleteAt(int index)
	{
		for (int i = index; i < size; i++) {
			array[i] = array[i + 1];
		}

		// Replace the last index by 0
		array[size - 1] = 0;

		// Decrement the array size
		size--;

		// Reduce if the container half element of its
		// capacity
		if (size == (capacity / 2)) {
			shrinkArray();
		}
	}

	// To Print Array
	void printArrayDetails()
	{
		cout << "Elements of array : ";
		for (int i = 0; i < size; i++) {
			cout << array[i] << " ";
		}
		cout << endl;
		cout << "No of elements in array : " << size
			<< ", Capacity of array :" << capacity << endl;
	}

	bool isEmpty()
	{
		if (size == 0) {
			return true;
		}
		else {
			return false;
		}
	}
};

int main()
{
	DynamicArray da;

	da.push_back(1);
	da.push_back(2);
	da.push_back(3);
	da.push_back(4);
	da.push_back(5);
	da.push_back(6);
	da.push_back(7);
	da.push_back(8);
	da.push_back(9);
	da.push_back(10);
	da.push_back(11);

	da.printArrayDetails();

	da.shrinkArray();
	cout << "\nCapacity of array after shrinking : "
		<< da.getCapacity() << endl;

	cout << "\nAfter inserting at index 3 " << endl;
	da.insertAt(3, 50);
	da.printArrayDetails();

	cout << "\nAfter delete last element ";
	da.pop_back();
	da.printArrayDetails();

	cout << "\nAfter deleting at index 3 ";
	da.deleteAt(3);
	da.printArrayDetails();

	cout << "\nSearching 5 in array ";
	int index = da.search(5);
	if (index != -1) {
		cout << "Element found at index : " << index << endl;
	}
	else {
		cout << "Element not found " << endl;
	}
	return 0;
}

