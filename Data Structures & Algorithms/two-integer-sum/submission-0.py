class Solution:
    def twoSum(self, nums: List[int], target: int) -> List[int]:
        diferencias = {} #diccionario de diferencias
        for i, num in enumerate(nums):
            diference = target - num
            if num in diferencias:
                return [diferencias[num], i]
            diferencias[diference] = i

