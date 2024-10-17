from mpi4py import MPI
comm = MPI.COMM_WORLD
rank = comm.Get_rank()
MAX = 1000
i = 0
while i < MAX:
    if rank == 0:
        print(f"ping, {i}")
        i+=1
        comm.send(i, dest = 1, tag=0)
        i = comm.recv(source = 1, tag=0)
    else:
        i = comm.recv(source = 0, tag=0)
        print(f"pong, {i}")
        i+=1
        comm.send(i, dest = 0, tag=0)
