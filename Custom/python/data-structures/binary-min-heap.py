class Heap:
    def __init__(self):
        self.buffer = []

    def _get_parent(self, index):
        return (index - 1) // 2
    
    def _get_left_child(self, index):
        return 2 * index + 1

    def _get_right_child(self, index):
        return 2 * index + 2

    def _sift_up(self, index):
        while index: # while index != 0
            parent = self._get_parent(index)

            if self.buffer[parent] < self.buffer[index]:
                return
            
            self.buffer[parent], self.buffer[index] = self.buffer[index], self.buffer[parent]
            index = parent
    
    def _sift_down(self, index):
        left = self._get_left_child(index)
        right = self._get_right_child(index)

        smallest = index

        if left < len(self.buffer) and self.buffer[left] < self.buffer[smallest]:
            smallest = left
        if right < len(self.buffer) and self.buffer[right] < self.buffer[smallest]:
            smallest = right

        if smallest != index:
            self.buffer[smallest], self.buffer[index] = self.buffer[index], self.buffer[smallest]
            self._sift_down(smallest)

    def add(self, value):
        self.buffer.append(value)
        self._sift_up(len(self.buffer)-1)

    def get_min(self):
        if len(self.buffer) == 0:
            return -1

        return self.buffer[0]

    def extract_min(self):
        if len(self.buffer) == 0:
            return -1

        minimum = self.buffer[0]

        self.buffer[0] = self.buffer[-1]
        self.buffer = self.buffer[:-1]

        if not len(self.buffer) == 0:
            self._sift_down(0)

        return minimum


heap = Heap()
heap.add(9)
heap.add(6)
heap.add(5)
heap.add(4)
heap.add(4)
heap.add(1)
heap.add(0)

while len(heap.buffer) != 0:
    print(heap.extract_min())


