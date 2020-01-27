#!/usr/bin/python3

def remove_comments(infile: str, outfile: str) -> None:
    fin = open(infile, "r")
    fout = open(outfile, "w")

    for line in fin:
        try:
            position = line.index("#")
            fout.write(line[:position])
        except:
            fout.write(line+"\n")

    fin.close()
    fout.close()

    return

if __name__ == '__main__':
    infile = input("Enter the input file-name: ")
    outfile = input("Enter the output file-name: ")

    remove_comments(infile, outfile)