#A program in python for replicating the binary operations that takes place in registers assuming strings as binary input
class binaryOperations:
        
        def __init__(self) -> None:
            pass

        def AND(x,y):
            if(x==0 or y==0):
                return 0
            else:
                return 1

        def XOR(self,x,y):
            if((x==0 and y==0)or (x==1 and y==1)):
                return 0
            else:
                return 1
        
        # def zeroPadding(self,x,y):
        #     n = max(len(x),len(y))

        #     if(n==len(y)):
        #         x = x.zfill(n)
        #         return x
        #     else:
        #         y = y.zfill(n)
        #         return y

        def addition(self,v1,v2):
            n = max(len(v1),len(v2))    #get the maximum number of digits and zero-padding the strings
            v1 = v1.zfill(n)
            v2 = v2.zfill(n)
            carry = 0
            sum = ""
            for i in range (n-1,-1,-1):  #starting the addition from the end of the string
                a = int(v1[i])           
                b = int(v2[i])
                sumbits = (a + b + carry)%2   # getting the remainder from the addition of bits and the quotent i.e carry bits 
                carry = (a + b + carry)//2    
                sum = str(sumbits)+ sum       #appending at the front of the sum because the bits are being added from the LSB
            if(carry == 1):
                sum = str(carry) + sum

            return sum
        
        def subtraction(self,x,y):
            n = max(len(x),len(y)) 
            x = x.zfill(n)
            y = y.zfill(n)

            cmp = ""                    #storing the 1's complement of subrahend in cmp
            for i in range (n):
                cmp += str(self.XOR(int(y[i]),1))
            
            y = self.addition(cmp,"1")  #replacing the subrahend with 2's complement of itself

            res = self.addition(x,y)    #subtracting subrahend from minuend and ignoring the carry
            if(len(res) != n):
                res = res[1:]
                return res
            else:
                return res
    
        def multiplication(self,b,q):
            print("\n USING BOOTH'S ALGORITHM")
            n = max(len(b),len(q))      #get the maximum number of digits and zero-padding the strings
            b = b.zfill(n)
            q = q.zfill(n)

            cmpb = ""
            for i in range (n):
                cmpb += str(self.XOR(int(b[i]),1))
            cmpb = self.addition(cmpb,"1")

            a = ""
            a = a.zfill(n)
            
            q1 = "0"
            for i in range (n):
                if(q[n-1] == "1" and q1 == "0" ):
                    a = self.addition(a,cmpb)        #A = A - B
                    if(len(a) != n):
                        a = a[1:]
                        
                    q1 = q[n-1]                      #ASR
                    q = a[n-1]+q[:-1]
                    a = a[0]+a[:-1]
                    pass

                elif(q[n-1] == "0" and q1 == "1"):
                    a = self.addition(a,b)
                    if(len(a) != n):
                        a = a[1:]
                 #asr
                    q1 = q[n-1]
                    q = a[n-1]+ q[:-1]
                    a = a[0]+ a[:-1]
                 
                    pass

                else:
                #asr
                    q1 = q[n-1]
                    q = a[n-1]+ q[:-1]
                    a = a[0]+ a[:-1]
                
                    pass
            
            return a+q


#sum = (a xor b )xor c
#carry = (a and b) + (a xor b)

def main():
    bo = binaryOperations()

    prompt = "Y"

    while(prompt == "Y"):
        choice = input("CHOOSE AN OPERATION: \n 1 for ADDITION \n 2 for SUBTRACTION \n 3 for MULTIPLICATION \n OTHER KEY TO LEAVE : ")
        if(choice == '1'):
            first = input("FIRST: ")
            second = input("Second: ")
            print("sum =",bo.addition(first,second))
            pass
        elif(choice == '2'):
            first = input("MINUEND: ")
            second = input("SUBTRAHEND: ")
            print("subtraction =",bo.subtraction(first,second))
            pass
        elif(choice == '3'):
            first = input("MULTIPLICAND: ")
            second = input("MULTIPLIER: ")
            print("multiplication =",bo.multiplication(first,second))
            pass
        else:
            break

        prompt = input("DO YOU WANT TO CONTINUE? [Y/N] : ")
        prompt = prompt.upper()

main()
