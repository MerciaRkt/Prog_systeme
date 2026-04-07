import threading
import time
import random
s1 = threading.Semaphore(1)
s2 = threading.Semaphore(0)
def T1():
    for i in range(10):
        s1.acquire()
        print("T1")
        time.sleep(2)
        s2.release()

def T2():
    for i in range(10):
        s2.acquire()
        print("T2")
        time.sleep(random.randint(4, 9))
        s1.release()

t1 = threading.Thread(target=T1)
t2 = threading.Thread(target=T2)
t1.start()
t2.start()
t1.join()
t2.join()