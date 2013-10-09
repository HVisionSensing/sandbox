
# 配列を作って返す
func1 = ->
  a = [1,2,3,4,5]
  b = []
  for i in a
    b.push(i)
  for i in a
    console.log("=> #{b.pop()}")
  return

# 何も返さない
func2 = ->
  for i in [1..10]
    console.log("=> #{i}")
  return

console.log("func1")
func1()
console.log("func2")
func2()
