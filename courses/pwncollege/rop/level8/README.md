```
0x210a7fa70a232320:     Cannot access memory at address 0x210a7fa70a232320   
```   
For some reason rdx gets overwritten with
```
##\n\x11\x7f\n!
from 
Welcome to ./%s!
###
```
So for now I'm skipping this level

The concept is that you have a ROP gadget
print an address from plt and use that to find the offset to bypass ASLR and then call a gadget
to cat the flag.

Info registers before main()
Can't call read() b/c we don't know know stack address or have a syscall gadget
```
rax            0x40253c            4203836
rbx            0x402700            4204288
rcx            0x402700            4204288
rsi            0x7fffffffe618      140737488348696
rdi            0x1                 1                                                                                               │>>> p64( 0x94fb300a )
rbp            0x0                 0x0
rsp            0x7fffffffe528      0x7fffffffe528
r8             0x0                 0
r9             0x7ffff7fe0d50      140737354009936
r10            0x0                 0
r11            0x0                 0
r12            0x401190            4198800
r13            0x7fffffffe610      140737488348688
r14            0x0                 0                                                                                               r15            0x0                 0
rip            0x40253c            0x40253c <main>
eflags         0x246               [ PF ZF IF ]
cs             0x33                51
ss             0x2b                43
ds             0x0                 0
es             0x0                 0
fs             0x0                 0
gs             0x0                 0
```