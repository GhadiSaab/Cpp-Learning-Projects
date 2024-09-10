def sommeN(num):
    if num == 0:
        return 0
    else:
        return num + sommeN(num-1)
    
##print(sommeN(5))
    
def reverse(mot):
    if len(mot) == 0:
        return mot
    else: 
        return mot[-1] + reverse(mot[:-1])
    
#print(reverse("ghadi"))
    
def fusion(l1,l2):
    if not l1:
        return l2
    if not l2:
        return l1
    if l1[0] < l2[0]:
        return [l1[0]] + fusion (l1[1:], l2 )
    return [l2[0]] + fusion (l2[1:],l1)
    

def tri_fusion(l):
    n = len(l)
    if n <= 1:
        return l
    moy = n//2
    l1 = l[moy:]
    l2 = l[:moy]
    return fusion( tri_fusion(l1) , tri_fusion(l2))
