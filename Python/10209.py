import sys
import math

for line in sys.stdin:
    r = float(line)
    a = r * r
    z = a * (4 - 2 * math.pi / 3 - math.sqrt(3))
    x = a * (4 - math.pi) - 2 * z
    y = a - x - z
    print("%.3f %.3f %.3f" % (y, x, z))