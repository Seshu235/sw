use std::mem;

fn main() {
  let array1: [i32; 5] = [1, 2, 3, 4, 5];
  println!("array1: {:?}", array1);

  // All elements can be initialized to same value
  // let array2: [i32; 2] = [0; 2];
  // println!("array2: {:?}", array2);

  // Indexing starts at 0
  println!("First element of the array: {}", array1[0]);
  println!("Second element of the array: {}", array1[1]);
  
  // 'len' returns the count of elements in the array
  println!("Number of elements in the array1: {}", array1.len());

  // Arrays are stack allocated
  println!("Array occupies {} bytes", mem::size_of_val(&array1));

  // Arrays can be automatically borrowed as slices
  println!("Borrow the whole array as slice.");
  analyze_slice(&array1); 

}

// This function borrows a slice
fn analyze_slice(slice: &[i32]) {
  println!("First element of slice: {}", slice[0]);
  println!("The slice has {} elements", slice.len())
}