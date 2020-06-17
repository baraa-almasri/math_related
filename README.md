# Matrix & SquareMatrix Classes Documentation

### Member private variables:
      
| **Name**    |   **Type**                              | **Usage**                      |
| :---------- | :-------------------------------------  | :----------------------------- |
| matrix      |   vector of vectors of floats           |  To hold matrix's elements     |
| rows        |   integer                               |  Number of rows                |
| columns     |   interger                              |  Number of columns             | 
| matrixName  |   string                                |  Matrix name                   |      
| zeroMatrix  |   vector of vectors of floats           |  Equivalent order zero matrix  |
| identityMatrix `in SquareMatrix` |  vector of vectors of floats           |  Equivalent order identity matrix  |
      
### Member functions:

**`Constructors:`**
- Matrix()
  
  default constructor creates a 1x1 matrix with name "M"
  
- Matrix(int rows, int columns, string matrixName)

  parameterized constructor, creates a matrix with the provided data `rows, columns, matrix name`
  

**`Operators:`**
  - operator +=
  
    adds an another matrix to the current matrix and returns the added matrix
  
  - operator *= 
  
    multiplies a matrix or a scalar with the current matrix and returns the resulting matrix
    
    
**`Matrix Operations:`**
  - transpose()
    
    returns transposed matrix of the current matrix
    
  - power(int exp)
  
    return a matrix raised to the given power
    
#### the rest for tomorow :)
