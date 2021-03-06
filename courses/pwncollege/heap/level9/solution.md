From Ghidra we know &_end is a pointer to 0x430000
and &global is a pointer to 0x420000

```
      if ((allocations[index] < &global) || (&_end < allocations[index])) {
        printf("[*] allocations[%d] = %p\n",(unsigned long)index,allocations[index]);
      } else {
        puts("Invalid allocation detected: discarded!");
        allocations[index] = (char *)0x0;
      }
```

If we allocate memory in between those chunks their pointers in the allocations array are set to null, making us unable to
reach them. However, if we look at the code above we can see a bug causes a deviation from the intended behavior of preventing
allocation between those addresses.


```
pcVar1 = (char *)malloc((unsigned long)size);
allocations[index] = pcVar1;
```

We still allocate the area in memory. The password is at 0x424d61. We can overwrite the password still like in level8, however this time we need at least 19809 bytes to read 0x424d61.