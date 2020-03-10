import sys


BUFF_SIZE = 65535


def main() -> None:
    if len(sys.argv) < 2:
        print('Usage: python3 bytesum.py $file_name')
        return

    s: int = 0

    with open(sys.argv[1], 'rb') as f:
        while True:
            data = f.read(BUFF_SIZE)
            if len(data) == 0:
                break

            for b in data:
                s = (s + b) % 255

    print('Sum % 255 = ', s)


main()
