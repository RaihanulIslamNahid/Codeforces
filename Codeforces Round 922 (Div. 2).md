# Codeforces Round 922 (Div. 2) 

I'm sad that the E I worked so hard to write turned out to be TLE.

Problem A - Use 1 * 2 horizontal tiles to cover as many rows as possible. If one cell remains in the end, extend the last tile to make it 1 * 3. Hence vertical tiles are never required.

Problem B - Normally we would use [position of the element in sorted array]. Use here [position in sorted A + position in sorted B] to get the final sorted combination array. [Try proving it by looking at the number of inversions added by any index].

Problem C - Only the bits which are set in one and not in other matters. Without loss of generality, let's a < b. Try setting as many bits (less than the highest one) in 'a' as possible to make the difference less. The only other option is to flip the highest bit, now a > b. Try setting in 'b' now in a similar way.

Problem D - Binary search for the answer. Suppose we want to check if X is a possible answer. We can use dynamic programming to find what's the minimum sum of blocked elements we can get when we have to split subarrays with <= X. If this dp tells us that we can get blocked elements with a sum less than X, then this is possible. Look at my code for implementation details.

Problem E - This was a beauty. Hint for one possible solution - Randomized Quick Sort.

Code:

A - Brick Wall
```
# PyPy3-64

import sys
input = sys.stdin.readline

t=int(input())
for tests in range(t):
    n,m=map(int,input().split())

    if m==1:
        print(-1)
        continue

    x=m//2

    print(x*n)

```

B - Minimize Inversions
```
# PyPy3-64
import sys
input = sys.stdin.readline

from operator import itemgetter

t=int(input())
for tests in range(t):
    n=int(input())
    A=list(map(int,input().split()))
    B=list(map(int,input().split()))

    C=[]
    for i in range(n):
        C.append((A[i],B[i]))

    C.sort(key=itemgetter(0))
    X=[]
    Y=[]
    for i in range(n):
        X.append(C[i][0])
        Y.append(C[i][1])

    print(*X)
    print(*Y)
    
```

C - XOR-distance
```
# PyPy3-64
import sys
input = sys.stdin.readline

    
t=int(input())
for tests in range(t):
    a,b,r=map(int,input().split())

    flag=0
    s=0

    if a<b:
        a,b=b,a

    for i in range(63,-1,-1):
        if flag==0:
            if (a & (1<<i)) != (b& (1<<i)):
                flag=1
        else:
            if (a & (1<<i)) !=0 and  (b& (1<<i))==0:
                if s+(1<<i)<=r:
                    s+=(1<<i)

    a,b=b,a
    flag=0
    ANS2=0
    s2=0

    for i in range(63,-1,-1):
        if flag==0:
            if (a & (1<<i)) != (b& (1<<i)):
                if s2+(1<<i)<=r:
                    flag=1
                    s2+=(1<<i)

        else:
            if (a & (1<<i)) !=0 and  (b& (1<<i))==0:
                if s2+(1<<i)<=r:
                    s2+=(1<<i)


    #print(ANS,ANS2)
    print(min(abs((a^s)-(b^s)),abs((a^s2)-(b^s2))))
```

D - Blocking Elements
```
# PyPy3-64
import sys
input = sys.stdin.readline

def update(n,x,seg_el): # update A[n] to x
    i=n+seg_el
    SEG[i]=x
    i>>=1 # to child node
    
    while i!=0:
        SEG[i]=min(SEG[i*2],SEG[i*2+1])
        i>>=1
        
def getvalues(l,r): # Check min for interval [l,r)
    L=l+seg_el
    R=r+seg_el
    ANS=1<<60

    while L<R:
        if L & 1:
            ANS=min(ANS , SEG[L])
            L+=1

        if R & 1:
            R-=1
            ANS=min(ANS , SEG[R])
        L>>=1
        R>>=1

    return ANS

    
t=int(input())
for tests in range(t):
    n=int(input())
    A=list(map(int,input().split()))

    if n==1:
        print(A[0])
        continue

    S=[0]
    for a in A:
        S.append(S[-1]+a)

    OK=10**14
    NG=min(A)-1

    seg_el=1<<((n+1).bit_length()) # Number of elements in the segment tree

    while OK>NG+1:
        mid=(OK+NG)//2

        SEG=[1<<60]*(2*seg_el) # Since it is 1-indexed, initialize it with the initial value of the number of elements 2*seg_el.Segment tree

        flag=0
        ind=0

        for i in range(n):
            if i==0:
                update(i,A[i],seg_el)
                continue

            while S[ind]<S[i]-mid:
                ind+=1

            if ind==0:
                k=0
            else:
                k=getvalues(max(0,ind-1),i)

            update(i,A[i]+k,seg_el)

            if A[i]+k<=mid and S[-1]-(S[i+1])<=mid:
                flag=1
                break

        #print(mid,[getvalues(i,i+1) for i in range(n)])

        if flag==1:
            OK=mid
        else:
            NG=mid

    print(OK)
```
E - ace5 and Task Order

```
# Python 3
import sys
input = sys.stdin.readline

def query(i):
    print("? "+str(i)+"\n",flush=True)
    return input().strip()

def big(L,ind):
    while True:
        x=query(ind)

        if x=="=":
            break

    LEN=len(L)

    plus=0

    for b in L:
        while plus!=LEN//2:
            x=query(b)

            if x==">":
                plus+=1
                continue

            if x=="=":
                break
            if x=="<":
                plus-=1
                break

        if plus==LEN//2:
            last=b
            break

    for b in L:
        x=query(b)
        if x=="=":
            center=b
            break

        if x==">":
            query(ind)
        else:
            query(last)

    BIG=[]
    SMALL=[]

    for b in L:
        if center==b:
            continue
        x=query(b)

        if x==">":
            BIG.append(b)
            query(center)
        else:
            SMALL.append(b)
            query(center)

    return BIG,SMALL,center

def small(L,ind):
    while True:
        x=query(ind)

        if x=="=":
            break

    LEN=len(L)

    plus=0

    for b in L:
        while plus!=LEN//2:
            x=query(b)

            if x=="<":
                plus+=1
                continue

            if x=="=":
                break
            
            if x==">":
                plus-=1
                break

        if plus==LEN//2:
            last=b
            break

    for b in L:
        x=query(b)
        if x=="=":
            center=b
            break

        if x=="<":
            query(ind)
        else:
            query(last)

    BIG=[]
    SMALL=[]

    for b in L:
        if center==b:
            continue
        x=query(b)

        if x==">":
            BIG.append(b)
            query(center)
        else:
            SMALL.append(b)
            query(center)

    return BIG,SMALL,center

    
t=int(input())
for tests in range(t):
    n=int(input())

    while True:
        x=query(1)

        if x=="=":
            break

    BIG=[]
    SMALL=[]

    for i in range(2,n+1):
        x=query(i)

        if x==">":
            BIG.append(i)
            query(1)
        else:
            SMALL.append(i)
            query(1)

    X=[[SMALL,-1],[[1],1],[BIG,1]]

    ANS=[]

    while X:
        L,ind=X.pop()

        if len(L)==0:
            continue

        if len(L)==1:
            ANS.append(L[0])
            continue

        if ind<0:
            BIG,SMALL,center=small(L,-ind)
        else:
            BIG,SMALL,center=big(L,ind)

        X.append([SMALL,center*(-1)])
        X.append([[center],center])
        X.append([BIG,center])

    ANS.reverse()
    LANS=[-1]*n

    for i in range(n):
        LANS[ANS[i]-1]=i+1

    print("!",*LANS,flush=True)
```
