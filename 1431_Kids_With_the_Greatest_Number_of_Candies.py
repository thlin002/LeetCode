class Solution(object):
    def kidsWithCandies(self, candies, extraCandies):
        """
        :type candies: List[int]
        :type extraCandies: int
        :rtype: List[bool]
        """
        # Find the maximum number of candies among all the kids.
        max = 0
        for candy in candies:
            if candy > max:
                max = candy

        greatestAmongTheKids = []
        for candy in candies:
            if candy + extraCandies >= max:
                greatestAmongTheKids.append(True)
            else:
                greatestAmongTheKids.append(False)

        return greatestAmongTheKids