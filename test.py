#!/usr/bin/python
import subprocess
import random
s=subprocess.Popen("./b1",stdin=subprocess.PIPE,stdout=subprocess.PIPE,stderr=subprocess.PIPE)
s.stdin.write('1')
s.stdin.write('1 1')
s.stdin.write('1')
print s.stdout.read()


