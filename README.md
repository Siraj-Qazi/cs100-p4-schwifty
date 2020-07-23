# Project 4: Schwifty

### Description

This is C Programming Project 4 of a CS 100 Computer Science I For Majors course that I took. Mainly includes a practice for string manipulation and formatted output etc. in C.

### Prerequisites

```
 C11
```

### Building and Running

Compile with gcc:

```
gcc schwifty.c -o flipped
```

To execute:

```
./schwifty <input-file-name> <commands>
```

### Project Requirements (from PDF)

This program reads a text file and makes it schwifty. The user supplies the filename to schwift and a string containing a sequence of the following characters to determine the schwiftiness via command line arguments:
  * **L** - Left shift each character in a word:
      ** hello --> elloh
  * **R** - Right shift each character in a word:
      ** elloh --> hello
  * **I** - Shift the letters' and digits' value "up" by one (wraps if necessary) and keeps other characters as the same:
      ** a --> b
      ** Y --> Z
      ** 2 --> 3
      ** z --> a (wrap)
      ** 9 --> 0 (wrap)
      ** \[ --> \[ (same: not letter or digit)
    **D** - Shift the letters' and digits' value "down" by one (wraps if necessary) and leaves other characters as the same:
      ** b --> a
      ** Z --> Y
      ** 3 --> 2
      ** a --> z (wrap)
      ** 0 --> 9 (wrap)
      ** \[ --> \[ (same - not letter or digit)

![sample1](/samples/sample1.png)

![notes](/samples/notes.png)
 
## Built With

* [CLion](https://www.jetbrains.com/clion/) - A cross-platform IDE for C and C++

## Authors

* **Siraj Qazi**

## License

This project is licensed under the GNU General Public License - see the [LICENSE.md](LICENSE.md) file for details

## Acknowledgments

 - [PurpleBooth](https://github.com/PurpleBooth) for the simplistic README template.
