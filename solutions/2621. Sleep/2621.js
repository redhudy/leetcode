// Time Complexity: O(1)
// Space Complexity: O(1)
async function sleep(millis) {
  return new Promise(resolve => {
    setTimeout(resolve, millis);
  });
}