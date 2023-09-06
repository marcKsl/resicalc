#include <stdio.h>
#include <string.h>

int getColorValue(char *color)
{
    // Check for valid input
    if (strcmp(color, "black") == 0)
        return 0;
    if (strcmp(color, "brown") == 0)
        return 1;
    if (strcmp(color, "red") == 0)
        return 2;
    if (strcmp(color, "orange") == 0)
        return 3;
    if (strcmp(color, "yellow") == 0)
        return 4;
    if (strcmp(color, "green") == 0)
        return 5;
    if (strcmp(color, "blue") == 0)
        return 6;
    if (strcmp(color, "violet") == 0)
        return 7;
    if (strcmp(color, "gray") == 0)
        return 8;
    if (strcmp(color, "white") == 0)
        return 9;
    return -1;
};

float getTolerance(char *color)
{

    // Check for valid input
    if (strcmp(color, "brown") == 0)
        return 1;
    if (strcmp(color, "red") == 0)
        return 2;
    if (strcmp(color, "green") == 0)
        return 0.5;
    if (strcmp(color, "blue") == 0)
        return 0.25;
    if (strcmp(color, "violet") == 0)
        return 0.1;
    if (strcmp(color, "gold") == 0)
        return 5;
    if (strcmp(color, "silver") == 0)
        return 10;
    return 20;
}

int main(int argc, char *argv[])
{

    // Used to suffix the value if it exceeds 1K or 1M
    char suffix = '\0';
    float tolerance = 20;

    // Check for correct amount of arguments
    if (argc < 3 || argc > 6)
    {
        printf("Invalid number of arguments. \n");
        printf("Usage: resicalc <color1> <color2> <multiplier> <tolerance> <temperature coefficient \n");
        return 1;
    }

    int first = getColorValue(argv[1]);
    int second = getColorValue(argv[2]);

    // Check if the first two inputs are valid
    if (first == -1 || second == -1)
    {
        printf("Invalid colors. \n");
        printf("Usage: resicalc <color1> <color2> <multiplier> <tolerance> <temperature coefficient \n");
        return 1;
    }

    // Needs to be long long
    // To ensure sufficient storage for the result of multiplying 'first' by 10 and adding 'second',
    // which could potentially overflow a long
    long long resistance = first * 10 + second;

    int multiplier = getColorValue(argv[3]);

    // Check if multiplier is valid
    if (multiplier == -1)
    {
        printf("Invalid multiplier. \n");
        printf("Usage: resicalc <color1> <color2> <multiplier> <tolerance> <temperature coefficient \n");
        return 1;
    }

    // Tolerance needs no check, even if a wrong argument is given
    // It just defaults to 20 if not specified further
    if (argc > 4)
    {
        tolerance = getTolerance(argv[4]);
    }

    // Apply multiplier and suffix
    for (int i = 0; i < multiplier; i++)
    {
        resistance *= 10;
    }

    if (resistance > 999)
    {
        resistance /= 1000;
        suffix = 'K';
    }

    if (resistance > 999)
    {
        resistance /= 1000;
        suffix = 'M';
    }

    printf("Resistance: %lld%c Ohm +- %.1f \n", resistance, suffix, tolerance);

    return 0;
}