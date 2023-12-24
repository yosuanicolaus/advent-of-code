import os

__location__ = os.path.realpath(os.path.join(
    os.getcwd(), os.path.dirname(__file__)))
with open(os.path.join(__location__, 'input.txt')) as f:
    content = f.read()
    lines = content.split('\n')[:-1]  # discard last new line

test = """1abc2
pqr3stu8vwx
a1b2c3d4e5f
treb7uchet""".split('\n')

digits = []

for line in lines:
    first_digit = False
    last_digit = False

    # get first digit
    pointer = 0
    while not first_digit:
        if line[pointer].isnumeric():
            first_digit = line[pointer]
        pointer += 1

    # get last digit
    pointer = len(line) - 1
    while not last_digit:
        if line[pointer].isnumeric():
            last_digit = line[pointer]
        pointer -= 1

    digits.append(int(first_digit + last_digit))

print(sum(digits))

