;;;
;;; @see ANSI Common Lisp, Chapter 02
;;;

;;; 2.1 式

;;; 2.2 評価

;;; 2.3 データ

;;; 2.4 リストオペレータ

;;; 2.5 真
;;; Lispでは真偽を判別する関数を述語(predicate)と呼ぶ

;;; listp : リストに対して真を返す
(listp '(1 2 3)) ;; ==> T
(listp nil) ;; ==> T
(listp 27)  ;; ==> NIL

;;; null : 空リストに対して真を返す
(null '(1 2 3)) ;; ==> NIL
(null nil) ;; ==> T
(null ())  ;; ==> T
(null 27)  ;; ==> NIL

;;; not : 偽である引数に対して真を返す
(not nil)  ;; ==> T

;;; if : テスト式、then式、else式の3つを引数に取り
;;;      テスト式の真偽に応じてthen/else式を評価しその値を返す
(if (listp '(1 2 3))
	'(i am list)
    '(i am not list)) ;; ==> I AM LIST

;;; and : 全ての引数が真の場合、最後の引数を返す
;;; or  : 真となる引数を見つけた時点で、その引数を返す (残りの引数は評価しない)
(and t (+ 1 2) (+ 3 4))  ;; ==> 7
(or nil (- 1 2) (/ 1 0)) ;; ==> -1 ((/ 1 0)は評価されない)


;;; 2.6 関数
;;; defunで新しい関数を定義できる
(defun my-third (lst)
  (car (cdr (cdr lst))))


;;; 2.7 再帰
(defun my-member (obj lst)
  (if (null lst)
	  nil
	  (if (eql (car lst) obj)
		  lst
		  (my-member obj (cdr lst)))))

(my-member 'b '(a b c)) ;; ==> (B C)
(my-member 'z '(a b c)) ;; ==> NIL


;;; 2.8 Lispのコードの読み書き




