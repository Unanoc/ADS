class Stack:
    def __init__(self):
        self.buffer = []

    def add(self, value):
        self.buffer.append(value)

    def extract(self):
        if len(self.buffer) > 0:
            res = self.buffer[-1]
            self.buffer = self.buffer[:-1]
            return res

    def top(self):
        if len(self.buffer) > 0:
            return self.buffer[-1]
