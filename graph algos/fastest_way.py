a=[[7,8], [9,5], [3,6], [4,4], [8,5], [4,7]]
t=[[2,2], [3,1], [1,2], [3,2], [4,1]]
x=[3,2]
e=[2,4]
n=6
f1=[]
f2=[]
l1=[]
l2=[]
for i in range(n):
        f1.append(0)
        f2.append(0)
        l1.append(0)
        l2.append(0)

f1[0] = e[0]+a[0][0]
f2[0] = e[1] + a[0][1]
for j in range(1, n):        
        if (f1[j-1] + a[j][0] <= f2[j-1] + t[j-1][1] + a[j][0]):
                f1[j] = f1[j-1] + a[j][0]
                l1[j] = 1
        else:
                f1[j] = f2[j-1] + t[j-1][1] + a[j][0]
                l1[j] = 2

        if (f2[j-1] + a[j][1] <= f1[j-1] + t[j-1][0] + a[j][1]):
                f2[j] = f2[j-1] + a[j][1]
                l2[j] = 2
        else:
                f2[j] = f1[j-1] + t[j-1][0] + a[j][1]
                l2[j] = 1  

print(f1[n-1] + x[0])
print(f2[n-1] + x[1])
