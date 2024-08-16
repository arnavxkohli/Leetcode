from typing import List

class Solution:
    def fullJustify(self, words: List[str], maxWidth: int) -> List[str]:
        lines = []
        curr_length = 0
        line = []
        for word in words:
            if len(line) == 0:
                line.append(word)
                curr_length = len(word)
            elif curr_length + len(word) + 1 <= maxWidth:
                curr_length += 1 + len(word)
                line.append(word)
            else:
                lines.append(line)
                line = [word]
                curr_length = len(word)
        if len(line) > 0: lines.append(line)
        for i, line in enumerate(lines):
            res = ''
            if len(line) == 1 or i == len(lines)-1:
                for string in line:
                    res += string + ' '
                lines[i] = res.rstrip() + ' ' * (maxWidth + 1 - len(res))
            else:
                total_spaces = maxWidth - sum([len(string) for string in line])
                spaces = [total_spaces//(len(line)-1)] * (len(line)-1)
                ptr = 0
                while total_spaces%(len(spaces)):
                    spaces[ptr%len(spaces)] += 1
                    total_spaces, ptr = total_spaces-1, ptr+1
                for j, string in enumerate(line):
                    res += string
                    if j < len(spaces):
                        res += ' ' * spaces[j]
                lines[i] = res
        return lines
