# Welcome to Tripwire Lite!
# The Purpose of thise code id to run hash checking on various configuration files for the Apache2 framework. So Far, the files include: [/etc/apache2/sites-available/000-default.conf, /etc/apache2/sites-enabled/000-default.conf, /etc/apache2/apache2.conf/, /etc/apache2/sites-available/default-ssl.conf]  

# At its present state, twLite will only check hashes and recompute for future checking. All temp hashes and hashes are stored in '/etc/apache2/twLite/'


# Open files for re-computation (if needed)

# If file dne, go ahead and compute all the hashes and put them in /hashes

from pathlib import Path

NUM_FILES_TO_SCAN = 4 #Number of configuration files to scan

if Path('/etc/apache2/twLite/hashes').is_file() == False: #Fist time using twLite!
    
    with open('/etc/apache2/sites-available/000-default.conf') as tmp1:
        available_000 = tmp1.read()
        tmp1.close()
    with open('/etc/apache2/sites-enabled/000-default.conf') as tmp2:
        enabled_000 = tmp2.read()
        tmp2.close()
    with open('/etc/apache2/apache2.conf') as tmp3:
        apache2Conf = tmp3.read()
        tmp3.close()
    with open('/etc/apache2/sites-available/default-ssl.conf') as tmp4:
        defaultSSLConf = tmp4.read()
        tmp4.close()

    a = hash(available_000)
    b = hash(enabled_000)
    c = hash(apache2Conf)
    d = hash(defaultSSLConf)

    permHashes = open('/etc/apache2/twLite/hashes', "w+")

    permHashes.write(str(a) + "\n")
    permHashes.write(str(b) + "\n")
    permHashes.write(str(c) + "\n")
    permHashes.write(str(d) + "\n")
    permHashes.close()


choice = 5

while choice != 1 and choice != 2 and choice != 3:

    print("What would you like to do?")
    print("1) Check hashes")
    print("2) Re-run Hashes")
    print("3) Quit")
    

    choice = input()
    print ("You chose: " + str(choice))


if choice == 1:
        
    tempHashes= open('/etc/apache2/twLite/tempHashes', "w+r")
        
        # Hash CURRENT versions of files
    with open('/etc/apache2/sites-available/000-default.conf') as tmp1:
        available_000 = tmp1.read()
        tmp1.close()
    with open('/etc/apache2/sites-enabled/000-default.conf') as tmp2:
        enabled_000 = tmp2.read()
        tmp2.close()
    with open('/etc/apache2/apache2.conf') as tmp3:
        apache2Conf = tmp3.read()
        tmp3.close()
    with open('/etc/apache2/sites-available/default-ssl.conf') as tmp4:
        defaultSSLConf = tmp4.read()
        tmp4.close()

    a = hash(available_000)
    b = hash(enabled_000)
    c = hash(apache2Conf)
    d = hash(defaultSSLConf)

    # Write CURRENT versions of files to /tempHashes

    tempHashes.write(str(a) + "\n") # Cannot write hashes easily to a file....
    tempHashes.write(str(b) + "\n")
    tempHashes.write(str(c) + "\n")
    tempHashes.write(str(d) + "\n")
    tempHashes.close()
    
    # Take both hashes and tempHashes, read them in, and compare
        
    tempHashArray = []
    with open('/etc/apache2/twLite/tempHashes', "r+") as tempHashFile:
        for line in tempHashFile:
             tempHashArray.append(line)
        tempHashFile.close()

    permHashArray = []
    with open('/etc/apache2/twLite/hashes', "r+") as permHashFile:
        for line in permHashFile:
             permHashArray.append(line)
    permHashFile.close()
        
    # now we need to compare and see what file has been tampered with :)

    beenTampered = False;
    for x in range(len(permHashArray)):
        a = permHashArray[x]
        b = tempHashArray[x]

        if(a != b and x == 0):
            print("File /etc/apache2/sites-available/000-default.conf/ has been tampered with!")
            beenTampered = True
        elif(a!= b and x == 1):
            print("File /etc/apache2/sites-enabled/000-default.conf has been tampered with!")
            beenTampered = True
        elif(a!=b and x == 2):
            print("File /etc/apache2/apache2.conf has been tampered with!")
            beenTampered = True
        elif(a != b and x ==3):
            print("File /etc/apache2/sites-available/default-ssl.config has been tampered with")
            beenTampered = True

    if (beenTampered == False):
        print("No Apache files have been tampered with.")


elif choice == 2:
    
    with open('/etc/apache2/sites-available/000-default.conf') as tmp1:
        available_000 = tmp1.read()
        tmp1.close()
    with open('/etc/apache2/sites-enabled/000-default.conf') as tmp2:
        enabled_000 = tmp2.read()
        tmp2.close()
    with open('/etc/apache2/apache2.conf') as tmp3:
        apache2Conf = tmp3.read()
        tmp3.close()
    with open('/etc/apache2/sites-available/default-ssl.conf') as tmp4:
        defaultSSLConf = tmp4.read()
        tmp4.close()

    a = hash(available_000)
    b = hash(enabled_000)
    c = hash(apache2Conf)
    d = hash(defaultSSLConf)

    permHashes = open('/etc/apache2/twLite/hashes', "w+")

    permHashes.write(str(a) + "\n")
    permHashes.write(str(b) + "\n")
    permHashes.write(str(c) + "\n")
    permHashes.write(str(d) + "\n")
    permHashes.close()
    print("Hashes have been re-computed!")


elif(choice == 3):
    print("namaste!")


