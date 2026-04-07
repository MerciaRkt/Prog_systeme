import os
import sys
os.execl("/bin/cp", "cp", "-r", ".", sys.argv[1])