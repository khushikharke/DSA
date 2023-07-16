s="fpbavjsmppdt"
k=8

ct=Counter(Counter(s).values())
res=1
for i in sorted(ct)[::-1]:
    
    res*=i**min(ct[i],k)   # or pow(i,min(ct[i],k),mod)
    
    if k<=ct[i]:
        res*=math.comb(ct[i],k)   # do inverse mod is needed
        break
    
    k-=ct[i]

   print(res)