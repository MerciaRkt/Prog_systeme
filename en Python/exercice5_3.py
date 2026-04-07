import threading
import random
import sys

class TypeTableau:
    def __init__(self, n, x):
        self.tab = [0] * 100
        self.n = n
        self.x = x
result = None

def fonction1(t):
    for i in range(t.n):
        t.tab[i] = random.randint(0, 99)

def fonction2(t):
    global result
    trouve = 0
    for i in range(t.n):
        if t.tab[i] == t.x:
            trouve = 1
    result = trouve


n = int(sys.argv[1])
x = int(input("entrez x : "))
t = TypeTableau(n, x)
thread1 = threading.Thread(target=fonction1, args=(t,))
thread1.start()
thread1.join()
thread2 = threading.Thread(target=fonction2, args=(t,))
thread2.start()
thread2.join()
print(result)