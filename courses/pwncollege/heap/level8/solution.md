same as level 6 except the address begins with 0x0a (newline)
in little endian - newline is "ASCII hardened"


We could either move to a later address that doesn't start with
a bad character and brute force the missing bytes


scanf("%0s") - An optional nonzero decimal integer that specifies the maximum field width (in characters).
Since this is undefined behavior the binary ignores the 0 allowing us to scanf any amount of characters.


We can use this to cause a buffer overflow and overwrite the memory strcmp checks against to be all A's
so the password we give for the flag is all A's.
