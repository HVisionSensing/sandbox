
(defun my-length (list)
  (if list
	  (1+ (my-length (cdr list)))
	0))

(my-length '(list with four symbols))


;; '() () nil 'nil は全て空リストとして扱われる
(eq '() nil)  ;; ==> T
(eq '() ())   ;; ==> T
(eq '() 'nil) ;; ==> T


;; Lispは普通の関数呼び出しでは、関数名の後に続く式は、
;; 関数自体が呼ばれる前に全て評価されるが、if はその規則に従わない
;; 例えば以下を実行しても、0 除算は行われない
(if (oddp 5)
	'odd-number
  (/ 1 0) ;; こっちの分岐は評価されない
)

;; ifの分岐で複数のことを実行したい場合はprognを用いる
(defvar *number-is-odd* nil)
(if (oddp 5)
	(progn
	  (setf *number-is-odd* t)
	  'odd-number)
  'even-number)


;; whenまたはunlessを使うと、prognなしで複数のコマンドを実行できる
;; (これを暗黙のprognという)
(when (oddp 5)
  (setf *number-is-odd* t)
  'odd-number)

(unless (oddp 4)
  (setf *number-is-odd* nil)
  'even-number)


;; condを使うと複数の分岐が書けて、暗黙のprognも使える
(defvar *arch-enemy* nil)
(defun pudding-eater (person)
  (cond ((eq person 'henry)
		 (setf *arch-enemy* 'stupid-lisp-alien)
		 '(curse you lisp alien - you ate my pudding))
		((eq person 'johnny)
		 (setf *arch-enemy* 'useless-old-johnny)
		 '(i hope you choked on my pudding johnny))
		(t
		 '(why you eat my pudding stranger?))
		))

;; caseによる分岐
;; CやJavaのswitchのように比較対象になる値だけを並べればよい
;;
;; caseコマンドは比較にeqを使うことに注意
;; (シンボルの値で分岐するため、文字列の値で分岐することはできない)
(defun pudding-eater (person)
  (case person
	((henry)
	 (setf *arch-enemy* 'stupid-lisp-alien)
	 '(curse you lisp alien - you ate my pudding))
	((johnny)
	 (setf *arch-enemy* 'useless-old-johnny)
	 '(i hope you choked on my pudding johnny))
	(otherwise
	 '(why you eat my pudding stranger?))
	))

;; and/or はその名の通りの論理オペレータ
(and (oddp 3) (oddp 5) (oddp 7)) ;; ==> T
(or  (oddp 2) (oddp 3) (oddp 4)) ;; ==> T





