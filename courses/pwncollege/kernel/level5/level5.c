undefined8 device_ioctl(undefined8 fd,uint request,ulong *params){
  undefined8 i; 
  printk(&DAT_00100728,fd,(ulong)request,params);
  i = 0xffffffffffffffff;
  if (request == 0x539) {
    i = 0xfffffffffffffffe;
    if (*params < 0x1001) {
      _copy_from_user(shellcode,params + 1);
      __x86_indirect_thunk_rax();
      i = 0;
    }
  }
  return i;
}
