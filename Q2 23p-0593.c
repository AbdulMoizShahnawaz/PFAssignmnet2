#include <stdio.h>

// Function to calculate Collatz sequence length for numbers up to 'a'
int collatz(int *a){
    int i; 
    int s=0; // Variable to store the length of the longest sequence
    int st = 0; // Variable to store the starting number with the longest sequence

    // Loop through each number from 1 to 'a'-1
    for(i = 1; i < *a; i++) {
        int l = 1; // Initialize sequence length to 1 for each starting number
        long long num = i; // Store the current number to handle larger numbers

        // Generating Collatz sequence until reaching 1
        while(num != 1) {
            if(num % 2 == 0) {
                num = num / 2; // If the number is even, divide by 2
            } else {
                num = (num * 3) + 1; // If the number is odd, multiply by 3 and add 1
            }
            l++; // Increment sequence length
        }

        // Checking if the current sequence is longer than the previous longest sequence
        if(l > s) {
            s = l; // Updating the longest sequence length
            st = i; // Updating the starting number with the longest sequence
        }
    }

    // Print the result
    printf("The starting number is %d with the longest sequence is %d", *a, st);
    printf("\n");
    printf("Length of sequence: %d", s);
}

int main() {
    int n; // Variable to store the user input (limit)
   
    printf("Enter number: ");
    scanf("%d", &n); // Input limit from user
    collatz(&n); // Call collatz function to calculate and print the result
    return 0;
}

