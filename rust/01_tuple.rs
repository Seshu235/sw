fn main() {
  // A Tuple with a bunch of different types
  let long_tuple = (1u8, 2u16, 3u32, 4u64,
                  -1i8, -2i16, -3i32, -4i64,
                  0.1f32, 0.2f64,
                  'a', true);
  
  // Values can be extracted from tuple using tuple indexing
  println!("long tuple first value {}", long_tuple.0);
  println!("long tuple 6th value {}", long_tuple.5);
  println!("long tuple 9th value {}", long_tuple.8);
  println!("long tuple 11th value {}", long_tuple.10);
  println!("long tuple 12th value {}", long_tuple.11);

  // Tuples can be printable
  println!("long tuple: {:?}", long_tuple);
  
  // Tuples can be tuple members
  let tuple_of_tuples = ((1u8, 2u16, 3u32), (4u64, -1i8), -2i16);

  println!("tuple of tuples: {:?}", tuple_of_tuples);

  // Long tuples (more than 12 elements) cannot be printed
  // let too_long_tuple = (1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13);  // This line will result in compile-time warning
  // println!("Too long Tuple: {:?}", too_long_tuple);  // This line will result in compile-time error
  // TODO ^ uncomment the above 2 lines to see the compiler error

  let pair = (1, true);
  println!("Pair is {:?}", pair);

  println!("Reverse of pair: {:?}", reverse(pair));

  // To create one element tuple, the comma is required 
  // to tell them apart from literal surrounded by paranthesis
  println!("One element tuple: {:?}", (8u32,));
  println!("Just an integer: {:?}", (8u32));

  // Tuple can be destructured to create bindings
  let tuple = (1, "hello", 4.5, true);

  let (a, b, c, d) = tuple;
  println!("a: {} b: {} c: {} d: {}", a, b, c, d);

  let matrix = (1.1, 1.2, 2.1, 2.2);
  println!("{:?}", matrix);
  // println!("matrix: {}", matrix);
}

// Tuples can be used as function arguments and as return Values
fn reverse(pair: (i32, bool)) -> (bool, i32) {
  // let can be used to bind the members of a tuple to variables
  let (int_param, bool_param) = pair;

  return (bool_param, int_param);
}