class Solution:
    def __init__(self):
        self.expression = ''

    def parse_num(self, ptr):
        ptr += 1
        num = ''
        while ptr < len(self.expression) and self.expression[ptr].isdigit():
            num += self.expression[ptr]
            ptr += 1
        return int(num), ptr

    def gcd(self, num1, num2):
        gcd = 1
        for i in range(1, min(num1, num2) + 1):
            if num1 % i == 0 and num2 % i == 0:
                gcd = i
        return gcd

    def fractionAddition(self, expression: str) -> str:
        self.expression = expression
        fractions = []
        total_den = 1
        if self.expression[0] != '-':
            self.expression = '+' + self.expression
        ptr = 0
        while ptr < len(self.expression):
            sign = self.expression[ptr]
            num, ptr = self.parse_num(ptr)
            den, ptr = self.parse_num(ptr)
            if total_den % den: total_den *= den
            fractions.append([int(f'{sign}1'), num, den])
        num_sum = 0
        for sign, num, den in fractions:
            num_sum += sign * num * (total_den // den)
        if num_sum == 0: return '0/1'
        gcd = self.gcd(abs(num_sum), total_den)
        return f'{num_sum//gcd}/{total_den//gcd}'