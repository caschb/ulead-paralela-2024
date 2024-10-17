from mpi4py import MPI
comm = MPI.COMM_WORLD
comm_size = comm.Get_size()
rank = comm.Get_rank()
MAX = 1000
ring_variable = 0
while ring_variable < MAX:
    if rank == 0:
        ring_variable += 1
        comm.send(ring_variable, dest = rank + 1, tag=0)
        ring_variable = comm.recv(source = comm_size - 1, tag=0)
    elif rank == comm_size -1:
        ring_variable = comm.recv(source = rank - 1, tag=0)
        ring_variable += 1
        comm.send(ring_variable, dest = 0, tag=0)
    elif rank % 2 == 0:
        ring_variable += 1
        comm.send(ring_variable, dest = rank + 1, tag=0)
        ring_variable = comm.recv(source = rank - 1, tag=0)
    else:
        ring_variable = comm.recv(source = rank - 1, tag=0)
        ring_variable += 1
        comm.send(ring_variable, dest = rank + 1, tag=0)
if rank == 0:
    print(ring_variable)
