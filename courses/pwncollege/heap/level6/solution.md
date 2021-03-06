From looking at the source code for the ptmalloc implementation in malloc.c:


```
/* We overlay this structure on the user-data portion of a chunk when
           the chunk is stored in the per-thread cache.  */
         typedef struct tcache_entry
         {
           struct tcache_entry *next;
         } tcache_entry;
        
         /* There is one of these for each thread, which contains the
            per-thread cache (hence "tcache_perthread_struct").  Keeping
            overall size low is mildly important.  Note that COUNTS and ENTRIES
            are redundant (we could have just counted the linked list each
            time), this is for performance reasons.  */
         typedef struct tcache_perthread_struct
         {
           char counts[TCACHE_MAX_BINS];
           tcache_entry *entries[TCACHE_MAX_BINS];
         } tcache_perthread_struct;


            /* Caller must ensure that we know tc_idx is valid and there's
           available chunks to remove.  */
        static __always_inline void *
        tcache_get (size_t tc_idx)
        {
          tcache_entry *e = tcache->entries[tc_idx];
          assert (tc_idx < TCACHE_MAX_BINS);
          assert (tcache->entries[tc_idx] > 0);
          tcache->entries[tc_idx] = e->next;
          --(tcache->counts[tc_idx]);
          return (void *) e;
        }
```

1. Allocate 2 16 bytes chunks with their pointers at index 0 and 1 in allocations - 
an array of pointers


2. Free the memory they point to so the chunks are each of size 16. This creates 2
32 byte fastbins.

```
(gdb) heap bins (using gef plugin)
[+] No Tcache in this version of libc
───────────────────────────────────────────────────────────── Fastbins for arena 0x7ffff7dd1b20 ─────────────────────────────────────────────────────────────
Fastbins[idx=0, size=0x20]  ←  Chunk(addr=0x430830, size=0x20, flags=PREV_INUSE)  ←  Chunk(addr=0x430850, size=0x20, flags=PREV_INUSE) 
Fastbins[idx=1, size=0x30] 0x00
Fastbins[idx=2, size=0x40] 0x00
Fastbins[idx=3, size=0x50] 0x00
```


3. Write the address of the variable to read into memory pointed to by allocations[0]


```
(gdb) heap chunks
Chunk(addr=0xfe1010, size=0x410, flags=PREV_INUSE)
[0x0000000000fe1010     5b 2a 5d 20 46 75 6e 63 74 69 6f 6e 20 28 6d 61   
[*] Function (ma]
Chunk(addr=0xfe1420, size=0x1010, flags=PREV_INUSE)
[0x0000000000fe1420     73 63 61 6e 66 0a 30 0a c6 99 42(next pointer overwritten) 00 00 00 00 00   
Chunk(addr=0xfe2430, size=0x20, flags=PREV_INUSE)
    [0x0000000000fe2430     c6 99 42(fake chunk with address of variable) 00 00 00 00 00 00 00 00 00 00 00 00 00   
 ..B.............]
Chunk(addr=0xfe2450, size=0x20, flags=PREV_INUSE)
    [0x0000000000fe2450     00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00   
 ................]
Chunk(addr=0xfe2470, size=0x1fba0, flags=PREV_INUSE)  ←  top chunk
```


4. Allocate 2 16 bytes chunks and save their pointers in address 2 and 3


```
Fastbins[idx=0, size=0x20]  ←  Chunk(addr=0x4299d6, size=0x0, flags=) [incorrect fastbin_index](corrupted next address created fake fast bin)
Fastbins[idx=1, size=0x30] 0x00
```

5. Print the pointer at index 3 - which is actually the variable
