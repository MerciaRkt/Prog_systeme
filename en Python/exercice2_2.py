import os
import sys

pid_fils1 = os.fork()
if pid_fils1 == 0:
    print("Je suis le fils 1")
    sys.exit(0)

pid_fils2 = os.fork()
if pid_fils2 == 0: print("Je suis le fils 2")
if (pid_fils1 != 0) and (pid_fils2 != 0): print("Je suis le pere")