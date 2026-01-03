class queue:
    def __init__(self):
        self.items = []

    def is_empty(self):
        return len(self.items) == 0

    def insert(self, item):
        item=str(item)
        self.items.append(item)

    def pop(self):
        if not self.is_empty():
            return self.items.pop(0)
        print("Warning: cannot pop from an empty queue.")
        return None


