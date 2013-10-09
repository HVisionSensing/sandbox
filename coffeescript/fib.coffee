fib = (n) ->
  if n < 2
    n
  else
    fib(n-1) + fib(n-2)

for i in [1..10]
  console.log("fib(#{i}) => #{fib(i)}")
