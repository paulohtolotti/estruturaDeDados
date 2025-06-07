""""
Aplicação de uma pilha em Python usando classes
"""
class Node:
    '''Classe que representa um nó, membro da pilha'''
    def __init__(self, val):
        self.next = None
        self.key = val
    

class Stack:
    '''Classe que representa uma pilha'''
    def __init__(self):
        self.head = None
        self.size = 0
    
    def insert(self, val):
        '''Método para inserir um elemento na pilha'''
        new_node = Node(val)

        if self.head is None:
            self.head = new_node
            self.size += 1
            return
        
        new_node.next = self.head
        self.head = new_node
        self.size += 1
    
    def show (self):
        '''Exibe a pilha'''
        while (self.head is not None):
            print(f"{self.head.key}")
            print("↓")
            self.head = self.head.next
        print("NULL")



pilha = Stack()
pilha.insert(15)
pilha.insert(20)
pilha.insert(30)
pilha.show()




