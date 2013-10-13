;;;
;;; @see also Land of Lisp
;;;

;;; ゲーム中の場所の描写を記述
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


;;; 場所から場所への通り道を記述
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
  `(there is a ,(caddr edge) going ,(cadr edge) from here))








