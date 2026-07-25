# Calendar
# C Calendar Program

A console-based calendar program written in C that prints the full calendar for a given year, checks leap years, finds the day of the week for a specific date, displays some special days, and lets users save or read date-based notes from text files.

This project is useful for learning core C concepts such as functions, arrays, file handling, conditional logic, and console interaction. It also includes support for Gregorian leap-year rules and uses `conio.h` keyboard functions for quick key detection. [page:3][page:2]

## Features

- Print the full 12-month calendar for any entered year.
- Detect whether a year is a leap year.
- Find the weekday for a specific date.
- Show predefined international and national special days for selected dates.
- Save notes for a specific date into a text file.
- Read previously saved notes for a specific date.
- Exit quickly when the `ESC` key is pressed during execution.

## How It Works

The program asks the user to enter a year, then:
1. Calculates the first day of that year.
2. Checks whether the year is a leap year.
3. Prints the complete calendar month by month.
4. Lets the user either:
   - check another year,
   - work with a specific date and notes,
   - or exit the program.

For date-based queries, the program can:
- validate the entered month and day,
- calculate the weekday for that date,
- check whether the date matches a predefined special day,
- and save or read notes linked to that date.

## Project Structure

This program is currently contained in a single C source file and uses:

- Standard C libraries:
  - `stdio.h`
  - `stdlib.h`
- Non-standard console library:
  - `conio.h`

It also creates note files in the same folder where the program runs, using this format:

```text
note_DD_MM.txt
```

Example:

```text
note_25_12.txt
```

## Requirements

To compile and run this program, you need:

- A C compiler such as GCC
- A console environment
- Support for `conio.h`

`kbhit()` checks whether a keypress is available, and `getch()` reads it without waiting for Enter, which is how the program detects the `ESC` key. `conio.h` is a console I/O header and is not part of standard ANSI C, so portability depends on your compiler and platform. [page:2]

## Build and Run

### On Windows with GCC

Compile:

```bash
gcc calendar.c -o calendar
```

Run:

```bash
calendar
```

### On Windows with MinGW

Compile:

```bash
gcc calendar.c -o calendar.exe
```

Run:

```bash
calendar.exe
```

## Usage

After running the program:

- Enter a year.
- The program prints the yearly calendar.
- It tells you whether the year is a leap year.
- Then choose one of the options:
  - `Y` to check another year
  - `D` to work with a date
  - `X` to exit

When using the date option:
- Enter the month.
- Enter the day.
- The program shows the weekday.
- It checks whether that date is a special day.
- You can choose to:
  - write a note for that date
  - or read an existing note

## Example

```text
Enter any year: 2024
```

The program will:
- print the full calendar for 2024,
- report whether 2024 is a leap year,
- and allow additional date-based actions.

## Special Days Included

The program contains a hardcoded list of selected special days such as:

- New Year's Day
- Republic Day
- Valentine's Day
- International Women's Day
- Earth Day
- Independence Day (India)
- Christmas Day

These are stored inside the `special_day()` function using a `switch` statement by month.

## Notes Storage

Notes are saved as plain text files using append mode. That means if you write multiple notes for the same date, they will be added to the same file instead of replacing previous content.

Format used:

```text
note_DD_MM.txt
```

Example:

```text
note_14_02.txt
```

## Main Functions

### `check_escape()`
Checks whether the `ESC` key was pressed and exits the program immediately.

### `leap_or_not(int year)`
Determines whether the given year is a leap year using Gregorian leap-year rules: divisible by 4, except century years unless divisible by 400. [page:3]

### `first_day(int year)`
Calculates the weekday index of the first day of the given year.

### `print_calender(int year, int first_day, int leap)`
Prints the full calendar for all 12 months.

### `special_day(int month, int date)`
Checks whether a specific date matches a predefined special day.

### `save_note_of_date_based_on_date(int month, int date)`
Saves a note into a file associated with that date.

### `read_note_of_date_based_on_date(int month, int date)`
Reads saved notes from a file associated with that date.

### `date_validator(int month, int date, int leap)`
Validates whether the entered month and date are correct.

### `something_with_date(int year)`
Handles date-specific features such as weekday lookup, special day check, and note operations.

### `main()`
Entry point of the program and menu controller.

## Limitations

- The program uses `conio.h`, which is not standard C and may not work on all systems. [page:2]
- The file name and some function names use the spelling `calender` instead of `calendar`.
- `main()` is called recursively when choosing another year, which works for small usage but is not ideal design.
- February's day count is modified globally, which can lead to side effects if reused carelessly.
- The list of special days is fixed in source code and not loaded from a file or database.
- The program is fully console-based and has no graphical interface.

## Possible Improvements

- Replace recursive `main()` calls with a loop-based menu.
- Use a struct or separate modules for cleaner organization.
- Move special days into an external file for easier editing.
- Improve support for Linux and macOS by replacing `conio.h`.
- Add better note management, such as edit and delete options.
- Fix spelling and naming consistency, such as `print_calendar`.
- Reset February safely instead of modifying the global array directly.

## Gregorian Calendar Note

The leap-year logic in this project follows the Gregorian rule: years divisible by 4 are leap years, except years divisible by 100 unless they are also divisible by 400. [page:3]

## License

You can add your preferred license here, for example:

```md
This project is licensed under the MIT License.
```

## Author

Add your name here.

```md
Author: Your Name
```
