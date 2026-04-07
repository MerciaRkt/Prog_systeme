import threading
import random

result = None
def fonction():
    global result
    tab = [random.randint(0, 99) for _ in range(10)]
    result = tab

thread = threading.Thread(target=fonction)
thread.start()
thread.join()
print(result)