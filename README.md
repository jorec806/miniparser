# miniparser

A lightweight C library for robust string-to-integer parsing with comprehensive error handling.

## Overview

Mini Parser provides a simple, safe API for converting strings to integers in C. Built with a focus on correctness and clear error reporting, it handles edge cases like overflow, invalid input, and malformed strings gracefully.

This project serves as a foundation for building more complex tokenizers and parsers.

## Current Implementation

**Completed:**
- ✅ NULL pointer validation
- ✅ Empty string detection
- ✅ Digit validation (0-9)
- ✅ Invalid character detection (tabs, newlines, non-numeric)
- ✅ No spaces between digits allowed
- ✅ Negative sign support
- ✅ Multiple sign rejection

**In Progress:**
- 🔄 Overflow detection (INT_MAX/INT_MIN bounds)
- 🔄 Leading zeros handling (valid but removed in output)

**Explicitly Not Supported (Yet):**
- ❌ Positive sign (+)
- ❌ Whitespace (leading/trailing/middle)
- ❌ Mathematical expressions

## Roadmap

### Phase 1: Core Parser (Current)
- Robust `str_to_int()` implementation
- Comprehensive error handling
- Unit tests

### Phase 2: Numeric Tokenizer
- Tokenize sequences of numbers
- Build on `str_to_int()` foundation

### Phase 3: General Tokenizer
- Extended tokenization for mixed input
- Support for additional data types

## API Reference

### `str_to_int`

Converts a string to an integer with error detection.
```c
int str_to_int(const char* str, int* out);
```

**Parameters:**
- `str`: Input string to parse (must be null-terminated)
- `out`: Pointer to store the resulting integer

**Returns:**
- `0`: Success - result stored in `out`
- `-1`: Error - invalid input, overflow, or malformed string

**Example:**
```c
#include "miniparser.h"

int main() {
    int result;
    
    if (str_to_int("123", &result) == 0) {
        printf("Parsed: %d\n", result);  // Output: Parsed: 123
    } else {
        printf("Parse error\n");
    }
    
    return 0;
}
```

## Usage

### Integration

Clone the repository and include the header in your project:
```bash
git clone https://github.com/jorec806/miniparser.git
```
```c
#include "miniparser.h"

int main() {
    int result;
    if (str_to_int("123", &result) == 0) {
        printf("%d\n", result);
    }
    return 0;
}
```

Compile with your project:
```bash
gcc your_program.c miniparser/parser.c -o your_program
```

## Contributing

This is a personal learning project, but suggestions and feedback are welcome! Feel free to:
- Open issues for bugs or feature requests
- Submit pull requests with improvements
- Share ideas for additional functionality

## License

MIT License

---

**Author:** Jose Ore  
**Contact:** jorec806@gmail.com  
**GitHub:** [@jorec806](https://github.com/jorec806)  
**Project Start:** January 2026
