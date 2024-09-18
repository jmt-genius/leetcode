class Solution:
    def fourSum(self, nums: List[int], target: int) -> List[List[int]]:
        li=[]
        s=set
        nums.sort()
        for i in range(len(nums)):
            
            for j in range(i+1,len(nums)):
                
                k=j+1
                l=len(nums)-1
                while k<l:
                    sum=nums[i]+nums[j]+nums[k]+nums[l]
                    if sum>target:
                        l-=1
                    elif sum<target:
                        k+=1
                    else:
                        temp=[nums[i],nums[j],nums[k],nums[l]]
                        li.append(temp)
                        k+=1
                        l-=1
        r=[]
        for i in li:
            if i not in r:
                r.append(i)
        return r


        