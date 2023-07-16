import os

class pageReplacement:
    cache = {}      #key values for pairs and grows dynamically
 
    
    def __init__(self) -> None:
        pass

    def fifo(self, maxSize):
        i =0
        hit = 0
        chit = 0
        cmiss = 0
        while len(self.cache) < maxSize:
            page = input("ENTER THE PAGE: ")
            for key, value in self.cache.items():
                if value == page:
                    hit = 1   
                    chit += 1

            if hit == 1:
                #self.clear()
                print(self.cache,"\t CACHE HIT")
                hit = 0
            else:
                key  = i
                i += 1
                self.cache[key] = page
                print(self.cache,"\tCACHE MISS")
                cmiss += 1
        next = 0
        hit = 0
        prompt = 'y'
        while prompt == 'y':
            self.clear()
            print(self.cache)
            page = input("ENTER THE PAGE: ")
            for key, value in self.cache.items():
                if value == page:
                    hit = 1  
                    chit +=1 

            if hit == 1:
                self.clear()
                print(self.cache,"\t CACHE HIT")
                hit = 0
            else:
                for j in range (maxSize-1):
                    self.cache[j] = self.cache[j+1]
                self.cache[maxSize-1] = page
                self.clear()
                cmiss += 1
                print(self.cache,"\tCACHE MISS")
            print("HIT COUNT", chit,"\n MISS COUNT",cmiss)
            prompt = (input("WANT TO CONTINUE?: y/n : ")).lower()

    def LRU(self, maxSize):
        hit = 0
        miss = 0
        next = 0
        count = 0
        flag = 0
        while len(self.cache) != maxSize-1:
            page = input("ENTER PAGE: ")
            for key, value in self.cache.items():
                if value == page:
                    hit += 1
                    count = key
                    flag = 1
                    break
            
            if flag == 1:
                for i in range (count-1,-1,-1):
                    self.cache[i + 1] = self.cache[i]
                self.cache[0] = page
                print(self.cache,"\t CACHE HIT")
                count = 0
                flag = 0
            else:
                self.cache[next] = page
                next+=1
                miss += 1
                print(self.cache,"\t CACHE MISS")
        
        while True:
            #self.clear()
            #print(self.cache)
            page = input("ENTER PAGE: ")

            for key, value in self.cache.items():
                if value == page:
                    hit += 1
                    count = key
                    flag = 1
            
            if flag == 1:
                for i in range (count-1,-1,-1):
                    self.cache[i + 1] = self.cache[i]
                self.cache[0] = page
                print(self.cache,"\t CACHE HIT")
                count = 0
                flag =0
            else:
                for k in range (maxSize-1,0,-1):
                    self.cache[k] = self.cache[k-1]
                self.cache[0] = page
                miss += 1
                print(self.cache,"\t CACHE miss")
            print("HIT COUNT: ",hit,"\nMISS COUNT: ",miss)

    
    def clear(self):
        os.system('cls' if os.name == 'nt' else 'clear')


def main():
    pr = pageReplacement()
    p = int(input("ENTER THE CACHE NUMBER OF CACHE FRAMES: "))
    choice = input("CHOOSE A PAGE REPLACEMENT: \n 1. FIFO (FIRST-IN-FIRST-OUT) \n 2.LRU (LEAST RECENTLY USED) \n :")
    
    if choice == '1':
        pr.fifo(p)
    elif choice == '2':
        pr.LRU(p)
    else:
        print("error")


main()
