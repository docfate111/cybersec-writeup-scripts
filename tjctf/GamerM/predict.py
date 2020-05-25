from pwn import *
import random, time
from randcrack import RandCrack
rps = ['rock', 'paper', 'scissors']
def shuffle(s):
	for i in range(len(s)):
		j = random.randint(0, len(s) - 1)
		s[i], s[j] = s[j], s[i]
	return s
def response(crit):
    if(crit=='rock'):
        return 'paper'
    else:
        if(crit=='paper'):
            return 'scissors'
        else:
            return 'rock'
def main():
    names = [i.strip() for i in open('names.txt').readlines()]
    t0 = time.clock()
    # connect to server and get output
    conn = remote('p1.tjctf.org', 8007) 
    # read ouput and guess rock, paper, or scissors correctly via randcrack
    # use names index within names.txt to find out index of each associated letter
    # use indeces to combine letters into the flag
    diff = time.clock() - t0
    while True:
        cracker = RandCrack()
        random.seed(time.time()+diff)
        for i in range(624):
            cracker.submit(random.getrandbits(32))
        crit = rps[cracker.predict_randint(0, 2)]
        s = conn.recvuntil('Choice: ', drop=True)
        print(s[s.find('Choose'):])
        resp = response(crit)
        conn.sendline(resp)
        print('Program chose: '+resp)
        s = conn.recvline()
        if 'Sucess!' not in s:
            print(conn.recvline(timeout=2))
            break
        print(conn.recvuntil('You', drop=True))
    conn.close()
'''
for i in range(624):
	rc.submit(random.getrandbits(32))
	# Could be filled with random.randint(0,4294967294) or random.randrange(0,4294967294)
print("Random result: {}\nCracker result: {}"
	.format(random.randrange(0, 4294967295), rc.predict_randrange(0, 4294967295)))
	names = shuffle([i.strip() for i in open('names.txt').readlines()])
	match = [(names[i], flag[i]) for i in range(len(flag))]
	levels = shuffle([shuffle(match[::5]), shuffle(match[1::5]), shuffle(match[2::5]), shuffle(match[3::5]), shuffle(match[4::5])])
'''
main()