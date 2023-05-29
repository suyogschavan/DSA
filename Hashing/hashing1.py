class HashTable:
    def __init__(self, m) -> None:
        self.MAX = m
        self.arr = [[] for i in range(self.MAX)]
    
    def get_hash(self, key):
        hash = 0
        for number in key:
            hash += ord(number)
        return hash%self.MAX
    
    def __getitem__(self, index):
        h=self.get_hash(index)
        return self.arr[h]
    
    def __setitem__(self, key, val):
        h = self.get_hash(key)
        self.arr[h] = val

t = HashTable(10)
print(t.get_hash("8080808080"))
print(t.get_hash("8080808081"))
print(t.get_hash("80808085"))