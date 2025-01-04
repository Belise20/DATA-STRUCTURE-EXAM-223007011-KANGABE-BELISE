
from collections import deque

class PayrollDeque:
    def __init__(self):
        self.deque = deque()

    def add_to_front(self, data):
        self.deque.appendleft(data)

    def add_to_rear(self, data):
        self.deque.append(data)

    def remove_from_front(self):
        return self.deque.popleft() if self.deque else None

    def remove_from_rear(self):
        return self.deque.pop() if self.deque else None

# Example Usage
payroll = PayrollDeque()
payroll.add_to_front({'ID': 3, 'Name': 'Alice', 'Salary': 4000})
payroll.add_to_rear({'ID': 4, 'Name': 'Bob', 'Salary': 4500})
print(list(payroll.deque))
