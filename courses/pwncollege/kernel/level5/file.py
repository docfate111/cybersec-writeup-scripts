x = b''
with open('f', 'rb') as f:
	byte = f.read(1)
	while(byte):
		x += byte
		byte = f.read(1)
print(x)
print(len(x))
