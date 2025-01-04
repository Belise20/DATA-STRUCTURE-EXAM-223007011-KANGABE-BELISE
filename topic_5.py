
import heapq

class DynamicHeap:
    def __init__(self):
        self.heap = []

    def add_salary(self, salary):
        heapq.heappush(self.heap, salary)

    def get_highest(self):
        return heapq.nlargest(1, self.heap)[0] if self.heap else None

# Example Usage
heap = DynamicHeap()
heap.add_salary(3000)
heap.add_salary(4000)
heap.add_salary(3500)
print(heap.get_highest())
