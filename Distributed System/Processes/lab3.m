%z-transform
num=[1,0.8,2,7,3,1.6]   #numerator value of equation
den=[0.7,0,2,3,2.3]    #demnominator value of equation
[z,p,k]=tf2zp(num,den)
zplane(z,p)
