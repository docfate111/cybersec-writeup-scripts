import random
import itertools
import functools
A=bool
N=ord
y=sorted
Y=list
h=bin
T=int
e=range
F=len
L=open
O=repr
R=random.shuffle
D=functools.reduce
S=A
P=lambda a,b:(N(a)^N(b)).to_bytes(1,'big')
B='[redacted - 15 chars]'
poss_letters = 'abcdefghiklmnopqrstuvwxyz'
B = []
def u(li):
 return [li[i::3] for i in range(3)]
def W(i):
 R(i)
 a=[S(T(h(N('e'))[2:][-1]))]
 return[n(a,x(i[E[j][0]],i[E[j][1]]))for j in e(F(E))][-1]
def n(g,k):
 g[0]=g[0]and k
 return g[0]
for a in poss_letters:
    for b in poss_letters:
        for c in poss_letters:
            for d in poss_letters:
                for e in poss_letters:
                    for f in poss_letters:
                        for g in poss_letters:
                            for h in poss_letters:
                                for i in poss_letters:
                                    for j in poss_letters:
                                        for k in poss_letters:
                                            for l in poss_letters:
                                                for m in poss_letters:
                                                    for n in poss_letters:
                                                        for o in poss_letters:
                                                            B=[a, b, c, d, e, f, g, h, i, j, k, l, m, n, o]
                                                            E=((0,3),(1,4),(0,1),(3,4),(2,3),(1,2))
                                                            B=y(Y(B))
                                                            x=lambda a,b:h((N(a)-N(b))^(T('1'*10,2)))[0]!='-'
                                                            f=u(B)
                                                            a=L('input.txt','r').read()
                                                            ans=O(b''.join([D(P,[(((N(a[i])&(~N(f[j][i%5])))|((~N(a[i]))&(N(f[j][i%5])))).to_bytes(1,"big")) for j in e(F(f))]) for i in e(F(a))]))
                                                            if(ans==b':\x1c\x10\x07ZV\x1a\x12\x11B\x1bS\x06\r[\x19\x01B\x11^\x02S\x03\x0fR\x02_B\x01X\x18\x00\x07\x01C\x13\x07\x17\x10\x17\x17\x17\x0b\x12^\x05\x10\x0b\x0cPV\x16\x0e\x0bC'):
                                                                print(ans)
#   if c%100000==0:
#     print(i)
#     print(c)
