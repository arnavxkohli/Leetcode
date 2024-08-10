class TimeMap:

    def __init__(self):
        self.time_map = {}

    def set(self, key: str, value: str, timestamp: int) -> None:
        if key not in self.time_map:
            self.time_map[key] = [(value, timestamp)]
        else:
            self.time_map[key].append((value, timestamp))

    def get(self, key: str, timestamp: int) -> str:
        if key not in self.time_map: return ''
        search_space = self.time_map[key]
        l, r = 0, len(search_space)-1
        while l <= r:
            mid = l + (r-l)//2
            cur_val, cur_time = search_space[mid]
            if cur_time == timestamp: return cur_val
            if cur_time < timestamp: l = mid + 1
            else: r = mid - 1
        cur_val, cur_time = search_space[r]
        return '' if cur_time > timestamp else cur_val