Looking at the source code the goal is to
overwrite the first byte of the part of the
heap containing the flag, 
then the program will print the flag


First we start off with the wilderness
then we allocate 2 chunks of 456 bytes
the pointers to these chunks are stored
in an array at indexes 0 and 1
(I am representing the array of pointers
as the memory the pointers are pointing to
not the actual pointers)


```
+-------+-------+
  456   |  456  |
+-------+-------+
```


Then we free the memory pointed to by the second pointer
so we can read the flag into there
We know the flag will be written there
because the chunk is the perfect size and 
the pt memory allocator likes optimizing

```
+-------+-------+
  456   | flag  |
+-------+-------+
```


Then we free both chunks of the heap.
We know the data is still the same 
after we free the pointers.
We can then overwrite the next chunk
where the flag is by allocating 458 bytes
to the first chunk, overwriting the old beginning
of the second chunk with the flag.


```
+-------+-------+
    458   | flag|
+-------+-------+
```

Now we have changed the flag
so the program will give us the flag.
And there was much rejoicing.