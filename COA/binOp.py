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

        def addition(self,v1,v2,temp = 0):
            if(temp == 8):
                n = 8
            else:
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

        
        def subtraction(self,x,y,temp = 0):
            if(temp == 8):
                n = 8
            else:
                n = max(len(x),len(y))    #get the maximum number of digits and zero-padding the strings
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
            
        def boothMult(self,b,q):
            n = max(len(b),len(q))      #get the maximum number of digits and zero-padding the strings

            if(n < 4):
                n = 4
            b = b.zfill(n)
            q = q.zfill(n)

            a = ""
            a = a.zfill(n)
            q1 = "0"
            for i in range (n):
                if(q[n-1] == "1" and q1 == "0" ):
                    a = self.subtraction(a,b)        #A = A - B
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
        
        def rDiv(self,q,y):
            n = max(len(q),len(y))
            q = q.zfill(n)
            y = y.zfill(n)

            print(q)
            print(y)
            a = ""
            a = a.zfill(n+1)

            for i in range(n):
                a = a[1:]+q[0]   #shift
                a = self.subtraction(a,y)            
                q = q[1:]+str(self.XOR(int(a[0]),1))
                if(a[0]=='1'):
                    a = self.addition(a,y)    #restore
                    if(len(a) != (n+1)):
                        a = a[1:]
            
            print(" QUOTIENT = ",q,"REMAINDER = ",a)
        
        
        
        def nrDiv(self,q,y):
            n = max(len(q),len(y))
            q = q.zfill(n)
            y = y.zfill(n)

            print(q)
            print(y)
            a = ""
            a = a.zfill(n+1)

            for i in range(n):
                
                a = a[1:]+q[0]   #shift

                if(a[0] =='0'):  
                    a = self.subtraction(a,y)
                else:
                    a = self.addition(a,y)
                    if(len(a) != (n+1)):
                        a = a[1:]

                q = q[1:]+str(self.XOR(int(a[0]),1))
            
            if(a[0] == '1'):
                a  = self.addition(a,y)
                if(len(a) != (n+1)):
                    a = a[1:]
            
            print(" QUOTIENT = ",q,"REMAINDER = ",a)

        def partial(self,q,y):
            n = max(len(q),len(y))
            if(n<4):
                n = 4

            q = q.zfill(n)
            y = y.zfill(n)
            res = ""

            for i in range(n-1,-1,-1):
                if(y[i] == '1'):
                    res = self.addition(res,q)
                    q += '0'
                else:
                    res = self.addition(res,"0")
                    q += '0'
            
            return res


def main():
    bo = binaryOperations()

    prompt = "Y"

    while(prompt == "Y"):
        choice = input("CHOOSE AN OPERATION: \n 1 for ADDITION \n 2 for SUBTRACTION \n 3 for MULTIPLICATION \n 4 for DIVISION \n OTHER KEY TO LEAVE : ")
        if(choice == '1'):
            first = input("FIRST: ")
            second = input("Second: ")
            print("sum =",bo.addition(first,second,8))
            pass
        elif(choice == '2'):
            first = input("MINUEND: ")
            second = input("SUBTRAHEND: ")
            print("subtraction =",bo.subtraction(first,second,8))
            pass
        elif(choice == '3'):
            first = input("MULTIPLICAND: ")
            second = input("MULTIPLIER: ")
            print("\nBOOTH'S ALGORITHM =",bo.boothMult(first,second))
            print("PARTIAL PRODUCT METHOD =",bo.partial(first,second))
            pass
        elif(choice == '4'):
            first = input("DIVIDEND: ")
            second = input("DIVISOR: ")
            print("\nALGORITHM FOR RESORTING DIVISION: ")
            bo.rDiv(first,second)
            print("\nALGORITHM FOR NON-RESORTING DIVISION: ")
            bo.nrDiv(first,second)
            pass
        else:
            break

        prompt = input("DO YOU WANT TO CONTINUE? [Y/N] : ")
        prompt = prompt.upper()

main()
