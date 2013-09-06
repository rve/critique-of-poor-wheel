(define (no-num l)
  ((null? l) '())
  (if (number? (car l)) (no-num (cdr l))
      (cons (car l) (no-num (cdr l)))))
