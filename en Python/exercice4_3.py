import os
import sys

tube_l, tube_e = os.pipe()
pid = os.fork()
if pid == 0:
    os.close(tube_e)
    fd = str(tube_l)
    os.execlp("python3", "python3", "fils.py", fd)

else:
    os.close(tube_le)
    os.write(tube_e, b"Bonjour")