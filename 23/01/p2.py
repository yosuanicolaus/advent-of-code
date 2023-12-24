import os

__location__ = os.path.realpath(os.path.join(
    os.getcwd(), os.path.dirname(__file__)))
with open(os.path.join(__location__, 'input.txt')) as f:
    content = f.read()
    lines = content.split('\n')[:-1]  # discard last new line

test = """two1nine
eightwothree
abcone2threexyz
xtwone3four
4nineeightseven2
zoneight234
7pqrstsixteen""".split('\n')

num_map = {"one": '1', "two": '2', "three": '3', "four": '4',
           "five": '5', "six": '6', "seven": '7', "eight": '8', "nine": '9'}

digits = []

for line in lines:
    first_digit = None
    last_digit = None

    # get first digit
    pointer = 0
    while not first_digit:
        if line[pointer].isnumeric():
            first_digit = line[pointer]
        for num_name, num in num_map.items():
            end_pointer = pointer + len(num_name)
            if end_pointer <= len(line) and line[pointer:end_pointer] == num_name:
                first_digit = num
        pointer += 1

    # get last digit
    pointer = len(line) - 1
    while not last_digit:
        if line[pointer].isnumeric():
            last_digit = line[pointer]
        for num_name, num in num_map.items():
            end_pointer = pointer - len(num_name)
            if end_pointer >= -1 and line[end_pointer+1:pointer+1] == num_name:
                last_digit = num
        pointer -= 1

    digits.append(int(first_digit + last_digit))

print(sum(digits))
