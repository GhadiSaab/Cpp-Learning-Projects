
import string

class Car:
    def __init__(self,make,model,year):    #Constructor
        self.make = make
        self.model = model
        self.year = year
    def drive (self):
        print("the "+self.model+" is driving")

#car_1 = Car("roles","royes",2024)
#print(car_1.make)

def mono(n):
    if n < 10:
        return True
    if n % 10 == (n // 10 ) % 10:
        return mono(n // 10)
    else:
        return False
    
T = [22,1,15,555,3124,66666666]

def pgm(T):
    T = sorted(T)
    for i in range(len(T)-1, 0 , -1):
        if mono(T[i]):
            return T[i]
    return -1
 #print(pgm(T))



def isPalindrome(s):
    alph = list(string.ascii_lowercase) + ["0","1","2","3","4","5","6","7","8","9"]
    s = s.lower()
    for i in s:
        if i in alph:
            print(i)
            None
        else:
            print(i)
            s = s.replace(i,"") 
    print(s)
    if s == s[::-1]:
        return True
    else:
        return False


s = "0P" 


def isalphanumeric(c):
        return (ord('A') <= ord(c) <= ord('Z') or ord('a') <= ord(c) <= ord('z') or ord(0) <= ord(c) <= ord(9))

def isPalinndrome2(s):
    l = 0
    r = len(s) - 1
    while l < r:
        while not isalphanumeric(s[l]) and l < r:
            l += 1
        while not isalphanumeric(s[r]) and l < r:
            r += 1
        if s[l] != s[r]:
            return False
        l += 1
        r -= 1
    return True



def nbinf(e,L):
    if not L:
        return 0
    if L[0] < e:
        return 1 + nbinf(e , L[1:])
    else:
        return nbinf(e,L[1:])
    

##print(nbinf(5,[1,2,3,4,5,6,7]))

def affEspace(e):
    for i in range(e):
        print(" ", end="")

def affEtoile():
    print("*", end="")

def affRL():
    print()

def etoile(n):
    if n == 0:
        return " "
    else:
        affEspace(n-1)
        affEtoile()
        affRL()
        return etoile(n-1)


#print(etoile(5))

def somme(n):
    if n == 0:
        return 0
    else:
        return n + somme(n-2)
    
#print(somme(10))

def maxListes(L,p):
    if not L:
        return p
    else:
        if p < L[0]:
            p = L[0]
        return maxListes(L[1:], p)
    
print(maxListes([2,3,5,1,7],0))

def listesEgales(L1,L2):
    if len(L1) != len(L2):
        return False
    if not L1:
        return True
    else:
        if L1[0] != L2[0]:
            return False
        listesEgales(L1[1:],L2[1:])


print(listesEgales([3,4,5],[3,4,5]))
def stack():
    stack = []
    stack.append(1)
    stack.append(2)
    print(stack)
    print(stack.pop())

print(stack())



