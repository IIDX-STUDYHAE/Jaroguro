#testing for unittest



#stack by python 


class Stack:
    def __init__(self):
        self.items = []

    def pushback(self,item):
        self.items.append(item)
    def popfront(self):
        if self.is_empty():
            raise IndexError("스택에 원소가 없습니다. 다시 시도해주세요")
        else:
            return self.items.pop()
    def showstack(self):
        #스택의 원소를 pop하지 않고, 전부를 print하는 검증을 위한 코드.
        print(" ".join(map(str, self.items)))


    def is_empty(self):return len(self.items) == 0
    def size(self):return len(self.items)

def main():
    stack = Stack()
    stack.pushback(10)
    stack.pushback(20)
    stack.pushback(40)
    stack.showstack()

    stack.pushback(60)
    k = stack.popfront()

    print(k)#60이 당연히 나와야.

    k = stack.popfront()

    print(k)#40이 당연히 나와야.

    stack.pushback(50)

    stack.showstack()#10 20 50
