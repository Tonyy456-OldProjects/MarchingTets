import sys
import os
search_dir = "./../projects/"

# read sys argv
def main():
    if len(sys.argv) < 3:
        exit("#ERROR")

    search_dir = sys.argv[1]
    try:
        number = int(sys.argv[2])
        getNthFile(search_dir, number)
    except ValueError:
        exit("#ERROR")

# get the nth file
def getNthFile(directory, n):
    if os.path.isdir(directory):
        files = os.listdir(directory)
        if len(files) > n:
            file_path = os.path.join(directory, files[n])
            print(file_path)
        else:
            exit("#ERROR")
    else:
        exit("#ERROR")

if __name__ == "__main__":
    main()
