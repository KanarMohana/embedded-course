#ifndef FILESWORK_H
#define FILESWORK_H

/*
description - Writes an array of Person records to a binary file ("persons.dat").
input - _persons: array of Person, _Size: number of elements.
output - 1 on success, 0 on failure.
error - returns 0 if file cannot be opened or fwrite fails.
*/
int binary_write_persons(Person* _persons, int _Size);


/*
description - Writes an array of Person records to a text file ("persons.data").
input - _persons: array of Person, Size: number of elements.
output - 1 on success, 0 on failure.
error - returns 0 if file cannot be opened.
*/
int write_persons(Person *_persons, int Size);


/*
description - Reads Person records from binary file ("persons.dat") into buffer.
input - buffer: destination array, size: number of elements to read.
output - 1 if exactly size records were read, 0 otherwise.
error - returns 0 if file cannot be opened or fread reads fewer than size.
*/
int binary_read_persons(Person* buffer, int size);


/*
description - Reads and prints all Person records from text file ("persons.data").
input - none.
output - 1 on success, 0 on failure.
error - returns 0 if file cannot be opened.
*/
int read_persons(void);


/*
description - Prints the last _n lines from a text file.
input - filename: file path, _n: number of last lines to print.
output - 1 on success, 0 on failure, -1 for invalid filename.
error - returns 0 if file cannot be opened.
*/
int print_last_n(char *filename, int _n);


/*
description - Counts lines and words in a text file (wc-like).
input - filename: file path.
output - (implementation dependent) should return counts or success flag.
error - returns 0 if file cannot be opened.
*/
int my_wc(char *filename);


/*
description - Counts frequency of letters in a text file and prints results (case-sensitive).
input - filename: file path.
output - 1 on success, 0 on failure.
error - returns 0 if file cannot be opened.
*/
int letter_freq(char *filename);


/*
description - Reads words from a text file, counts frequency of each word, and prints results.
input - filename: file path.
output - 1 on success, 0 on failure.
error - returns 0 if file cannot be opened.
*/
int word_freq(char *filename);

#endif
