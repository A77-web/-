int removeElement(int* nums, int numsSize, int val)
{
    for(int i=0; i<numsSize; )
    {
        if(nums[i] == val)
        {
            //移动数据进行删除
            for(int k=i; k<numsSize-1; ++k)
                nums[k] = nums[k+1];
            numsSize--;
        }
        else
            i++;
    }
    return numsSize;
}
