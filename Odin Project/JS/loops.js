// outer: for (let i = 0; i < 9; i++) {
//   for (let j = 0; j < 9; j++) {
//     // Could use "inner: " but we only need the outer label to break both inner + outer so no label needed here
//     let input = prompt("Enter some selection: ");
//     if (!input) break outer; // We could break out of both loops using a labelled break, such as when invalid input is given
//   }
// }

//// Loop through 2-10 and print out only the even numbers
// for (let i = 2; i <= 10; i++) {
//   if (i % 2 == 0) {
//     console.log(i);
//   }
// }

do {
  num = prompt("Enter a number greater than 100?", 0);
} while (num <= 100 && num);
