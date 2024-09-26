# CubeEncoder

## Project Description

This project implements the **CubeEncoder** class, which encodes and decodes text using a 2D matrix (cube) of characters. The input string is transformed into a square matrix, and then various encoding operations, such as cyclic shifts of rows, columns, or diagonal swaps, are applied. The class also supports decoding the encoded text back to its original form.

## Program Structure

### `CubeEncoder` Class

This class provides the main functionality for encoding and decoding. Key methods and functionalities include:

- **Constructor `CubeEncoder(const string& text)`**: Initializes the encoder with the provided text. It calculates the smallest square size that can fit the text and fills the matrix (cube) with the characters from the string.

- **`find_size(int size)`**: Helper function that determines the size of the square matrix required to fit the text.

- **`fill_cube(const string& original_text)`**: Fills the matrix (cube) with the characters of the string in a row-by-row manner.

- **`encode(Coder type)`**: Encodes the string using the chosen encoding strategy. Options include:
  - `right`: Shifts each row to the right.
  - `left`: Shifts each row to the left.
  - `up`: Shifts rows upwards.
  - `down`: Shifts rows downwards.
  - `x`: Diagonal swap based on the reverse diagonal (i.e., flips elements across the reverse diagonal).

- **`decode(Coder type)`**: Decodes the encoded string by reversing the chosen encoding operation.

### Encoding Operations
- **Right (`right_encode`)**: Shifts each row of the matrix to the right by one position.
- **Left (`left_encode`)**: Shifts each row of the matrix to the left by one position.
- **Up (`up_encode`)**: Moves all rows one position upwards.
- **Down (`down_encode`)**: Moves all rows one position downwards.
- **X-diagonal (`x_encode`)**: Swaps elements along the reverse diagonal of the matrix.

### Decoding Operations
The decoding operations are essentially the inverse of the corresponding encoding operations:
- **Right** encoding can be undone by **left** decoding and vice versa.
- **Up** encoding can be undone by **down** decoding and vice versa.
- **X-diagonal** encoding is symmetric, meaning it can be undone by the same `x_encode()` function.

### Example Usage
```cpp
int main(){
    CubeEncoder encoder("Hovhannes Kharazyan");
    
    // Apply right encoding
    string encoded = encoder.encode(CubeEncoder::Coder::right);
    
    // Apply diagonal encoding after right encoding
    encoded = encoder.encode(CubeEncoder::Coder::x);    
    cout << "Encoded: " << encoded << endl;
    
    // Decode the diagonal encoding
    encoder = encoded;
    encoder = encoder.decode(CubeEncoder::Coder::x);
    
    // Decode the right encoding
    encoded = encoder.decode(CubeEncoder::Coder::right);
    cout << "Decoded: " << encoded << endl;
}
```

### Output
```
Encoded: (Encoded text here)
Decoded: Hovhannes Kharazyan
```

## How to Run
1. Copy the provided code into your C++ development environment.
2. Compile the code using a C++ compiler:
   ```bash
   g++ -o cube_encoder cube_encoder.cpp
   ```
3. Run the compiled program:
   ```bash
   ./cube_encoder
   ```

## Features
- Supports 5 types of encoding: right, left, up, down, and diagonal swap (`x`).
- Efficiently handles square matrices, automatically adjusting the matrix size based on the length of the input text.
- Simple interface for both encoding and decoding operations.

