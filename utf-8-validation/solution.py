from typing import List

class Solution:
    def validUtf8(self, data: List[int]) -> bool:
        count = 0
        for string in map(lambda s: format(s, '08b'), data):
            if count > 3:
                return False
            if count:
                if string[:2] == '10':
                    count -= 1
                else:
                    return False
            else:
                for char in string:
                    if char == '0':
                        break
                    count += 1
                if count == 1:
                    return False
                count = max(0, count-1)
        return count == 0