import os
import time
import random

debut = time.time()
fils1 = os.fork()
if fils1 == 0:
    random.seed(os.getpid())
    n = random.randint(1, 10)
    time.sleep(n)
    os._exit(0)

fils2 = os.fork()
if fils2 == 0:
    random.seed(os.getpid())
    n = random.randint(1, 10)
    time.sleep(n)
    os._exit(0)
# le père attend les deux fils
os.wait()
os.wait()
print("Duree totale =", int(time.time() - debut), "secondes")