import random

def computer_turn(stones):
    if stones%4==0:
        print("\nThe computer admits defeat.")
        exit(0)
    else:
        n=stones%4
        stones -= n
        print(f"\nThe computer takes {n} stones")
    return stones
stones = random.randint(5, 21)
print(f"\nHeap: {stones} stones")
while stones > 0:        
    stones = computer_turn(stones)
    print(f"\nHeap: {stones} stones")
    if stones==0:
        break
    else:
        while True:
            num_stones = int(input("\nHow many stones player takes? "))
            if(num_stones > 0 and num_stones<4):
                stones -= num_stones
                print(f"\nHeap: {stones} stones")
                break
            else:
                print("\nPlease enter a valid number of stones")
print("\nGame over! The computer has won!")
