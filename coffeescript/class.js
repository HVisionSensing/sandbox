var Animal, Dog, animal, dog,
  __hasProp = Object.prototype.hasOwnProperty,
  __extends = function(child, parent) { for (var key in parent) { if (__hasProp.call(parent, key)) child[key] = parent[key]; } function ctor() { this.constructor = child; } ctor.prototype = parent.prototype; child.prototype = new ctor; child.__super__ = parent.prototype; return child; };

Animal = (function() {

  function Animal(name) {
    this.name = name;
  }

  Animal.prototype.say = function(word) {
    return console.log("" + this.name + " said : " + word);
  };

  return Animal;

})();

Dog = (function(_super) {

  __extends(Dog, _super);

  function Dog(name) {
    Dog.__super__.constructor.call(this, name);
  }

  Dog.prototype.say = function(word) {
    return Dog.__super__.say.call(this, "Bowwow, " + word);
  };

  return Dog;

})(Animal);

animal = new Animal("Bob");

animal.say("Hello!");

dog = new Dog("Bob");

dog.say("Hello!");
