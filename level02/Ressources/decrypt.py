import sys

if (len(sys.argv) != 2):
	exit(1)

str = sys.argv[1]

reverse_str = ""

for s in str.split("0x"):
	if (s == ""):
		continue
	# print("little endian\t", s)

	bytes_list = [s[i:i+2] for i in range(0, len(s), 2)]
	# list comprehension - meaning :
	# bytes_list = []
	# for i in range(0, len(s), 2)
		# bytes_list.append(s[i:i+2])

	reverse_bytes = bytes_list[::-1]
	# print("big endian\t", ''.join(reverse_bytes), "\n")

	reverse_str += ''.join(reverse_bytes)
	# print(reverse_str, "\n")

decrypt_str = bytes.fromhex(reverse_str).decode("ascii")

print(decrypt_str)
