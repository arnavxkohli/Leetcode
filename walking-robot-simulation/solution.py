from typing import List
from collections import defaultdict


class Solution:
    def robotSim(self, commands: List[int], obstacles: List[List[int]]) -> int:
        if (0, 0) in obstacles: return 0
        obstacles = set([tuple(obstacle) for obstacle in obstacles])
        directions = [(0, 1), (1, 0), (0, -1), (-1, 0)]
        cur_direction = 0
        cur_coordinates = (0, 0)
        furthest = 0
        for command in commands:
            if command == -1:
                cur_direction = (cur_direction + 1) % 4
            elif command == -2:
                cur_direction = (cur_direction + 3) % 4
            else:
                x_inc, y_inc = directions[cur_direction]
                test_x, test_y = cur_coordinates
                for _ in range(command):
                    test_x, test_y = test_x + x_inc, test_y + y_inc
                    if(test_x, test_y) in obstacles:
                        break
                    else:
                        cur_coordinates = (test_x, test_y)
                furthest = max(furthest, cur_coordinates[0] ** 2 + cur_coordinates[1] ** 2)
        return furthest