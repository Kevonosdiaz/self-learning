class Solution(object):
    def containsDuplicate(self, nums):
        """
        :type nums: List[int]
        :rtype: bool
        """
        # nums is an array of numbers, which we want to determine if it has any duplicates, at all.
        # Idea 1 : Iterate through every element, then compare with every other element (or every element after it)
        # Idea 2 : Use of some hashmap or set to check membership

        seen_nums = set()

        for num in nums:
            if num in seen_nums:
                return True
            else:
                seen_nums.add(num)

        return False
