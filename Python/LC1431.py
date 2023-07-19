class Solution:
    def kidsWithCandies(self, candies: [int], extraCandies: int) -> [bool]:
        result = [False]*len(candies)
        maxCandy = max(candies)

        for i, element in enumerate(candies, start=0):
            if (element + extraCandies) >= maxCandy:
                result[i] = True

        return result