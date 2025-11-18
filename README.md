My C Diary Management System

1. Project Description

This is a secure personal diary program written in C. It allows a user to write, view, and manage diary entries. All entries are protected by a password and are encrypted when saved to a file, so they cannot be read by anyone else.

2. Features

Core Features

[x] Password Protection: The program demands a password and allows only 3 attempts.

[x] Add Entry: Allows the user to add a new, dated diary entry.

[x] View All Entries: Shows all past entries in order.

[x] Search Entry: Allows the user to find a specific entry by its date.

[x] Encryption: All entries are encrypted before being saved to disk.

[x] Delete Entry: Deletes a specific entry by date.

[x] Update Entry: Updates the text of a specific entry.

Technical Features

File I/O: The project reads and writes data to a binary file (diery.dat).

Data Structure: Uses a C struct to organize the data for each entry.

Security: Uses a simple XOR ^ cipher for encryption.

3. How to Compile & Run

Compile the code:

gcc myproject.c -o mydiary


Run the program:

./mydiary


Enter the password: SUJAL_IS_THE_KING

4. Code Explanation

This is a reminder of how the most important parts of the code work.

struct DiaryEntry

This is the "blueprint" for our data. Each entry is saved as one of these:

struct DiaryEntry {
   char date[20];
   char text[100000];
};


encryptDecrypt(char *data)

This is the encryption function. It works by using a "secret key" ('K').

It loops through a string (like "Hello").

It takes each character (H, e, l, l, o) and runs an XOR (^) operation on it with the key.

Why it works: The magic of XOR is that it's reversible.

( 'H' ^ 'K' ) = '$' (an encrypted character)

( '$' ^ 'K' ) = 'H' (the original character)

We run this function once to save (encrypt) and again to view (decrypt).

addEntry()

Opens the file diery.dat in "ab" (append binary) mode. "Append" means it adds to the end without erasing.

Crucial Buffer Fix: It runs a while((c = getchar())...) loop first. This is to "eat" the leftover \n (Enter key) from the scanf in the main menu so fgets works correctly.

It gets the date and text from the user using fgets.

It calls encryptDecrypt() on the date and the text.

It writes the entire encrypted struct to the file using fwrite.

viewEntries()

Opens the file diery.dat in "rb" (read binary) mode.

Crucial Fix: Uses rewind(fp) and clearerr(fp) to reset the file pointer so the function can run multiple times.

It uses a while loop with fread to read one struct DiaryEntry at a time from the file.

Inside the loop:

It calls encryptDecrypt() on the date and text to make them readable.

It prints the readable data to the screen.

Closes the file after the loop finishes.

SearchEntries()

Gets a searchDate from the user.

Opens the file in "rb" mode.

It loops through every entry using fread.

Inside the loop:

It decrypts only the entry.date.

It compares the entry's date to the searchDate using strcmp.

If strcmp returns 0 (a match): It then decrypts the entry.text and prints the whole entry.

deleteEntries() & updateEntry()

These functions use a "Temporary File" logic because we cannot delete from the middle of a file in C.

Open the original file (diery.dat) for reading.

Open a new file (temp.dat) for writing.

Loop through every entry in the original file.

If the entry DOES NOT match: Copy it to temp.dat.

If the entry DOES match:

For Delete: Do nothing (skip it).

For Update: Ask the user for new text, encrypt it, and write the new version to temp.dat.

Close both files.

Delete the original file using remove().

Rename temp.dat to diery.dat using rename().My C Diary Management System

1. Project Description

This is a secure personal diary program written in C. It allows a user to write, view, and manage diary entries. All entries are protected by a password and are encrypted when saved to a file, so they cannot be read by anyone else.

2. Features

Core Features

[x] Password Protection: The program demands a password and allows only 3 attempts.

[x] Add Entry: Allows the user to add a new, dated diary entry.

[x] View All Entries: Shows all past entries in order.

[x] Search Entry: Allows the user to find a specific entry by its date.

[x] Encryption: All entries are encrypted before being saved to disk.

[x] Delete Entry: Deletes a specific entry by date.

[x] Update Entry: Updates the text of a specific entry.

Technical Features

File I/O: The project reads and writes data to a binary file (diery.dat).

Data Structure: Uses a C struct to organize the data for each entry.

Security: Uses a simple XOR ^ cipher for encryption.

3. How to Compile & Run

Compile the code:

gcc myproject.c -o mydiary


Run the program:

./mydiary


Enter the password: SUJAL_IS_THE_KING

4. Code Explanation

This is a reminder of how the most important parts of the code work.

struct DiaryEntry

This is the "blueprint" for our data. Each entry is saved as one of these:

struct DiaryEntry {
   char date[20];
   char text[100000];
};


encryptDecrypt(char *data)

This is the encryption function. It works by using a "secret key" ('K').

It loops through a string (like "Hello").

It takes each character (H, e, l, l, o) and runs an XOR (^) operation on it with the key.

Why it works: The magic of XOR is that it's reversible.

( 'H' ^ 'K' ) = '$' (an encrypted character)

( '$' ^ 'K' ) = 'H' (the original character)

We run this function once to save (encrypt) and again to view (decrypt).

addEntry()

Opens the file diery.dat in "ab" (append binary) mode. "Append" means it adds to the end without erasing.

Crucial Buffer Fix: It runs a while((c = getchar())...) loop first. This is to "eat" the leftover \n (Enter key) from the scanf in the main menu so fgets works correctly.

It gets the date and text from the user using fgets.

It calls encryptDecrypt() on the date and the text.

It writes the entire encrypted struct to the file using fwrite.

viewEntries()

Opens the file diery.dat in "rb" (read binary) mode.

Crucial Fix: Uses rewind(fp) and clearerr(fp) to reset the file pointer so the function can run multiple times.

It uses a while loop with fread to read one struct DiaryEntry at a time from the file.

Inside the loop:

It calls encryptDecrypt() on the date and text to make them readable.

It prints the readable data to the screen.

Closes the file after the loop finishes.

SearchEntries()

Gets a searchDate from the user.

Opens the file in "rb" mode.

It loops through every entry using fread.

Inside the loop:

It decrypts only the entry.date.

It compares the entry's date to the searchDate using strcmp.

If strcmp returns 0 (a match): It then decrypts the entry.text and prints the whole entry.

deleteEntries() & updateEntry()

These functions use a "Temporary File" logic because we cannot delete from the middle of a file in C.

Open the original file (diery.dat) for reading.

Open a new file (temp.dat) for writing.

Loop through every entry in the original file.

If the entry DOES NOT match: Copy it to temp.dat.

If the entry DOES match:

For Delete: Do nothing (skip it).

For Update: Ask the user for new text, encrypt it, and write the new version to temp.dat.

Close both files.

Delete the original file using remove().

Rename temp.dat to diery.dat using rename().My C Diary Management System

1. Project Description

This is a secure personal diary program written in C. It allows a user to write, view, and manage diary entries. All entries are protected by a password and are encrypted when saved to a file, so they cannot be read by anyone else.

2. Features

Core Features

[x] Password Protection: The program demands a password and allows only 3 attempts.

[x] Add Entry: Allows the user to add a new, dated diary entry.

[x] View All Entries: Shows all past entries in order.

[x] Search Entry: Allows the user to find a specific entry by its date.

[x] Encryption: All entries are encrypted before being saved to disk.

[x] Delete Entry: Deletes a specific entry by date.

[x] Update Entry: Updates the text of a specific entry.

Technical Features

File I/O: The project reads and writes data to a binary file (diery.dat).

Data Structure: Uses a C struct to organize the data for each entry.

Security: Uses a simple XOR ^ cipher for encryption.

3. How to Compile & Run

Compile the code:

gcc myproject.c -o mydiary


Run the program:

./mydiary


Enter the password: SUJAL_IS_THE_KING

4. Code Explanation

This is a reminder of how the most important parts of the code work.

struct DiaryEntry

This is the "blueprint" for our data. Each entry is saved as one of these:

struct DiaryEntry {
   char date[20];
   char text[100000];
};


encryptDecrypt(char *data)

This is the encryption function. It works by using a "secret key" ('K').

It loops through a string (like "Hello").

It takes each character (H, e, l, l, o) and runs an XOR (^) operation on it with the key.

Why it works: The magic of XOR is that it's reversible.

( 'H' ^ 'K' ) = '$' (an encrypted character)

( '$' ^ 'K' ) = 'H' (the original character)

We run this function once to save (encrypt) and again to view (decrypt).

addEntry()

Opens the file diery.dat in "ab" (append binary) mode. "Append" means it adds to the end without erasing.

Crucial Buffer Fix: It runs a while((c = getchar())...) loop first. This is to "eat" the leftover \n (Enter key) from the scanf in the main menu so fgets works correctly.

It gets the date and text from the user using fgets.

It calls encryptDecrypt() on the date and the text.

It writes the entire encrypted struct to the file using fwrite.

viewEntries()

Opens the file diery.dat in "rb" (read binary) mode.

Crucial Fix: Uses rewind(fp) and clearerr(fp) to reset the file pointer so the function can run multiple times.

It uses a while loop with fread to read one struct DiaryEntry at a time from the file.

Inside the loop:

It calls encryptDecrypt() on the date and text to make them readable.

It prints the readable data to the screen.

Closes the file after the loop finishes.

SearchEntries()

Gets a searchDate from the user.

Opens the file in "rb" mode.

It loops through every entry using fread.

Inside the loop:

It decrypts only the entry.date.

It compares the entry's date to the searchDate using strcmp.

If strcmp returns 0 (a match): It then decrypts the entry.text and prints the whole entry.

deleteEntries() & updateEntry()

These functions use a "Temporary File" logic because we cannot delete from the middle of a file in C.

Open the original file (diery.dat) for reading.

Open a new file (temp.dat) for writing.

Loop through every entry in the original file.

If the entry DOES NOT match: Copy it to temp.dat.

If the entry DOES match:

For Delete: Do nothing (skip it).

For Update: Ask the user for new text, encrypt it, and write the new version to temp.dat.

Close both files.

Delete the original file using remove().

Rename temp.dat to diery.dat using rename().My C Diary Management System

1. Project Description

This is a secure personal diary program written in C. It allows a user to write, view, and manage diary entries. All entries are protected by a password and are encrypted when saved to a file, so they cannot be read by anyone else.

2. Features

Core Features

[x] Password Protection: The program demands a password and allows only 3 attempts.

[x] Add Entry: Allows the user to add a new, dated diary entry.

[x] View All Entries: Shows all past entries in order.

[x] Search Entry: Allows the user to find a specific entry by its date.

[x] Encryption: All entries are encrypted before being saved to disk.

[x] Delete Entry: Deletes a specific entry by date.

[x] Update Entry: Updates the text of a specific entry.

Technical Features

File I/O: The project reads and writes data to a binary file (diery.dat).

Data Structure: Uses a C struct to organize the data for each entry.

Security: Uses a simple XOR ^ cipher for encryption.

3. How to Compile & Run

Compile the code:

gcc myproject.c -o mydiary


Run the program:

./mydiary


Enter the password: SUJAL_IS_THE_KING

4. Code Explanation

This is a reminder of how the most important parts of the code work.

struct DiaryEntry

This is the "blueprint" for our data. Each entry is saved as one of these:

struct DiaryEntry {
   char date[20];
   char text[100000];
};


encryptDecrypt(char *data)

This is the encryption function. It works by using a "secret key" ('K').

It loops through a string (like "Hello").

It takes each character (H, e, l, l, o) and runs an XOR (^) operation on it with the key.

Why it works: The magic of XOR is that it's reversible.

( 'H' ^ 'K' ) = '$' (an encrypted character)

( '$' ^ 'K' ) = 'H' (the original character)

We run this function once to save (encrypt) and again to view (decrypt).

addEntry()

Opens the file diery.dat in "ab" (append binary) mode. "Append" means it adds to the end without erasing.

Crucial Buffer Fix: It runs a while((c = getchar())...) loop first. This is to "eat" the leftover \n (Enter key) from the scanf in the main menu so fgets works correctly.

It gets the date and text from the user using fgets.

It calls encryptDecrypt() on the date and the text.

It writes the entire encrypted struct to the file using fwrite.

viewEntries()

Opens the file diery.dat in "rb" (read binary) mode.

Crucial Fix: Uses rewind(fp) and clearerr(fp) to reset the file pointer so the function can run multiple times.

It uses a while loop with fread to read one struct DiaryEntry at a time from the file.

Inside the loop:

It calls encryptDecrypt() on the date and text to make them readable.

It prints the readable data to the screen.

Closes the file after the loop finishes.

SearchEntries()

Gets a searchDate from the user.

Opens the file in "rb" mode.

It loops through every entry using fread.

Inside the loop:

It decrypts only the entry.date.

It compares the entry's date to the searchDate using strcmp.

If strcmp returns 0 (a match): It then decrypts the entry.text and prints the whole entry.

deleteEntries() & updateEntry()

These functions use a "Temporary File" logic because we cannot delete from the middle of a file in C.

Open the original file (diery.dat) for reading.

Open a new file (temp.dat) for writing.

Loop through every entry in the original file.

If the entry DOES NOT match: Copy it to temp.dat.

If the entry DOES match:

For Delete: Do nothing (skip it).

For Update: Ask the user for new text, encrypt it, and write the new version to temp.dat.

Close both files.

Delete the original file using remove().

Rename temp.dat to diery.dat using rename().My C Diary Management System

1. Project Description

This is a secure personal diary program written in C. It allows a user to write, view, and manage diary entries. All entries are protected by a password and are encrypted when saved to a file, so they cannot be read by anyone else.

2. Features

Core Features

[x] Password Protection: The program demands a password and allows only 3 attempts.

[x] Add Entry: Allows the user to add a new, dated diary entry.

[x] View All Entries: Shows all past entries in order.

[x] Search Entry: Allows the user to find a specific entry by its date.

[x] Encryption: All entries are encrypted before being saved to disk.

[x] Delete Entry: Deletes a specific entry by date.

[x] Update Entry: Updates the text of a specific entry.

Technical Features

File I/O: The project reads and writes data to a binary file (diery.dat).

Data Structure: Uses a C struct to organize the data for each entry.

Security: Uses a simple XOR ^ cipher for encryption.

3. How to Compile & Run

Compile the code:

gcc myproject.c -o mydiary


Run the program:

./mydiary


Enter the password: SUJAL_IS_THE_KING

4. Code Explanation

This is a reminder of how the most important parts of the code work.

struct DiaryEntry

This is the "blueprint" for our data. Each entry is saved as one of these:

struct DiaryEntry {
   char date[20];
   char text[100000];
};


encryptDecrypt(char *data)

This is the encryption function. It works by using a "secret key" ('K').

It loops through a string (like "Hello").

It takes each character (H, e, l, l, o) and runs an XOR (^) operation on it with the key.

Why it works: The magic of XOR is that it's reversible.

( 'H' ^ 'K' ) = '$' (an encrypted character)

( '$' ^ 'K' ) = 'H' (the original character)

We run this function once to save (encrypt) and again to view (decrypt).

addEntry()

Opens the file diery.dat in "ab" (append binary) mode. "Append" means it adds to the end without erasing.

Crucial Buffer Fix: It runs a while((c = getchar())...) loop first. This is to "eat" the leftover \n (Enter key) from the scanf in the main menu so fgets works correctly.

It gets the date and text from the user using fgets.

It calls encryptDecrypt() on the date and the text.

It writes the entire encrypted struct to the file using fwrite.

viewEntries()

Opens the file diery.dat in "rb" (read binary) mode.

Crucial Fix: Uses rewind(fp) and clearerr(fp) to reset the file pointer so the function can run multiple times.

It uses a while loop with fread to read one struct DiaryEntry at a time from the file.

Inside the loop:

It calls encryptDecrypt() on the date and text to make them readable.

It prints the readable data to the screen.

Closes the file after the loop finishes.

SearchEntries()

Gets a searchDate from the user.

Opens the file in "rb" mode.

It loops through every entry using fread.

Inside the loop:

It decrypts only the entry.date.

It compares the entry's date to the searchDate using strcmp.

If strcmp returns 0 (a match): It then decrypts the entry.text and prints the whole entry.

deleteEntries() & updateEntry()

These functions use a "Temporary File" logic because we cannot delete from the middle of a file in C.

Open the original file (diery.dat) for reading.

Open a new file (temp.dat) for writing.

Loop through every entry in the original file.

If the entry DOES NOT match: Copy it to temp.dat.

If the entry DOES match:

For Delete: Do nothing (skip it).

For Update: Ask the user for new text, encrypt it, and write the new version to temp.dat.

Close both files.

Delete the original file using remove().

Rename temp.dat to diery.dat using rename().
