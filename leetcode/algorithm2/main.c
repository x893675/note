#include <stdio.h>


int singleNumber(int* nums, int numsSize) {
    for(int i=0; i < numsSize; ++i)
    {
        for (int j = i+1; j< numsSize-1; ++j)
        {
            if (nums[i] ^ nums[j] == 0)
            {
                nums[i] = 0;
                nums[j] = 0;
                break;
            }
        }
    }
}

void printArray(int *nums, int numsSize)
{
    for(int i=0; i < numsSize; ++i)
    {
        printf("%d,%d\n",i,nums[i]);
    }
}

int main()
{
    int a[10] = {0,0,1,1,1,2,2,3,3,4};
    int ret;
    ret = singleNumber(&a[0], 10);
    printArray(&a[0],ret);
    return 0;
}
