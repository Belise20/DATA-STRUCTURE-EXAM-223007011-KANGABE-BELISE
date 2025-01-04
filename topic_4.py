
import heapq

class FixedOrderHeap:
    def __init__(self, max_size):
        self.heap = []
        self.max_size = max_size

    def add_order(self, order):
        if len(self.heap) < self.max_size:
            heapq.heappush(self.heap, order)
        elif order > self.heap[0]:
            heapq.heapreplace(self.heap, order)

    def get_orders(self):
        return sorted(self.heap)

# Example Usage
heap = FixedOrderHeap(3)
heap.add_order(1000)
heap.add_order(2000)
heap.add_order(1500)
heap.add_order(1200)
print(heap.get_orders())
