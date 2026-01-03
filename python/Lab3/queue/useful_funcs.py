def get_qid():
    file=open("qid.txt","r")
    qid=file.read().strip()
    file.close()
    return qid

def increase_qid():
    file=open("qid.txt","r")
    qid=int(file.read().strip())
    file.close()
    qid+=1
    file=open("qid.txt","w")
    file.write(str(qid))
    file.close()

def get_by_name(name):
    file=open("queues.txt","r")
    for line in file:
        q=line.strip().split(",")
        if q[1]==name:
            file.close()
            return q
    file.close()
    return None

def save_file(qid,name,max_size,items):
    file=open("queues.txt","a")
    items_str=";".join(items)
    file.write(f"{qid},{name},{max_size},{items_str}\n")
    file.close()

def update_queues_file(qid,name,max_size,items):
    file=open("queues.txt","r")
    lines=file.readlines()
    file.close()
    file=open("queues.txt","w")
    for line in lines:
        q=line.strip().split(",")
        if q[0]==qid:
            items_str=";".join(items)
            file.write(f"{qid},{name},{max_size},{items_str}\n")
        else:
            file.write(line)
    file.close()
