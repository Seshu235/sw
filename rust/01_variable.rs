fn main()
{
  let logical: bool = true;

  // Type 1 implementation : Regular Annotation
  let float1:f64 = 1.0;
  let integer1:i32 = 1;

  println!("{float1:?} and {integer1:?}");
  
  // Type 2 implementation : Suffix Annotation
  let float2 = 3.5f64;
  let integer2 = 5i32;

  println!("{float2:?} and {integer2:?}"); 

  // Type 3 implementation : Default type
  let default_float = 7.0;  //  floats default to 'f64' 
  let default_integer = 3;  //  integers default to 'i32'

  println!("{default_float:?} and {default_integer:?}");
  
  // A type can also be inferred from context.
  let mut inferred_type = 12; // Default i32 ==> Type i64 is inferred from another line.
  inferred_type = 4294967296i64;  // Type i64 is inferred here in this line.

  // A mutable variable's value can be changed
  let mut mutable1 = 12;  //  Mutable i32
  mutable1 = 21i64; 

  // Error! type of a variable cannot be changed
  // mutable1 = true;

  // variable can be overwritten with shadowing
  let mutable1 = true;
}