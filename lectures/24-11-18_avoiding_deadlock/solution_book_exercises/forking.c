
void try()
{
    if (fork() == 0) { // 1 process running (the child) (parent will go to the else branch)
        fork();  // 2 processes running
        fork(); // 4 processes running (each of the 2 processes above forked)
        printf("Example\n");
        return; // return (produces 9 Examples) , exit(0)  produces 5 Examples
    }
    return;
}

int main()
{
    try();
    printf("Example\n");
    exit(0);
    return 0;
}
