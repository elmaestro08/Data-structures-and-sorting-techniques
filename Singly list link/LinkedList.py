class Node:
    def __init__(self,value = None):
        self.value = value
        self.next = None

class LinkedList:
    def __init__(self):
        self.head = None

    def insert_start(self,data):
            new_node = Node(data)
            new_node.next = self.head
            self.head = new_node

    def display(self):
        node = self.head
        if node == None:
            print('Empty list!')
        else:
            while node != None:
                print (node.value)
                node = node.next

    def insert_end(self,data):
        node = Node(data)
        n = self.head
        while(n.next!= None):
            n = n.next
        n.next = node







ll = LinkedList()
ll.insert_start(1)
ll.insert_start(2)
ll.insert_start(3)
ll.insert_end(4)
ll.insert_end(5)
ll.display()




