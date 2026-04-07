import threading
import random
import time

N = 100
tab = [0] * N
for i in range(1, N-1):
    tab[i] = random.randint(0, 100)

def fonc1():
    while True:
        for i in range(1, N-1):
            tab[i] = (tab[i-1] + tab[i] + tab[i+1]) // 3
        time.sleep(random.randint(1, 3))

def fonc2():
    while True:
        for i in range(N):
            print(f"tab[{i}] = {tab[i]}")
        time.sleep(4)

t1 = threading.Thread(target=fonc1)
t2 = threading.Thread(target=fonc2)
t1.start()
t2.start()
t1.join()
t2.join()