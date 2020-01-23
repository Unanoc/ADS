class Queue:
    def __init__(self, cap=5):
        self.cap = cap
        self.size = 0
        self.buffer = []

    def push(self, value):
        if self.size < self.cap:
            if self.size == 0:
                self.buffer.append(value)
                self.head, self.tail = 0, 1
                return

            if self.head < self.tail:
                if self.tail < len(self.buffer):
                    self.buffer.append(value)
                    self.tail += 1
                else:
                    self.buffer[0]
                    self.tail = 1
                return

            if self.head > self.tail:
                self.buffer[self.tail] = value
                self.tail += 1
                return
        else:
            tmp = []
            if self.head < self.tail:
                tmp.extend(self.buffer)
            else:
                tmp.extend(self.buffer[self.head:])
                tmp.extend(self.buffer[:self.tail])

            self.buffer = tmp
            self.cap = self.cap * 2
            self.buffer.append(value)
            self.size = len(tmp) + 1
