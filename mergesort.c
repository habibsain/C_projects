#include<stdio.h>
#include<stdlib.h>

void arr_cpy(int *arr_from, int num_element, int *arr_to){
    for(int i = 0; i < num_element; i++)
    {
        arr_to[i] = arr_from[i];
    }
}

int *merge(int* a, int l, int m, int r)
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
    return temp;

}

void mergesort(int * arr, int l, int m, int r)
{
    int mid_l = m / 2;
    int mid_r = m + l + 1;

    mergesort(arr, l, mid_l, m);
    mergesort(arr, m + 1, mid_r, r);

    merge(arr, l, m, r);

    
}

int main()
{
    int num = 7;
    int array[7] = {6, 4, 2, 0, 3, 5, 1};
    int l = 0;
    int m = num / 2;
    int r = num - 1;

}