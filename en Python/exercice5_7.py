import threading
import random
import time

u = 1.0
compt = 0
def T1():
    global u, compt
    while True:
        compt += 1
        u = ((u - 1) * (u - 1)) / 4
        print("u(1) =", u)
        time.sleep(random.randint(1, 5))

def T2():
    global u, compt
    while True:
        compt += 1
        u = (u - 2) * (u - 2) / 6
        print("u(2) =", u)
        time.sleep(random.randint(1, 5))

t1 = threading.Thread(target=T1)
t2 = threading.Thread(target=T2)
t1.start()
t2.start()
t1.join()
t2.join()