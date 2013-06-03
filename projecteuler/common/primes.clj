(def fibs (lazy-cat [1 1] (map + fibs (rest fibs))))
