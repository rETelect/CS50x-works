from cs50 import get_string

def main():
    number = get_string("Number: ")

    if valid_checksum(number):
        print_card_brand(number)
    else:
        print("INVALID")

def valid_checksum(number):
    total = 0
    reverse_digits = number[::-1]

    for i, digit in enumerate(reverse_digits):
        n = int(digit)

        if i % 2 == 1:
            doubled = n * 2
            total += doubled // 10 + doubled % 10
        else:
            total += n

    return total % 10 == 0

def print_card_brand(number):
    length = len(number)
    start_two = int(number[:2])
    start_one = int(number[:1])

    if length == 15 and (start_two == 34 or start_two == 37):
        print("AMEX")
    elif length == 16 and (51 <= start_two <= 55):
        print("MASTERCARD")
    elif (length == 13 or length == 16) and start_one == 4:
        print("VISA")
    else:
        print("INVALID")

if __name__ == "__main__":
    main()
