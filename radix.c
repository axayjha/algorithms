/*
    Radix Sort implementation
    
    Akshay Anand
    5th Sem
    02/09/2017
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 100 // bucket size: max number of elements that can be sorted (if all elements have same value)
#define DIGITS 10 // number of digits in decimal number system. 

struct str_queue
{
    //circular queue to store strings (only their references, not copies)
    int rear, front;
    char *data[MAX]; //array of string pointers
};

typedef struct str_queue strQueue;


void enqueue(strQueue *, char *);
char *dequeue(strQueue *);
void radixsort(int *arr, int n);

int main()
{
    // taking input     
    int n;
    printf("Enter the number of elements to sort: ");
    scanf("%d", &n);
    int arr[n];
    printf("Enter the elements: ");
    for(int i=0; i<n; i++)
        scanf("%d", &arr[i] );
    
    // calling the sort function    
    radixsort(arr, n);

    // printing the sorted array
    printf("Sorted array: ");    
    for(int i=0; i<n; i++)
    {
        printf("%d ",arr[i]);
    }
    printf("\n");
        
}

void radixsort(int *arr, int n)
{
    int digits=0; // to store the numbers of digits in the largest number of the array

    /*since radix sort requires padding with 0 on left,
      i'll work with strings  */

    char *numbers[n]; // array of strings to store the numbers

    for(int i=0; i<n; i++)
    {   
        char temp[16];     
        sprintf(temp, "%d", arr[i]);  // converting integers to strings
        numbers[i]  = (char *)malloc(strlen(temp)*sizeof(char));
        strcpy(numbers[i], temp);  // storing in string array

        if(strlen(numbers[i]) > digits)
            digits = strlen(numbers[i]); // finding the largest number & storing its number of digits
    }

    /* the for loop below just pads the numbers with 0 on left
       an array like : 1, 23, 100, 2378
       will be converted to:  0001, 0023, 0100, 2378     
    */
    for(int i=0; i<n; i++)
    {
        char temp[digits+1];
        for(int j=0; j<digits; j++)
            temp[j] = '0';       
        int pad = digits - strlen(numbers[i]);
        for(int j=pad; j<digits; j++)
        {
            temp[j] = numbers[i][j-pad];
        }
        temp[digits]='\0';
        numbers[i] = (char *)malloc((digits+1)*sizeof(char));
        strcpy(numbers[i], temp);     
    }   

       
    for(int i=digits-1; i>=0; i--)
    {
        // creating a buckets to store the numbers
        strQueue* buckets[DIGITS];
        for(int j=0; j<DIGITS; j++)
        {
            buckets[j] = (strQueue*)malloc(sizeof(strQueue));
            buckets[j]->rear =buckets[j]->front = -1;
        }

        // enqueueing the numbers to the i-th digit valued bucket
        // 2747 will go to 5th bucket (4+1 as its 0-indexed) in second pass (when i=digit-2)
        for(int j=0; j<n; j++)
        {
            char a[] = {numbers[j][i], '\0'}; //converting char to string to use atoi
            enqueue(buckets[atoi(a)], numbers[j]); 
        }      
        
        // dequeueing from buckets
        for(int j=0, index=0; j<DIGITS; j++)                    
            while((buckets[j]->front) != -1)
                numbers[index++]= dequeue(buckets[j]);
        
        // emptying used buckets ;p 
        for(int j=0; j<DIGITS; j++)
           free(buckets[j]);       
    } 

    // storing the string array to the integer array
    for(int i=0; i<n; i++)
    {
        arr[i] = atoi(numbers[i]);
    }
}

void enqueue(strQueue *q, char *str)
{
    
    if(q->front == -1)
    {
        (q->front)++;
        enqueue(q, str);
    }
    else if((q->rear==MAX-1 && q->front==0) || ((q->rear == q->front - 1)  && q->rear!=-1))
    {
              
        printf("Queue full\n");
        return;
    }

    else if((q->rear==MAX-1) && (q->front!=0))
    {
        q->rear = -1;
        enqueue(q, str);
    }

    else q->data[++(q->rear)] = str;
}

char *dequeue(strQueue *q)
{
    if(q->front == -1)
    {
        printf("Queue empty\n");
        return NULL;
    }
    else if(q->front == q->rear)
    {
        char *res = q->data[q->front];
        q->rear= -1; q->front = -1;
        return res;
    }

    else if(q->front == MAX-1)
    {
        q->front=0;
        return q->data[MAX-1];
    }

    else 
        return q->data[(q->front)++];
}
