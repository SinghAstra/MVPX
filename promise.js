// Promise is an object that represents the eventual completion (or failure) of an asynchronous operation and its resulting value.

// A Promise is in one of these states:
// pending: initial state, neither fulfilled nor rejected.
// fulfilled: meaning that the operation completed successfully.
// rejected: meaning that the operation failed.

// 1. Creating a Promise using the Promise constructor
// Promise constructor has two parameters : resolve and reject
// const promise = new Promise((resolve, reject) => {
//   setTimeout(() => {
//     const randomBoolean = Math.random() < 0.5;
//     if (randomBoolean) {
//       resolve("Promise is resolved successfully");
//     } else {
//       reject("Promise is rejected");
//     }
//   }, 1000);
// });
// promise
//   .then((value) => console.log(value))
//   .catch((error) => console.log(error));

// 2. Promise Chaining is used when we perform multiple asynchronous operations in sequence,
//  where each operation starts when the previous one completes.
// Each .then() returns a new Promise, allowing you to chain operations.
// fetchUserProfile(userId)
//   .then((profile) => fetchUserPosts(profile.id))
//   .then((posts) => filterPosts(posts))
//   .then((filteredPosts) => console.log(filteredPosts))
//   .catch((error) => console.log("Error:", error));

// 3. Promise.all() method takes an array of promises and returns a single Promise that resolves when all of the promises have resolved.
// const promises = [
//   fetch("/api/users"),
//   fetch("/api/posts"),
//   fetch("/api/comments"),
// ];

// Promise.all(promises)
//   .then(([users, posts, comments]) => {
// All requests completed successfully
//   })
//   .catch((error) => {
// If any promise fails, catch runs
//   });

function simulateAPI(shouldSucceed) {
  return new Promise((resolve, reject) => {
    setTimeout(() => {
      if (shouldSucceed) {
        resolve("Data fetched successfully");
      } else {
        reject(new Error("Failed to fetch data"));
      }
    }, 1000);
  });
}
// 4.  .then() in Promises
// The .then() method is used to handle the successful completion of a Promise.
// It takes two optional arguments:
// A function for success (resolve)
// A function for failure (reject)
simulateAPI(false).then(
  (response) => console.log("Success:", response),
  (error) => console.log("Error:", error)
);

// 5. .catch() in Promises
// The .catch() method handles any errors that occur in a Promise chain.
//  It's equivalent to .then(null, errorHandlingFunction).
// Catches errors from both the Promise and previous .then() blocks
// Should be placed at the end of Promise chains
simulateAPI(false)
  .then((response) => console.log("Success:", response))
  .catch((error) => console.log("Error:", error));

// 6. async await in Promises
// syntactic sugar for Promises that make asynchronous look synchronous
// error handling uses try catch block
// more readable then promise chain
// can handle multiple operations in one try block
