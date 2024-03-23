class Solution(object):
    def gcdOfStrings(self, str1, str2):
        """
        Compute the GCD of the strings using the same concept from the Euclidean algorithm

        :type str1: str
        :type str2: str
        :rtype: str
        """
        if len(str1) > len(str2):
            s_a = str1
            s_b = str2
        else:
            s_a = str2
            s_b = str1

        l_a = len(s_a)
        l_b = len(s_b)
        q = l_a/l_b

        # For s_b to be a reasonable divisor of s_a, it needs to be a substring of s_a
        if s_a[0:l_b*q] == s_b*q:
            if l_b*q == l_a:
                # if s_b could completly divide s_a, then it s_b is the gcd.
                return s_b
            else:
                # get the remainder
                s_c = s_a[len(s_b)*q:]
                return self.gcdOfStrings(s_b, s_c)
        else:
            # If s_b is not a substring of s_a, then there is no common gcd of s_a and s_b.
            return ""