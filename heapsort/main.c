#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
     #include <time.h>


void maxheapify(int arr[], int n, int i)
    {
        int largest = i; // Initialize largest as root
        int l = 2*i + 1; // left = 2*i + 1
        int r = 2*i + 2; // right = 2*i + 2

        // If left child is larger than root
        if (l < n && arr[l] > arr[largest])
            largest = l;

        // If right child is larger than largest so far
        if (r < n && arr[r] > arr[largest])
            largest = r;

        // If largest is not root
        if (largest != i)
        {
            int swap = arr[i];
            arr[i] = arr[largest];
            arr[largest] = swap;

            // Recursively heapify the affected sub-tree
            maxheapify(arr, n, largest);
        }
    }
 void buildmaxheap(int arr[], int n)
    {//rearrange array
      for (int i = n / 2 - 1; i >= 0; i--)
        maxheapify(arr, n, i);
}
void heapsort(int arr[], int n){
        int i;
       int r = 2*i + 2;
   buildmaxheap(arr,r+1);
for ( i=n-1; i>=0; i--)//extract element by element from heap
    {
        // Move current root to end
            int temp = arr[0];
            arr[0] = arr[i];
            arr[i] = temp;
        // call max heapify on the reduced heap
        maxheapify(arr, i, 0);

}}
  void printArray(int arr[], int n)
{
    for (int i=0; i<n; i++)
        printf("%d \n",arr[i]) ;
    printf("\n");
}
int readfile(int arr[],char*filename){
  FILE*fp= fopen(filename,"r");
if(fp==NULL){
    printf("not found");
return;
}
else if (ftell(fp)!=0)
    {
        printf("empty\n");
        fclose(fp);
        return;
    }
    else{int i=0;
    while(!feof(fp)) {
        fscanf(fp, "%d", &arr[i++]);

        }
return i;
    }
}


int main()
{
   int arr[500000];
   int size=readfile(arr,"file1.txt");
    heapsort(arr,size);
    printArray(arr, size);
    clock_t t;
    t = clock();
    heapsort(arr,size);
    t = clock() - t;
    double time_taken = ((double)t)/CLOCKS_PER_SEC; // in seconds

    printf("heapsort() took %f seconds to execute \n", time_taken);
}


