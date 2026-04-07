import os

pid_fils = os.fork()
if pid_fils == 0: print("Je suis le fils")
else: print("Je suis le pere")