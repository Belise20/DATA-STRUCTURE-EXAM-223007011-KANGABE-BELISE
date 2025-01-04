
def quick_sort(data, key):
    if len(data) <= 1:
        return data
    pivot = data[0]
    less = [item for item in data[1:] if item[key] <= pivot[key]]
    greater = [item for item in data[1:] if item[key] > pivot[key]]
    return quick_sort(less, key) + [pivot] + quick_sort(greater, key)

# Example Usage
employees = [{'ID': 1, 'Name': 'John', 'Priority': 3},
             {'ID': 2, 'Name': 'Jane', 'Priority': 1},
             {'ID': 3, 'Name': 'Bob', 'Priority': 2}]
sorted_employees = quick_sort(employees, 'Priority')
print(sorted_employees)
