class Solution(object):
    def twoSum(self, nums, target):
        mp={}

        for i,x in enumerate(nums):
            need=target-x

            if need in mp:
                return [mp[need],i]

            mp[x]=i
        