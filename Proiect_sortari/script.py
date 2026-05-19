#!/usr/bin/python3
import os
import time

#seed 1: numere random intre 1 si 1000
#seed 2: vectorul e sortat descrescator
#seed 3: vectorul e sortat descrescator in bucket-uri de 400
#seed 4: numere random intre 1 si 10
#seed 5: numere random
#seed 6: numere random intre 5 * 10^8 si 10^9
#seed 7: crescator pana la mijloc si descrescator in continuare
#seed 8: permutare circulara
#seed 9: 2 subsiruri crescatoare

params = [
    #N, iar apoi seed
    [20000, 1], 
    [20000, 2], 
    [20000, 3], 
    [20000, 4],
    [20000, 5],
    [20000, 6],
    [20000, 7],
    [20000, 8],
    [20000, 9],

    # [10**7, 1],
    # [10**7, 2],
    # [10**7, 3],
    # [10**7, 4],
    # [10**7, 5],
    # [10**7, 6],
]   



ok_solution = "main"

os.system("g++ -D LOCAL -std=c++20 -O2 gen.cpp -o gen")
os.system(f"g++ -D LOCAL -std=c++20 -O2 {ok_solution}.cpp -o {ok_solution}")


def check_solution(name, curr_tag):
    print(f"RULEZ {name}")
    ret_code = os.system(f"time ./{name} < tests/{curr_tag}.in > /dev/null")   
    # check = os.system(f"diff -qBbEa test.out tests/{curr_tag}.out > /dev/null")
    if(ret_code != 0):
        print(f"{name} WRONG!")         
        return 1
    else: 
        print(f"{name} PASSED!")
        return 0
i = 0
tag = "{}_{}"
delta = 0
while i < len(params):
    if params[i][0] == 20000:
        curr_tag = tag.format("small_team1", i + delta)
    else:
        curr_tag = tag.format("big_team1", i + delta);
    os.system(f"./gen {' '.join([str(x) for x in params[i]])} > tests/{curr_tag}.in")
    os.system(f"./{ok_solution} < tests/{curr_tag}.in > tests/{curr_tag}.out")

    print(f"TEST: {curr_tag}")

    cnt = 0
    if check_solution(ok_solution, curr_tag) == 1: 
        print(f"Failed")
    print()
    i += 1

