#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void swap(int *x, int *y)
{
    int temp = *x;
    *x = *y;
    *y = temp;
}

void bubbleSort(int arr[], int n)
{
   int i, j;
   for (i = 0; i < n-1; i++)

       for (j = 0; j < n-i-1; j++)
           if (arr[j] > arr[j+1])
              swap(&arr[j], &arr[j+1]);
}

void printArray(int arr[], int size)
{
    int i;
    for (i=0; i < size; i++)
        printf("%d ", arr[i]);
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
    bubbleSort(arr, size);
    printArray(arr, size);
    clock_t t;
    t = clock();
    bubbleSort(arr,size);
    t = clock() - t;
    double time_taken = ((double)t)/CLOCKS_PER_SEC; // in seconds

    printf("bubblesort() took %f seconds to execute \n", time_taken);

    return 0;
}
