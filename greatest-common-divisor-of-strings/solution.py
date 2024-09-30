class Solution:
    def veryStupidSolution(self, str1: str, str2: str) -> str:
        if len(str1) == len(str2):
            return str1 if str1 == str2 else ""
        if len(str1) < len(str2):
            return self.gcdOfStrings(str2, str1)
        smaller = len(str2)
        while smaller:
            found = True
            check = str2[:smaller]
            for i in range(0, len(str2), smaller):
                if str2[i:i+smaller] != check:
                    found = False
            if not found:
                smaller -= 1
                continue
            for i in range(0, len(str1), smaller):
                if str1[i:i+smaller] != check:
                    found = False
            if found:
                return check
            smaller -= 1
        return ""

    def gcdOfStrings(self, str1: str, str2: str) -> str:
        if len(str1) < len(str2):
            return self.gcdOfStrings(str2, str1)
        def find_gcd(n1, n2):
            while n2:
                n1, n2 = n2, n1%n2
            return n1
        if str1 + str2 != str2 + str1:
            return ""
        return str2[:find_gcd(len(str1), len(str2))]