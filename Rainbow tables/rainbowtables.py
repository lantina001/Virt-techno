import os
import random
import hashlib
import string
import enchant


def randomwoord(length):
    return ''.join(random.choice(string.lowercase) for i in range(length))

def mainroutine():
    woorden = enchant.Dict("nl_nl")
    fileb = open("gehastewachtwoorden.txt", "a+")

    #maakt een lijst met wachtwoorden aan in een woordenlijst en kijkt of die wachtwoorden kloppen of niet
    while True:
        randomwoord0 = randomwoord(6)
        if woorden.check(randomwoord0) == True:
            randomsleuteL0 = randomwoord0 + str(random.randint(0, 99))
        elif woorden.check(randomwoord0) == False:
            woordenlijst = woorden.suggest(randomwoord0)
            if len(woordenlijst) > 0:
                randomsleuteL0 = woordenlijst[0] + str(random.randint(0, 99))
            else:
                randomsleuteL0 = randomwoord0 + str(random.randint(0, 99))

        #Vergelijkt de random gegenereerde wachtwoorden van het woordenlijst 3
        randomwoord3 = randomwoord(5)
        if woorden.check(randomwoord3) == True:
            randomsleuteL3 = randomwoord3 + str(random.randint(0, 99))
        elif woorden.check(randomwoord3) == False:
            woordenlijst = woorden.suggest(randomwoord3)
            if len(woordenlijst) > 0:
                randomsleuteL3 = woordenlijst[0] + str(random.randint(0, 99))
            else:
                randomsleuteL3 = randomwoord3 + str(random.randint(0, 99))

        # Vergelijkt de random gegenereerde wachtwoorden van het woordenlijst 1
        randomwoord1 = randomwoord(7)
        if woorden.check(randomwoord1) == True:
            randomsleuteL1 = randomwoord1 + str(random.randint(0, 99))
        elif woorden.check(randomwoord1) == False:
            woordenlijst = woorden.suggest(randomwoord1)
            if len(woordenlijst) > 0:
                randomsleuteL1 = woordenlijst[0] + str(random.randint(0, 99))
            else:
                randomsleuteL1 = randomwoord1 + str(random.randint(0, 99))

        #checkt of de gegenereerde wachtwoorden overeenkomen met de kloppende wachtwoorden, en print de wachtwoordhash uit
        if 'randomsleuteL0' and 'randomsleuteL3' and 'randomsleuteL1' in locals():
            whasher0 = hashlib.new("md5")
            whasher0.update(randomsleuteL0)
            whasher3 = hashlib.new("md5")
            whasher3.update(randomsleuteL3)
            whasher1 = hashlib.new("md5")
            whasher1.update(randomsleuteL1)
            print(randomsleuteL0 + " + " + str(whasher0.hexdigest()) + "\n")
            print(randomsleuteL3 + " + " + str(whasher3.hexdigest()) + "\n")
            print(randomsleuteL1 + " + " + str(whasher1.hexdigest()) + "\n")
            fileb.write(randomsleuteL0 + " + " + str(whasher0.hexdigest()) + "\n")
            fileb.write(randomsleuteL3 + " + " + str(whasher3.hexdigest()) + "\n")
            fileb.write(randomsleuteL1 + " + " + str(whasher1.hexdigest()) + "\n")

mainroutine()