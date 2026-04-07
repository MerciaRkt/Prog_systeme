import os

for i in range(5):
    pid_fils = os.fork()
    if pid_fils == 0: break