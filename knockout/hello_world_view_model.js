/**
 * @see knockout demo&tips
 */

// ViewModel を定義する
var ViewModel = function(first, last) {
	// Observable はプロパティを監視するfunctionであり、
	// プロパティのSubscriberに変更通知を行う
    this.firstName = ko.observable(first);
    this.lastName = ko.observable(last);
      
    this.fullName = ko.computed(function() {
        // Computed Observable は一つ以上の Observable に依存する
		// function であり、 依存している Observable の変更により
		// 自動的に更新される
        return this.firstName() + " " + this.lastName();
    }, this);
};
 
// Knockout を起動する
ko.applyBindings(new ViewModel("Planet", "Earth"));

