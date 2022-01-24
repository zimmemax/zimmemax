x = 321

if x > (2^31-1) or x < -2^31:
    print(0)
        
reverseNum = 0
digit = 0
index = 0
arr = {}
        
while(x != 0):
    digit = x % 10
    x = x // 10
    arr[index] = digit
    print(arr[index])
    index += 1
          

multiple = len(arr) - 1
multiple = multiple * 10
j = 0

for n in enumerate(arr):
    reverseNum = (n * multiple) + reverseNum
    multiple = multiple / 10
            
            
print(reverseNum)
            