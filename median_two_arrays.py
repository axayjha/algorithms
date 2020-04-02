A=[1, 3, 4, 8]
B=[2,5,6,7, 9]
m=len(A)
n=len(B)
# i=len(a)/2

def search(imin, imax):
        i = (imin+imax)//2
        j = (m+n+1)//2 - i 
        if (B[j-1] > A[i]):
                return search(i+1, imax)
        elif (A[i-1] > B[j]):
                return search(imin, i-1)
        else:
                if (m+n)%2 != 0:
                        print(max(A[i-1], B[j-1]))
                        return max(A[i-1], B[j-1])
                else:
                        print((max(A[i-1], B[j-1]) + min(A[i], B[j]))/2)
                        return (max(A[i-1], B[j-1]) + min(A[i], B[j]))/2          

a=search(0, m)                       
print(a)