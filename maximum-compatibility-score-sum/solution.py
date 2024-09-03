from typing import List


class Solution:
    def __init__(self):
        self.total_pairs = 0
        self.res = 0
        self.students = []
        self.mentors = []

    def calculate_sum(self, mentors):
        res = 0
        for i, mentor in enumerate(mentors):
            for s, m in zip(self.students[i], self.mentors[mentor]):
                res += not(s^m)
        return res

    def backtrack(self, student_count, mentors):
        if student_count == self.total_pairs:
            self.res = max(self.res, self.calculate_sum(mentors))
            return
        for i in range(len(self.mentors)):
            if i not in mentors:
                mentors.append(i)
                self.backtrack(student_count+1, mentors)
                mentors.pop()

    def maxCompatibilitySum(self, students: List[List[int]], mentors: List[List[int]]) -> int:
        self.total_pairs = len(students)
        self.students, self.mentors = students, mentors
        self.backtrack(0, [])
        return self.res
