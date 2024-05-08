while True:
    height = input("height: ")

    if height.isdigit():
        if int(height) >= 1 and int(height) <= 8:
            break
        else:
            continue

for i in range(int(height)):
    print((int(height) - (i + 1)) * " " + (i + 1) * "#" + "  " + (i + 1) * "#")
