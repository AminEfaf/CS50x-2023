#include <stdio.h>
#include <cs50.h>

int main(void)
{
    // getting name from user
    string name = get_string("What is your name?\n");
    // saying hello to user
    printf("hello, %s\n", name);
}