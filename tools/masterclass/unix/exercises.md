# Exercise 1 (unix commands): 
Mess around with the unix commands of `mkdir`, `cp -`, `ls`, `clear`, `mv`. For around ~5 min suggestions include:
- Making a folder
- Making a new file.
- Moving the new file into the new folder.
- Rename the file.
- Move one step back, create another file, and copy it to the directory.
- Check the contents of the directory.
- Remove one file.
- Clearing the terminal with `clear`.

# Exercise 2:
## Task 1:
Try changing the owner and group, of one of the directories/files from last exercise.

If in need, you can create a user and group by:
- You can create a new user with : `sudo useradd username`
- And to create password : `sudo passwd username`
- You can create a new group with the :`sudo groupadd groupname`

## Task 2:
Write down what each character says about the file/directory, for the following two permission lines:
- drwxrwxrwx
- -rw--wx--x

## Task 3:
Write a `chmod` command for a file/directory from exercise1 where:
- Owner have write, read, and execute permission
- Group have read, and execute permission
- Others only have read permission.


# Exercise 3:
## Task 1:
```c
void print_example(int importantNumber) {
  if (fprintf("Output.txt", "The chosen number is (%d)\n",
    importantNumber) <= 0) {
  exit(EXIT_FAILURE);
  }
}
```
With the help of the manual command `man` in the terminal do the following:
In your own words, describe what this function does.
Hints:
- Consider the difference between `fprintf` and `printf`
- Consider what the if statement does/when the condition is true.

## Task 2:

With the help of the manual command `man` in the terminal do the following:
Either show via psuedocode, or explain in your own words:
How would you, check that a file given as argument to `fopen` was a successfully opened using said function?

Hints:
- A file is not successfully opened, if the filename given as an argument does not exist
- Look at the return section of the manual page of `fopen`
- Consider that if the file is indeed opened correctly, it should be able to be used afterwards. 
- If writing psuedocode, please do not worry about the correctness of the code, at all.

# Extra resources
If you want to read more about what you can do in the command-line:
[Unix-Like Data Processing 2017](https://github.com/diku-summer-programming/DSoP21/blob/main/uldp17-2018-08-16.pdf)
If you want to practice (and learn more):
[The Bandit wargame](https://overthewire.org/wargames/bandit/)

