#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
     #include <time.h>

void Display(int *arr,int size)
{

    int i;
    for(i=0; i<size; i++)
    {

        printf("%d\n",arr[i]);
    }

}

void merge(int *arr,int left,int right,int m)
{

    int i,j,k,n1,n2;
    n1=m-left+1;
    n2=right-m;
    int Larr[n1];
    int Rarr[n2];

    for (i=0; i<n1; i++)
    {

        Larr[i]=arr[left+i];

    }

    for (j=0; j<n2; j++)
    {

        Rarr[j]=arr[m+j+1];
    }

    i=0;
    j=0;
    k=left;

    while(i<n1&&j<n2)
    {


        if(Larr[i]<Rarr[j])
        {

            arr[k]=Larr[i];
            i++;
        }
        else
        {

            arr[k]=Rarr[j];

            j++;

        }
        k++;
    }


    while(i<n1)
    {

        arr[k]=Larr[i];
        i++;
        k++;
    }

    while(j<n2)
    {

        arr[k]=Rarr[j];
        j++;
        k++;
    }
}

void mergeSort(int *arr,int l, int r)
{

    int mid=l+(r-l)/2;

    if(l<r)
    {


        mergeSort(arr, l, mid);
        mergeSort(arr, mid+1, r);

        merge(arr, l, r, mid);
    }

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
    mergeSort(arr,0,size);
    Display(arr,size);
    clock_t t;
    t = clock();
    mergeSort(arr,0,size);
    t = clock() - t;
    double time_taken = ((double)t)/CLOCKS_PER_SEC; // in seconds

    printf("mergesort() took %f seconds to execute \n", time_taken);

    return 0;
}
