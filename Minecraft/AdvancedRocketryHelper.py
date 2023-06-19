def fuelEnough(n_engine, n_tank):
    fuelCapacity = n_tank * 400
    thrust = 8 * n_engine
    fuelConsumeRate = 1 * n_engine
    weight = n_engine + n_tank + 5
    acc = (thrust - weight) / 10000
    fuelNeed = (2 * (1000 - 150) / acc) ** 0.5 * fuelConsumeRate
    print(f"fuel capcity: {fuelCapacity}, fule need: {fuelNeed}")
    return fuelCapacity >= fuelNeed

def computeFuelNeed(n_engine):
    thrust = 8 * n_engine
    minTanks = 2 * n_engine
    maxTanks = thrust - n_engine - 5
    for n_tank in range(minTanks, maxTanks):
        print(f"considering {n_tank} tanks")
        if not fuelEnough(n_engine, n_tank):
            print("fuel not enough")

if __name__ == "__main__":
    #for n_engine in range(1, 5):
    n_engine = 4
    print(f"use {n_engine} engines")
    computeFuelNeed(n_engine)

    
