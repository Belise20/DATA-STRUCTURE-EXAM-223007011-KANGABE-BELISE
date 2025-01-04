
class TreeNode:
    def __init__(self, data):
        self.data = data
        self.children = []

    def add_child(self, child):
        self.children.append(child)

    def display(self, level=0):
        print(' ' * level * 4 + str(self.data))
        for child in self.children:
            child.display(level + 1)

# Example Usage
root = TreeNode({'ID': 1, 'Name': 'CEO'})
dept1 = TreeNode({'ID': 2, 'Name': 'Manager A'})
dept2 = TreeNode({'ID': 3, 'Name': 'Manager B'})
root.add_child(dept1)
root.add_child(dept2)
dept1.add_child(TreeNode({'ID': 4, 'Name': 'Employee A1'}))
dept2.add_child(TreeNode({'ID': 5, 'Name': 'Employee B1'}))
root.display()
