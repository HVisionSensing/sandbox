var fib, i;

fib = function(n) {
  if (n < 2) {
    return n;
  } else {
    return fib(n - 1) + fib(n - 2);
  }
};

for (i = 1; i <= 10; i++) {
  console.log("fib(" + i + ") => " + (fib(i)));
}
