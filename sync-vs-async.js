// 1. Every async function automatically returns Promise even if not specified explicitly
async function example1() {
  console.log("Hello");
}
console.log("Example1 :- ", example1());

// 2. If async function returns string, then it will be wrapped in Promise
async function example2() {
  return "Hello";
}
console.log("Example2 :- ", example2());

// 3. If async function returns number, then it will be wrapped in Promise
async function example3() {
  return 10;
}
console.log("Example3 :- ", example3());

// 4. If async function returns promise, then it stays as it is
async function example4() {
  return Promise.resolve("Hi");
}
console.log("Example4 :- ", example4());

// 5. If async function throws error, it will be wrapped in Promise
async function example5() {
  throw new Error("Oops!");
}
console.log("Example5 :- ", example5());
