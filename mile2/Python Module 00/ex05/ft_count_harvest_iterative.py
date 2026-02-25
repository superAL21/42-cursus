def ft_count_harvest_iterative():
    until = int(input("Days until harvest: "))
    for i in range(1, until + 1):
        print(f"Day {i}")
        print("Harvest time!")
