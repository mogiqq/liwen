import re

s = "One fish. Two fish. Red fish. Blue fish."

print(len(re.findall(r'[.|?|!]', s)))
