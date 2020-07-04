#include <stdio.h>

//耗时176ms
int removeDuplicates(int* nums, int numsSize)
{
    int count = 1;
    for(int i=0; i < numsSize-count; )
    {
        if(nums[i] == nums[i+1])
        {
            count ++;
            for(int j=i+1; j <= numsSize-count; ++j)
            {
                nums[j]=nums[j+1];
            }
        }
        else
	    {
	     ++i;
	    }
    }
    return numsSize-count+1;
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
    ret = removeDuplicates(&a[0], 10);
    printArray(&a[0],ret);
    return 0;
}


/***
 * 最优解:耗时8ms 
 * int removeDuplicates(int* nums, int numsSize) {
    if(numsSize == 0)
        return 0;
    int i,j = 1;
    for(i = 1;i < numsSize;i++){
        if(nums[i] == nums[i - 1]) 
            continue;
        nums[j++] = nums[i];
        
    }
    return j;
}
***/
