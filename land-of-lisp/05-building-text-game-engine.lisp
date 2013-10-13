;;;
;;; @see also Land of Lisp
;;;

;;; ゲーム中の場所の描写をalistで記述
;;; 描写はあえて文字列ではなく、Lispで最も操作しやすいシンボルとリストで持つ
(defparameter *nodes*
  '((living-room
	 (you are in the living-room.
		  a wizard is shoring loudly on the couch.))
	(garden
	 (you are in a beautiful garden.
		  there is a well in front of you.))
	(attic
	 (you are in the attic.
		  there is a giant welding torch in the corner.))
	))


;;; assoc はリスト中からキーを元に要素を取り出す
(assoc 'garden *nodes*) ;; ==> (garden (you are ...))

;;; assocを利用してdescribe-locationを実装する
;;; 
;;; 関数型プログラミングスタイルでは、関数は引数か関数内で宣言された変数しか
;;; 参照しない。ここでもそのスタイルを継承する
(defun describe-location (location nodes)
  (cadr (assoc location nodes)))


;;; 場所から場所への通り道をalistで記述
(defparameter *edges*
  '((living-room
	 (garden west door)
	 (attic upstairs ladder))
	(garden
	 (living-room east door))
	(attic
	 (living-room downstairs ladder))
	))

;;; エッジから通り道の説明文を取得
;;;
;;; `は()の中をデータモードで扱う点は'と同じだが、
;;; ()内で,が使われるとコードモードが実行される
(defun describe-path (edge)
  `(there is a ,(caddr edge) going ,(cadr edge) from here.))

;;; 複数の通り道を１度に描写
;;;
;;; #' はfunctionオペレータの略記。
;;; Common Lispでは関数を値として扱う場合、上記を使ってそれを明記しなければならない。
;;; (関数と変数で名前が衝突すると思わぬエラーを引き起こすため)
;;; Schemeではいちいちfunctionオペレータを付ける必要はない
;;;
;;; appendは結合したいリストを別々の引数で渡す必要があるため、
;;; そのまま使っても上手く機能しない。
;;; applyに関数とリストを渡すと、あたかもそのリストの各要素を引数として
;;; 関数を呼び出したかのように動作するため、この場合でも上手く機能する
(defun describe-paths (location edges)
  (apply #'append (mapcar #'describe-path (cdr (assoc location edges)))))


;;; ゲームの世界のオブジェクトを記述
(defparameter *objects*
  '(whiskey bucket frog chain))

(defparameter *object-locations*
  '((whiskey living-room)
	(bucket living-room)
	(chain garden)
	(frog garden)))

;;; 与えられた場所から見えるオブジェクトのリストを返す
;;; remove-if-not は関数が真を返すような要素だけを選び出すフィルタのようなもの
(defun objects-at (loc objs obj-locs)
  (labels ((at-loc-p (obj)
			 (eq (cadr (assoc obj obj-locs)) loc)))
	(remove-if-not #'at-loc-p objs)))

;;; 見えるオブジェクトを描写する
(defun describe-objects (loc objs obj-locs)
  (labels ((describe-obj (obj)
			`(you see a ,obj on the floor.)))
	(apply #'append (mapcar #'describe-obj (objects-at loc objs obj-locs)))))

					 
