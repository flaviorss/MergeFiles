Merge Files

This implementation performs the process of merging two files whose records are sorted, generating a single file whose records are the union of the original records of the two files, sorted.
The program receives, as standard input, the names of the two files on which the merge operation must be applied.
The format of each record in the files is composed of two fields, the first being an integer written in binary mode, through a call to the fwrite function with a pointer to a C long long int. The second field of each record is a sequence of letters that can be printed on screen, without the end-of-line \n, whose size is exactly the integer stored in the first field.
The program prints on the standard output the sequence of strings of the second fields of the records of the file resulting from the generated Merge, in the order in which they are in the output file (ordered).