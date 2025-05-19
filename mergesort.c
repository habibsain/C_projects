#include<stdio.h>
#include<stdlib.h>

void arr_cpy(int *arr_from, int num_element, int *arr_to){
    for(int i = 0; i < num_element; i++)
    {
        arr_to[i] = arr_from[i];
    }
}

void merge(int* a, int l, int m, int r)
{
    int num_l = l;
    int num_r = m + 1;
    int temp[r - l + 1];
    int i = 0;

    //copy elements to the temp arrays while maintaining an sorting order
    while(num_l <= m && num_r <= r)
    {
        if(a[num_l] <= a[num_r])
        {
            temp[i] = a[num_l];
            i++;
            num_l++;
        }
        else{
            temp[i] = a[num_r];
            i++;
            num_r++;
        }
    }
    while (num_l <= m)
    {
        temp[i] = a[num_l];
        i++;
        num_l++;
    }
    while (num_r <= r)
    {
        temp[i] = a[num_r];
        i++;
        num_r++;
    }

}

void mergesort(int * arr, int num)
{
    int l = 0;
    int r = num - 1;
    int m = r / 2;//gives the floor value after division

    int arr_l[m + 1];
    int arr_r[r - m];

    arr_cpy(arr, m + 1, arr)

    
}