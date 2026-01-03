import useful_funcs
import simple_queue
class QueueOutOfRangeException(Exception):
    pass
class named_queue(simple_queue.queue):
    def __init__(self, name,mx_size,iid=-1,lst=None):
        if named_queue.get_by_name(name) is not None and iid==-1:
            raise Exception("Queue with this name already exists.")
        if lst is None:
            lst=[]
        super().__init__()
        self.name = name
        self.max_size=mx_size
        if iid!=-1:
            self.id=iid
            self.items=lst
        else:
            self.id=useful_funcs.get_qid()
            useful_funcs.increase_qid()
            self.save()
    def get_name(self):
        return self.name
    def insert(self, item):
        if len(self.items) >= int(self.max_size):
            raise QueueOutOfRangeException("Warning: cannot insert into a full queue.")
        else:
            super().insert(item)
            self.update()
    def pop(self):
        num=super().pop()
        self.update()
        return num
    def update(self):
        useful_funcs.update_queues_file(self.id,self.name,self.max_size,self.items)
    def save(self):
        useful_funcs.save_file(self.id,self.name,self.max_size,self.items)
    @classmethod
    def get_by_name(self ,name):
        return useful_funcs.get_by_name(name)
    
    @classmethod
    def str_to_queue(cls,name):
        data=named_queue.get_by_name(name)
        if data is None:
            return None
        items_str=data[3]
        if items_str=='':
            data[3]=[]
        else:
            data[3]=items_str.split(";")
        return cls(data[1],data[2],data[0],data[3])
    @classmethod
    def load(cls):
        queues=[]
        file=open("queues.txt","r")
        for line in file:
            data=line.strip().split(",")
            items_str=data[3]
            if items_str=='':
                data[3]=[]
            else:
                data[3]=items_str.split(";")
            q=cls(data[1],data[2],data[0],data[3])
            queues.append(q)
        file.close()
        return queues


q=named_queue("test_queue",5)

qq=named_queue("test2_queue",7)

q.insert(10)
q.insert(20)
q.insert(30)
qq.insert(100)
qq.insert(200)

qqq=named_queue.str_to_queue("test_queue")
print(qqq.items) 

qqq.pop()
qqq.update()

qqq.pop()
qqq.update()

l=named_queue.load()  
print(len(l))
print(l[0].items)
print(l[1].items) 

l[0].insert(40)
l[0].update()

l[0].insert(50)
l[0].update()

