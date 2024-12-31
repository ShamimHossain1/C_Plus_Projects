# Password Generator in C++

This repository contains a simple C++ program to generate random passwords of user-defined length. The program uses a combination of uppercase and lowercase letters, digits, and special characters to create strong and secure passwords.

## Features

- Generates random passwords of any length specified by the user.
- Includes uppercase letters, lowercase letters, digits, and special characters for enhanced security.
- Lightweight and easy-to-understand C++ code.

## How It Works

1. The user specifies the desired length of the password.
2. The program generates a random password using characters from the following set:
   `ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789!@#$%^&*()_+-`
3. The generated password is displayed on the console.

## Example

```bash
Enter the length of the Password :: 12
Generated Password :: aB3!@X2cY#1$
```

## Code Overview

### Main Function

The `main` function handles user interaction:

- Prompts the user to input the desired password length.
- Calls the `getPass` function to generate the password.
- Displays the generated password.

### `getPass` Function

The `getPass` function:

- Takes the desired password length as input.
- Uses the `rand()` function to randomly select characters from the predefined set of characters.
- Constructs the password by appending randomly chosen characters.

## Notes

- The `srand(time(0))` function ensures unique randomization for each program run.
- Special characters are included to improve password strength.
