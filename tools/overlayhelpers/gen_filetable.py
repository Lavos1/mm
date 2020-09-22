import os,sys,json
from collections import OrderedDict

if not os.path.isfile("../../expected/build/mm.map"):
    print(f"An OK mm.map must exist at \"expected/build/mm.map\"")
    exit()

m = OrderedDict()
m["va"] = OrderedDict()
m["ra"] = OrderedDict()
m["ft"] = {}

with open("../../expected/build/mm.map","r",encoding="utf8") as f:
    fd = f.readlines()

vrom = []
vram = []
for i,line in enumerate(fd):
    if "load address" in line:
        rom_addr = int(line.split(" load address ")[1].strip(), 16)
        size = int(line.split(" load address ")[0].split("0x")[2].strip(), 16)
        vram_addr = int(line.split("0x")[1].strip(), 16) - 0x80000000
        if line.startswith(" "):
            name = fd[i-1].strip()
        else:
            name = line.split(" ",1)[0]

        if name.startswith("."):
            continue;

        print(name, "ROM:", hex(rom_addr), "RAM:", hex(vram_addr), "Size:",hex(size))

        m["va"][vram_addr] = name
        m["ra"][rom_addr] = name
        m["ft"][name] = [rom_addr, rom_addr + size]

m["va"] = {k:v for k,v in reversed(m["va"].items())}
m["ra"] = {k:v for k,v in reversed(m["ra"].items())}

with open("filetable.json","w",encoding="utf8") as f:
    f.write(json.dumps(m))
