class Animal
  constructor: (name) ->
    @name = name
  say: (word) ->
    console.log "#{@name} said : #{word}"

class Dog extends Animal
  constructor: (name) ->
    super name
  say: (word) ->
    super "Bowwow, #{word}"

animal = new Animal("Bob")
animal.say("Hello!")

dog = new Dog("Bob")
dog.say("Hello!")