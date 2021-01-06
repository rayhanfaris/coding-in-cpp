# Stringstream

stringstream is a stream class to operate on strings.stringstream can be helpful in different type of parsing. 
* The following operators/functions are commonly used here
  1. Operator >> Extracts formatted data.
  2. Operator << Inserts formatted data.
  3. Method str() Gets the contents of underlying string device object.
  4. Method str(string) Sets the contents of underlying string device object.

One common use of this class is to parse comma-separated integers from a string (e.g., "23,4,56").
> stringstream ss("23,4,56");  
> char ch;  
> int a, b, c;  
> ss >> a >> ch >> b >> ch >> c;  // a = 23, b = 4, c = 56
  
#### Sample Input
> 23,4,56
  
#### Sample Output
> 23  
> 4  
> 56
