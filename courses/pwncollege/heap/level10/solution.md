The memory that stored the password is at 0x428a68 and we cannot allocate before 0x430000(fixing the bug from level 9):

```
      if (local_118[uVar1] < (char *)0x430000) {
        puts("Invalid allocation detected: discarded!");
        local_118[uVar1] = (char *)0x0;
      }
```

