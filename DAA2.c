#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<limits.h>

void selection_sort(int arr[],int size) {
    for(int i=0;i<size-1;i++) {
        int min=i;
        for(int j=i+1;j<size;j++) 
            if(arr[j]<arr[min])
                min = j;
        int temp = arr[min];
        arr[min] = arr[i];
        arr[i] = temp;
    }

}

void insertion_sort(int arr[],int n) {
    int i,key,j;
    for(int i=1;i<n;i++) {
        key = arr[i];
        j=i-1;
        while(j>=0 && arr[j]>key) {
            arr[j+1] = arr[j];
            j=j-1;
        }
        arr[j+1] = key;
    }
}

void main() {
    FILE *filep;
    filep  = fopen ("exp1b.txt", "w");
    srand((unsigned int) time(NULL));
    for(int block=0;block<1000;block++) {
        for(int i=0;i<100;i++) {
            int number = (int)(((float) rand() / (float)(RAND_MAX))*100000);
            fprintf(filep,"%d ",number);
        }
        fputs("\n",filep);
    }
    fclose (filep);
    filep = fopen("exp1b.txt", "r");
   printf("Block\tSelection Sort Time(ms)\tInsertion Sort Time(ms)\n");
   for(int block=0;block<1000;block++) {
    clock_t t1,t2;
    int arr[(block+1)*100];
    int arr1[(block+1)*100];
    for(int i=0;i<(block+1)*100;i++){
        fscanf(filep, "%d", &arr[i]);
        arr1[i] = arr[i];
    }
    fseek(filep, 0, SEEK_SET);
    t1 = clock();   
    selection_sort(arr,(block+1)*100);
    t1 = clock() - t1;

    t2 = clock();
    insertion_sort(arr1,(block+1)*100);
    t2 = clock() - t2;

    double selection_sort_time = ((double)t1)/CLOCKS_PER_SEC; 
    double insertion_sort_time = ((double)t2)/CLOCKS_PER_SEC;
    
    printf("%d\t%f\t\t\t%f\n",(block+1),selection_sort_time,insertion_sort_time);
   }
    fclose(filep);
}
