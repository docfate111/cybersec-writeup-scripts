#!/bin/sh
echo 'Fix error while loading shared libraries: libcapstone.so.5: cannot open shared object file: No such file or directory'
sudo apt install -y libcapstone-dev
cp /usr/lib/x86_64-linux-gnu/libcapstone.so.3 /usr/lib/x86_64-linux-gnu/libcapstone.so.5