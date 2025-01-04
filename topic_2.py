
class Node:
    def __init__(self, data):
        self.data = data
        self.next = None

class CircularLinkedList:
    def __init__(self):
        self.head = None

    def append(self, data):
        new_node = Node(data)
        if not self.head:
            self.head = new_node
            self.head.next = self.head
        else:
            temp = self.head
            while temp.next != self.head:
                temp = temp.next
            temp.next = new_node
            new_node.next = self.head

    def display(self):
        nodes = []
        if self.head:
            temp = self.head
            while True:
                nodes.append(temp.data)
                temp = temp.next
                if temp == self.head:
                    break
        return nodes

# Example Usage
cll = CircularLinkedList()
cll.append({'ID': 1, 'Name': 'John', 'Salary': 3000})
cll.append({'ID': 2, 'Name': 'Jane', 'Salary': 3500})
print(cll.display())
