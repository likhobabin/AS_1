#include <iostream>
//

static void InsertionSort(int* /*array*/, unsigned int /*count*/);
//
static void MergeSort(int* /*array*/, unsigned int /*p*/, unsigned int /*q*/);
static void SetMerge(int* /*array*/, unsigned int /*p*/, unsigned int /*q*/, unsigned int /*r*/);
//

int main(int argc, char** argv)
{
    int array1[] = {9, 0, -19, 8, 8, 1, -1, 10, -100};
    unsigned int count = sizeof (array1) / sizeof (array1[0]);
    //

    InsertionSort(array1, count);
    //
    int array2[] = {9, 0, -19, 8, 8, 1, -1, 10, -100};
    count = sizeof (array2) / sizeof (array2[0]);
    //
    MergeSort(array2, 0, count-1);
    
    return 0;
}

static void InsertionSort(int* array, unsigned int count)
{
    for (unsigned int notSortIdx = 1; count > notSortIdx; notSortIdx++)
    {
        int key = array[notSortIdx];
        int sortIdx = notSortIdx - 1;
        //
        while (0 <= sortIdx && array[sortIdx] > key)
        {
            array[sortIdx + 1] = array[sortIdx];
            sortIdx = sortIdx - 1;
        }
        array[sortIdx + 1] = key;
    }
}
//

static void MergeSort(int* array, unsigned int l, unsigned int r)
{
    std::cout<<"+++l"<<l<<"+++r"<<r<<"\n";
    unsigned int c=0x0;
    if(l<r)
    {
        c = (r+l)/2;
    
    }
    else
        return;
    //
    MergeSort(array, l, c);
    //
    MergeSort(array, c+1, r);
    //
    //
    SetMerge(array, l, c, r);
}
//

static void SetMerge(int* array, unsigned int l, unsigned int c, unsigned int r)
{
    int a1[c - l+1];//1
    int a2[r - c];//1
    unsigned int i = 0x0;
    unsigned int idx = 0x0;
    //
    for (i=0x0, idx=l; (c + 1) > idx; idx++, i++)
    {
        a1[i] = array[idx];
        std::cout<<a1[i]<<"\n";
    }
    //
    std::cout<<"******\n";
    //
    for (i = 0x0, idx=c+1; r >= idx; i++, idx++)
    {
        a2[i] = array[idx];
        std::cout<<a2[i]<<"\n";
    }
    //
    unsigned int j = 0x0;
    unsigned int k = 0x0;
    //
    std::cout<<"******\n";
    //
    for (i = l; r >= i; i++)
    {
        if(( c-l + 1 > j) && ((r-c > k && a1[j] <= a2[k]) || ( r-c<=k) ))
        {
            array[i] = a1[j];
            j = j + 1;
        }
        else
            if ((r - c) > k)
        {
            array[i] = a2[k];
            k = k + 1;
        }
        std::cout<<array[i]<<"\n";
    }
    std::cout<<"******\n";
}
//