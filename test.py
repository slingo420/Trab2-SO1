import matplotlib.pyplot as plt

import subprocess
from time import time, sleep


num_frames = []
exec_time = []
fifo = []
lru = []
opt = []
for val in [1,2,4,8,16,32,64,128,256,512]:
# for val in [4, 8]:
    avg = 0
    for i in range(10):
        print(f"Testando com {val} frames ({i+1}/10)")
        begin = time()
        proc = subprocess.run(f"./main {val} < vsim-gcc.txt", shell=True, stdout=subprocess.DEVNULL, stderr=subprocess.DEVNULL)
        end = time()

        avg += ( (end - begin)/10 )

        # lines = proc.stdout.decode().splitlines()

        # if not i:
        #     fifo.append(int(lines[2].split()[1]) )
        #     lru.append(int(lines[3].split()[1]) )
        #     opt.append(int(lines[4].split()[1]) )
        #     break

        
    
    num_frames.append(val)
    exec_time.append(avg)

plt.xlabel("Num. Frames")
plt.ylabel("Tempo em segundos")
plt.plot(num_frames, exec_time)
plt.title("Tempo de execução do programa com vsim-gcc.txt")
plt.show()

# plt.xlabel("Num. Frames")
# plt.ylabel("Faltas de Página")
# plt.title("Faltas de página no vsim-gcc.txt")

# plt.plot(num_frames, fifo, label="FIFO")
# plt.plot(num_frames, lru, label="LRU")
# plt.plot(num_frames, opt, label="Ótimo")
# plt.legend()
# plt.show()