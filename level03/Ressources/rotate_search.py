import sys

if (len(sys.argv) != 3):
	exit(1)

str1 = sys.argv[1]
str2 = sys.argv[2]

if (len(str1) != len(str2)):
	print("Not same length - no rotation.")
	exit(1)

print("Search rotate gap between ", str1, " - ", str2)

gap = ord(str1[0]) ^ ord(str2[0])

for c1,c2 in zip(str1, str2):
	if (gap != (ord(c1) ^ ord(c2))):
		print("Not same rotation for each character.")
		exit(1)

print("rotation is : ", gap)