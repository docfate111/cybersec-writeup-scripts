# ARM-challenges
Protostart Stack Overflow Challenges compiled for ARMv6.

rpi.sh is the script that installs and runs a raspberry pi QEMU emulator on MacOS
https://azeria-labs.com/part-3-stack-overflow-challenges/

The script runs with ssh to the target open on port 5022

```
ssh pi@localhost -p 5022
```
default raspberry pi creds are user: pi and password: raspberry

I realized these are protostar challenges exactly copied and compiled
after solving the first two without pwntools or the C source code 
(the site does say "inspired by protostar" but I thought changes were made

Also I tried using Docker and qemu and both were unable to install pwntools, 
so I ended up using Bash and plain Python.
